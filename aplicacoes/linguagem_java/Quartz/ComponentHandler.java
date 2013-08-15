package br.com.okto.send;

import org.quartz.SchedulerException;
import java.util.ArrayList;
import org.quartz.JobBuilder;
import br.com.okto.corporate.bean.BatchFile;
import java.util.Properties;
import org.quartz.impl.StdSchedulerFactory;
import org.quartz.SchedulerFactory;
import org.quartz.JobKey;
import org.quartz.JobDataMap;
import java.util.Map;
import org.quartz.Trigger;

import java.util.Calendar;
import java.util.List;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import br.com.okto.basicmodel.exception.BDException;
import br.com.okto.basicmodel.service.bean.ConnectionPropBeanC3PO;
import br.com.okto.corporate.bd.AppBD;
import br.com.okto.corporate.bd.BatchBD;
import br.com.okto.corporate.bd.BatchFileBD;
import br.com.okto.corporate.bd.ComponentBD;
import br.com.okto.corporate.bd.FileLayoutBD;
import br.com.okto.corporate.bd.LayoutItensBD;
import br.com.okto.corporate.bd.TargetBD;
import br.com.okto.corporate.bean.Batch;
import br.com.okto.corporate.bean.BatchStatusEnum;
import br.com.okto.corporate.bean.Client;
import br.com.okto.corporate.bean.Component;
import br.com.okto.corporate.bean.ComponentStatusEnum;
import br.com.okto.corporate.bean.FileLayout;
import br.com.okto.corporate.bean.LayoutItem;
import br.com.okto.corporate.bean.LayoutItemEnum;
import br.com.okto.corporate.bean.Message;
import br.com.okto.corporate.bean.Target;
import br.com.okto.corporate.bean.User;
import java.util.HashMap;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import org.quartz.JobDetail;
import org.quartz.Scheduler;

import static org.quartz.JobBuilder.newJob;
import static org.quartz.TriggerBuilder.newTrigger;

public class ComponentHandler implements Runnable {

	private static final Log log = LogFactory.getLog( ComponentHandler.class );

	private static final Object monitor = new Object();
        private Object monitorTime = new Object();
	private final String threadName;
	private final Component component;
	private final Client client;
	private final ConnectionPropBeanC3PO cpb;
	
	public String appid;
        private User user = null;
        private ShareUser shareUser = null;
        
        private ExecutorService pool = Executors.newSingleThreadExecutor();
        
        private Map< String, Object > mapParamJob = null;
        private Map< Integer, Message > mapListMessage = null;
        private Calendar agendamento = Calendar.getInstance();
        private JobKey key;

        private SchedulerFactory sf;
        private Scheduler sched;
        
	public ComponentHandler( Component component, Client client, String appid, ShareUser shareUser ) {
		this.threadName = String.format( "b%dc%d", component.getBatchId(), component.getId() );
		this.component = component;
		this.client = client;
		this.cpb = DB.getAppDB();
		this.appid = appid;
                this.user = (shareUser == null)?null:shareUser.getUser(); 
                this.shareUser = shareUser; 
                load();
	}
        
        public void load(){
            
            try{
                
                Properties properties = new Properties();
                properties.setProperty("org.quartz.scheduler.instanceName", component.getId()+"_"+client.getId() );
                properties.setProperty("org.quartz.scheduler.instanceId", "AUTO" );
                properties.setProperty("org.quartz.threadPool.class", "org.quartz.simpl.SimpleThreadPool" );
                properties.setProperty("org.quartz.threadPool.threadCount", client.getApp().getTps().toString() );
                properties.setProperty("org.quartz.threadPool.threadPriority", "5" );
                properties.setProperty("org.quartz.jobStore.misfireThreshold", "60000" );
                properties.setProperty("org.quartz.jobStore.class", "org.quartz.simpl.RAMJobStore" );
                
                sf = new StdSchedulerFactory(properties);
                sched = sf.getScheduler();
                sched.start();
                
            }catch(Exception ex ) {
                log.error(String.format("Error Starting ComponentHandler : [%s]" , ex ));
            }
            
        }
        

	public void run() {
            
		try {
			execute();
		} catch ( Exception e ) {
			log.error( String.format( "[%s] <%s> Error handling component - Message [%s]", client.getName(), threadName, e ));
		} finally {

                        try {
                            
                            if(!sched.isShutdown()){
                                sched.shutdown(true);
                            }
                            
                        } catch (Exception ex){
                            log.error(String.format( "Error Shutdown on Scheduler - Message: [%s]", ex ));
                        }
                        ComponentScanner.componentFinished( this );
                        pool.shutdown();
		}
	}

	private void execute() throws Exception {
		log.info( String.format( "[%s] <%s> Starting thread batch [%d] component [%d]", client.getName(),
				threadName, component.getBatchId(), component.getId() ) );

                Batch batch = getBatch();

                CheckLimits checkLimits = new CheckLimits ( batch , component , client , user , shareUser,  threadName , true );
                
		synchronized ( monitor ) {
			if ( !checkLimits.checkBatchStatus( false ) ) {
				return;
			}
			updateComponent( ComponentStatusEnum.PROCESSING );
		}
		
                List<BatchFile> batch_file = BatchFileBD.getInstance().getByBatchId( batch.getId(), client.getDbName(), true, cpb );
		
                mapListMessage = new HashMap< Integer, Message >();
                
                for (BatchFile bf : batch_file) {
                    
                    if ( bf.getMessage() != null ){
                        mapListMessage.put( bf.getMessage().getId() , bf.getMessage() );
                    }
                    
                }
                
                if (mapListMessage.isEmpty()){
                    log.error(String.format("<%s> Falha ao obter mensagem para o Cliente[%s], AppId[%d] , AppName[%s] ", threadName, client.getName() , client.getApp().getId() , client.getApp().getName() ));
                    throw new IllegalStateException();
                }
                
		client.setApp( AppBD.getInstance().getById( batch.getAppId(), cpb ) );

                checkLimits.verifyLimits(); //verifica limits para ver se comeca o envio
                
		updateBatchStatus( batch, BatchStatusEnum.PROCESSING );

		List<LayoutItem> variables = loadLayoutItems( batch );

		int messagesToSend = messagesToSendCount();
		int blockSize = Config.getBlockSize();
                int recarregar = Config.getBlockSize();
                int blockSizeTarget = Config.getBlockSizeTarget();
                int id_proximo = 0;
                long realInterval;          
                long millisRemaining;

                int qtdPercentualEnvio = ( int ) Math.ceil( (double) ( component.getQuantity() * Config.getPercentSentNotifier() ) / 100 ); 
                int qtdSentNotifier = Config.getQtdSentNotifier();
                boolean envia_middle = false;
                
                if ( component.getQuantity() >= qtdSentNotifier ){
                    envia_middle = true ; 
                }
                
                SentComponentMessage setComponentMessage = new SentComponentMessage();
                
                mapParamJob = new HashMap< String, Object >();
                key = new JobKey(component.getId()+client.getName(), "EnvioSMS");

                JobDataMap jmp = new JobDataMap();
                mapParamJob.put("client", client );
                mapParamJob.put("user", user );
                mapParamJob.put("batch", batch );
                mapParamJob.put("component", component );
                mapParamJob.put("variables", variables );
                mapParamJob.put("shareUser", shareUser );
                mapParamJob.put("threadName", threadName );
                mapParamJob.put("appid", appid );
                mapParamJob.put("sched", sched );
                mapParamJob.put("setComponentMessage", setComponentMessage );
                mapParamJob.put("envia_middle", envia_middle );
                mapParamJob.put("qtdPercentualEnvio", qtdPercentualEnvio );
                mapParamJob.put("monitorTime", monitorTime );

                jmp.putAll(mapParamJob);

                //criar o job de envio de mensagem
                JobBuilder jobBuilder = newJob();
                jobBuilder.ofType(SendMessage.class);
                jobBuilder.withIdentity(key);
                jobBuilder.usingJobData(jmp);
                jobBuilder.storeDurably(true);
                JobDetail job = jobBuilder.build();
                
                sched.addJob(job, true);

                List<Target> targetsToSend = new ArrayList<Target>() ;
                List<Target> targetsToSendListCompleta = new ArrayList<Target>() ;
                
                while ( messagesToSend > 0 ) {
                    
                    //conta quantos registros por segundo
                    millisRemaining = component.getEndTime().getTimeInMillis() - System.currentTimeMillis() - 40000;
                    realInterval = millisRemaining / messagesToSend;
                    
                    Calendar compare = Calendar.getInstance();
                    int count=0;
                    
                    if (targetsToSend.size() < recarregar ){
                        targetsToSendListCompleta = TargetBD.getInstance().getToSend( component, blockSizeTarget , id_proximo ,
                                        client.getDbName(), cpb );
                        targetsToSend.addAll(targetsToSendListCompleta);
                    }
                    
                    for (count=0; count<blockSize && count<recarregar && count<targetsToSend.size() ; count++) {
                    
                        JobDataMap jmp2 = new JobDataMap();
                        
                        jmp2.put("target", targetsToSend.get(count));
                        jmp2.put("message", mapListMessage.get( targetsToSend.get(count).getMsgid() ) );
                        
                        agendamento.setTimeInMillis( ( System.currentTimeMillis() ) + ( realInterval * (count+1) ) );
                        
                        try {
                            
                            Trigger trigger = newTrigger()
                                .withIdentity( targetsToSend.get(count).getId().toString() , "EnvioSMS" )
                                .startAt(agendamento.getTime())
                                .endAt(component.getEndTime().getTime())
                                .forJob(job)
                                .usingJobData(jmp2)
                                .build();

                            if(!sched.isShutdown()){
                                sched.scheduleJob(trigger);
                            }
                            
                        } catch (IllegalArgumentException ex){
                            log.error( String.format("Error creating Trigger : [%s]" , ex ) );
                            checkLimits.verifyLimits();
                        } catch (SchedulerException ex){
                            checkLimits.verifyLimits();
                        }
                        
                    }
                    
                    id_proximo=targetsToSend.get(targetsToSend.size()-1).getId();
                    
                    for (int r=0; r<count ; r++){
                        targetsToSend.remove(0);
                    }
                    
                    try{
                        synchronized(monitorTime){
                            monitorTime.wait(agendamento.getTimeInMillis() - compare.getTimeInMillis(), 1);
                        }
                    } catch(IllegalArgumentException Iex){
                        
                    }
                    
                    int i=0;
                    List<Trigger> listaTrigger = (List<Trigger>) sched.getTriggersOfJob(key);
                    i=listaTrigger.size();
                    
                    while (i>( (blockSize * Config.getMinPercentBlock())/100 )){
                        Thread.sleep(100);
                        listaTrigger=(List<Trigger>) sched.getTriggersOfJob(key);
                        i=listaTrigger.size();
                    }
                    
                    messagesToSend=messagesToSend-count;
                    
                    recarregar=blockSize-i;
                    
                    checkLimits.verifyLimits();
                    
                    if ( !checkLimits.checkBatchStatus( false ) ) {
                        throw new IllegalStateException();
                    }
                    
                }
                
                int i=0;
                List<Trigger> listaTrigger = (List<Trigger>) sched.getTriggersOfJob(key);
                i=listaTrigger.size();

                while (i>0){
                    Thread.sleep(1000);
                    listaTrigger=(List<Trigger>) sched.getTriggersOfJob(key);
                    i=listaTrigger.size();
                    checkLimits.verifyLimits();
                }
                
		finishComponent();
		if ( checkLimits.checkBatchStatus( true ) ) {
			updateBatch( batch );
			log.info( String.format( "[%s] <%s> Finalizing thread...", client.getName(), threadName ) );
		}
                
                //enviar sms ou email depois que finalizou o envio para o component
                if ( batch.getSendEnd() != 0 ){
                    pool.execute(new SendSms( client , batch , component ));
                }
                
	}

	private Integer messagesToSendCount() throws BDException {
		return TargetBD.getInstance().countToSendComponent( component, client.getDbName(), cpb );
	}
        
	private List<LayoutItem> loadLayoutItems( Batch batch ) throws BDException {
		FileLayout fileLayout = FileLayoutBD.getInstance().getByAppId( batch.getAppId(), cpb );
		List<LayoutItem> variables = LayoutItensBD.getInstance().getItens( fileLayout.getColumnOrderLoad(),
				cpb );
		addSpecialLayoutItens( variables );
		return variables;
	}

	private void addSpecialLayoutItens( List<LayoutItem> variables ) {
		LayoutItem prinome = new LayoutItem();
		prinome.setColumnName( LayoutItemEnum.PRE_NAME );
		prinome.setItemKey( "PRINOME" );
		variables.add( prinome );

		LayoutItem primnome = new LayoutItem();
		primnome.setColumnName( LayoutItemEnum.PRE_NAME );
		primnome.setItemKey( "PRIMNOME" );
		variables.add( primnome );
	}
        
	private Batch getBatch() throws BDException {
		return BatchBD.getInstance().getById( component.getBatchId(), client.getDbName(), cpb );
	}

	private void updateComponent( ComponentStatusEnum status ) throws BDException {
		if ( status != null ) {
			component.setStatus( status );
		}
		ComponentBD.getInstance().update( component, client.getDbName(), cpb );
	}

	private void finishComponent() throws BDException {
		updateComponent( ComponentStatusEnum.CONCLUDED );
	}

	private void updateBatch( Batch batch ) throws BDException {
		BatchStatusEnum status = BatchStatusEnum.FINISHED;
		if ( ComponentBD.getInstance().countProcessing( batch.getId().toString(),
				component.getId().toString(), client.getDbName(), cpb ) == 0 ) {
			if ( ComponentBD.getInstance().countScheduled( batch.getId().toString(),
					component.getId().toString(), client.getDbName(), cpb ) > 0 ) {
				status = BatchStatusEnum.READY;
			} else if ( TargetBD.getInstance().countNotSentByBatch( batch.getId(), client.getDbName(), cpb ) > 0 ) {
				status = BatchStatusEnum.PENDING;
			}
			updateBatchStatus( batch, status );
		}
	}

	private void updateBatchStatus( Batch batch, BatchStatusEnum status ) throws BDException {
		batch.setStatus( status );
		BatchBD.getInstance().updateStatus( batch, client.getDbName(), cpb );
	}
        
        
        
	/*private void sendMessageBlock( Batch batch, List<LayoutItem> variables, int minutesRemaining,
			List<Target> targets, long realInterval ) throws Exception {
		long messageInterval;
		long messageStartTime;
		long messageSpentTime;
		long blockStartTime = System.currentTimeMillis();
		long blockEndTime = blockStartTime + ( minutesRemaining <= 1 ? 40 : 60 ) * 1000;

		addRetryMessages( minutesRemaining, targets );

		for ( int i = 0 ; i < targets.size() ; i++ ) {
			messageStartTime = System.currentTimeMillis();
			Target target = targets.get( i );

			updateMessage( target );
                       
                        //checa se usuario for com limite de envio
                        if ( user != null ){
                            checkUserLimits();
                        }
                        
                        sendMessage( variables, target );

                        if ( user != null ) {

                            //valida somente usuarios com limitacao de envio limit_qtd
                            if ( user.getLimitType() != UserLimitTypeEnum.LIMIT_PERIOD ){

                                if ( target.getStatus() == TargetStatusEnum.PRE_SENT ){
                                    messageSobra=shareUser.decrementMessagesRemaining();
                                    messageUsada=shareUser.incrementMessagesUsed();
                                }

                                if (messageSobra <= 0){
                                    user.setLimitPassed(true);
                                    user.setLocked(true);
                                    log.debug("Acabaram os creditos de envio QTD");
                                }
                            }
                        }
                        
			checkDayTimeLimit( batch );
			checkAppTimeLimit( batch );
			checkComponentTimeLimit( batch );

                        //só cliente conta trial
                        if ( client.isBlockable() ){
                            //checkClientMessagesLimit();
                        }

                        //envia notificacao a cada percentual enviado
                        if ( batch.getSendMiddle() != 0 ) {
                            
                            qtdStatusMessage++;
                            
                            if ( envia_middle ){
                                if ( qtdStatusMessage >= qtdPercentualEnvio && qtdStatusMessage <= qtdPercentualMaxEnvio ){
                                    pool.execute(new SendSms( client , batch , component ));
                                    qtdStatusMessage=0;
                                }
                            }
                        }
                        
			messageInterval = ( ( blockEndTime - messageStartTime ) / ( targets.size() - i ) );
			messageSpentTime = System.currentTimeMillis() - messageStartTime;

			if ( messageSpentTime < messageInterval ) {
				Thread.sleep( messageInterval - messageSpentTime );
			}

			if ( log.isDebugEnabled() ) {
				long sendTime = System.currentTimeMillis() - messageStartTime;
				log.debug( String.format( "[%s] <%s> [%d] Send time [%d] Expecting [%d] GK [%d]",
						client.getName(), threadName, target.getRetryCount(), sendTime, messageInterval,
						messageSpentTime ) );
			}
		}
		long blockElapsedTime = System.currentTimeMillis() - blockStartTime;
		log.info( String.format( "[%s] <%s> Elapsed time to send block [%.3f] seconds", client.getName(),
				threadName, blockElapsedTime / 1000d ) );

		if ( realInterval > 60000 && minutesRemaining > 1 ) {
			log.debug( String.format( "[%s] <%s> Extra sleeping for [%.3f] seconds", client.getName(),
					threadName, ( realInterval - blockElapsedTime ) / 1000d ) );
			Thread.sleep( realInterval - blockElapsedTime );
		}
	}

	private void checkAppTimeLimit( Batch batch ) throws BDException {
		if (! client.getApp().isIntervalAllowed(component.getStartTime(), component.getEndTime())) {
			updateBatchStatus( batch, BatchStatusEnum.HALTED );
			updateComponent( ComponentStatusEnum.HALTED );
                        
                        if ( batch.getSendEnd() != 0 ){
                            pool.execute(new SendSms( client , batch , component ));
                        }
                        
			throw new IllegalStateException( String.format(
					"[%s] <%s> Batch halted due to App time restrictions", 
					client.getName(),
					threadName));
		}
	}

	private void addRetryMessages( int minutesRemaining, List<Target> targets ) throws BDException {
		if ( minutesRemaining > 1 || targets.size() <= 30 ) {
			List<Target> toRetry = TargetBD.getInstance().getToRetry( component,
					(int)( targets.size() * 0.4 ), client.getDbName(), cpb );

			if ( !toRetry.isEmpty() ) {
				log.info( String.format( "[%s] <%s> Adding [%s] retry messages to block", client.getName(),
						threadName, toRetry.size() ) );
				targets.addAll( toRetry );
			}
		}
	}*/


	/*private void sendMessage( List<LayoutItem> variables, Target target ) throws BDException {
		String messageText = StringUtils.EMPTY;
		try {
			messageText = message.getFinalText( target.getCarrierId(), variables, target );
			if ( messageText != null ) {
				sendMessageToGK( target, messageText );
			}
		} catch ( Exception e ) {
			target.setStatus( TargetStatusEnum.INTERNAL_ERROR );
			log.error( String.format( "[%s] <%s> Error in target %d", client.getName(), threadName,
					target.getId() ), e );
		}
		target.setText( messageText );
		TargetBD.getInstance().update( target, client.getDbName(), cpb );
	}

	private void updateMessage( Target target ) throws BDException {
		if ( message == null || !message.getId().equals( target.getMsgid() ) ) {
			message = MessageBD.getInstance().getById( target.getMsgid(), client.getDbName(), cpb );
		}
	}

	private void checkDayTimeLimit( Batch batch ) throws BDException {
		if ( Calendar.getInstance().get( Calendar.HOUR_OF_DAY ) >= Config.getEndTimeLimit() ) {
			if ( ComponentBD.getInstance().countProcessing( batch.getId().toString(),
					component.getId().toString(), client.getDbName(), cpb ) == 0 ) {
				batch.setStatus( BatchStatusEnum.HALTED );
				BatchBD.getInstance().updateStatus( batch, client.getDbName(), cpb );
			}
			updateComponent( ComponentStatusEnum.HALTED );
                        
                        if ( batch.getSendEnd() != 0 ){
                            pool.execute(new SendSms( client , batch , component ));
                        }

                        throw new IllegalStateException( String.format(
					"[%s] <%s> Batch halted - Reached daytime limit for send [%d:00]", client.getName(),
					threadName, Config.getEndTimeLimit() ) );
		}
	}*/


        /*private void checkUserLimits() throws BDException {

                if ( user.isLockable() && user.isLocked() && user.isLimitPassed() && (user.getLimitType() == UserLimitTypeEnum.LIMIT_PERIOD) ){
                    log.warn( String.format( "[%s] <%s> User [%d] Expired per Time", client.getName(), threadName , user.getId() ) );
                    if(user.isSendEmail()){
                        sendUserExpiredMail(user.getEmail());
                        sendUserExpiredMail(Config.getMailTo());
                    }
                    blockUser();
                } else if ( user.isLockable() && user.isLocked() && user.isLimitPassed() && ( (user.getLimitType() == UserLimitTypeEnum.LIMIT_QTD) || (user.getLimitType() == UserLimitTypeEnum.LIMIT_QTD_PERIOD) ) ){
                    log.warn( String.format( "[%s] <%s> User [%d] messages limit exceeded", client.getName(), threadName , user.getId() ) );
                    if(user.isSendEmail()){
                        sendUserLimitExceededMail(user.getEmail());
                        sendUserLimitExceededMail(Config.getMailTo());
                    }
                    blockUser();
                }
        }
        
	private void blockUser() throws BDException {
		
                Batch batch = getBatch() ;
                batch.setStatus(BatchStatusEnum.STOPPED);
                BatchBD.getInstance().updateStatus( batch, client.getDbName(), cpb );
		throw new IllegalStateException( String.format(
				"[%s] <%s> Component blocked.", client.getName(), threadName ) );
	}*/


	/*private void checkComponentTimeLimit( Batch batch ) throws ResourceNotFoundException,
			ParseErrorException, Exception {
            
                int count = 0 ; 
		if ( Calendar.getInstance().after( component.getEndTime() ) ) {
                    
                        count = messagesToSendCount();        
                        
                        if ( count > 0 ) {
                            
                            updateBatchStatus( batch, BatchStatusEnum.HALTED );
                            updateComponent( ComponentStatusEnum.HALTED );
                            sendBatchLimitExceededMail( count );

                            if ( batch.getSendEnd() != 0 ){
                                pool.execute(new SendSms( client , batch , component ));
                            }

                            throw new IllegalStateException( String.format(
                                            "[%s] <%s> Component halted - Reached end time [%s]. [%d] messages remaining.",
                                            client.getName(), threadName, FormatX.formatDateTime( component.getEndTime() ),
                                            count ) );
                        }
		}
	}*/

	/*private void sendMessageToGK( Target target, String messageText ) throws UnsupportedEncodingException, URIException {

		String gkRet = "ERROR";
		Long wSerial = 0L;

		GetMethod method = new GetMethod( Config.getGatewayURL() );

		method.setQueryString( String.format( "user=%s&pwd=%s&appid=%s&phone=%s&appmsgid=%s&msgtext=%s",
				Config.getGatewayUser(), Config.getGatewayPwd(), appid,
				target.getMsgPhone(), target.getId(), URLEncoder.encode( messageText, "UTF-8" ) ) );

                log.debug(String.format(" Thread [%s] , Requisicao Enviada : [%s] , Retry : [%d] " , threadName, method.getQueryString() , target.getRetryCount() ));

		if ( HTTPClient.getInstance().executeNotReleasing( method ) ) {
			try {

                                log.debug(String.format( " Thread [%s] , Resposta GW [%s]", threadName, method.getResponseBodyAsString() )) ;

                                String line = method.getResponseBodyAsString();
				if ( log.isTraceEnabled() ) {
					log.trace( String.format( "[%s] <%s> GW return %s", client.getName(), threadName, line ) );
				}

				String[] ret = StringUtils.split( line, '|' );
				gkRet = ret[ 0 ].toUpperCase();
				if ( ret.length == 2 ) {
					wSerial = Long.valueOf( ret[ 1 ] );
				}

				target.setSendTime( Calendar.getInstance() );
				target.setGkResponse( gkRet );
			} catch ( Exception e ) {
				log.error( String.format( "[%s] <%s> Error sending message to GK", client.getName(),
						threadName ), e );
			} finally {
				method.releaseConnection();
			}
		}

		setTargetStatus( target, gkRet, wSerial );
	}*/

	/*private void setTargetStatus( Target target, String gkRet, Long wSerial ) {
		try {
			GKResponseEnum response = GKResponseEnum.valueOf( gkRet );
			if ( TargetStatusEnum.GATEWAY_ERROR.equals( target.getStatus() ) ) {
				target.setRetryCount( target.getRetryCount() + 1 );
			}
			switch ( response ) {
				case OK:
					target.setStatus( TargetStatusEnum.PRE_SENT );
					target.setWserial( wSerial );
					break;
				case ERROR:
				case INTERNAL_ERROR:
					target.setStatus( TargetStatusEnum.GATEWAY_ERROR );
					break;
				case INVALID_PHONE:
					target.setStatus( TargetStatusEnum.INVALID_PHONE );
					break;
				case BLOCKED:
				case BLACKLISTED:
					target.setStatus( TargetStatusEnum.BLACKLISTED );
					break;
				case UNKNOW_PHONE:
				case NOACCESS:
				case MISSING_PARAMETERS:
				case HTTP_NOT_FOUND:
				case INVALID_URL:
				default:
					target.setStatus( TargetStatusEnum.INTERNAL_ERROR );
					log.error( String.format( "[%s] <%s> Unexpected GW return %s for target %d",
							client.getName(), threadName, gkRet, target.getId() ) );
					break;
			}
		} catch ( IllegalArgumentException iae ) {
			log.error( String.format( "[%s] <%s> Unknown GW return %s for target %d", client.getName(),
					threadName, gkRet, target.getId() ) );
			target.setStatus( TargetStatusEnum.GATEWAY_ERROR );
		}
	}*/

	/*private Integer getClientSentCount() throws BDException {
		return TargetBD.getInstance().countSentAndPreSent( client.getDbName(), cpb );
	}

	private void sendBatchLimitExceededMail( int messagesToSend ) {
		try {
			VelocityContext context = new VelocityContext();
			context.put( "componentId", component.getId() );
			context.put( "endTime", FormatX.formatDateTime( component.getEndTime() ) );
			context.put( "remainingMessages", messagesToSend );
			context.put( "clientName", client.getDescription() );
			context.put( "appName", client.getApp().getName() );
			context.put( "appId", client.getApp().getId() );

			VelocityUtil.sendMail( Config.getMailBatchExceedTimeTemplate(), context,
					Config.getMailSmtpHost(), Config.getMailFrom(), Config.getMailTo(),
					Config.getMailBatchExceedTimeSubject() );
		} catch ( Exception e ) {
			log.warn( String.format( "[%s] <%s> Error sending mail", client.getName(), threadName ), e );
		}
	}

	private void sendUserLimitExceededMail(String email) {
		try {
			VelocityContext context = new VelocityContext();
			context.put( "componentId", component.getId() );
			context.put( "messagesToSent", component.getQuantity() );
			context.put( "limit", (user.getMessagesLimit()+user.getMessagesExcess()) );
			context.put( "sentMessages", messageUsada );
			context.put( "clientName", client.getDescription() );
			context.put( "appName", client.getApp().getName() );
			context.put( "appId", client.getApp().getId() );
                        context.put( "userId", user.getId() );

			VelocityUtil.sendMail( Config.getMailUserLimitExceededTemplate(), context, Config.getMailSmtpHost(),
					Config.getMailFrom(), email,
					Config.getMailUserLimitExceededSubject() );
		} catch ( Exception e ) {
			log.warn( String.format( "[%s] <%s> Error sending mail", client.getName(), threadName ), e );
		}
	}
        
        
	private void sendUserExpiredMail(String email) {
		try {
			VelocityContext context = new VelocityContext();
			context.put( "componentId", component.getId() );
			context.put( "expireTime", FormatX.formatDateTime( user.getExpireTime() ) );
			context.put( "limit", (user.getMessagesLimit()+user.getMessagesExcess()) );
			context.put( "clientName", client.getDescription() );
			context.put( "appName", client.getApp().getName() );
			context.put( "appId", client.getApp().getId() );
                        context.put( "userId", user.getId() );

			VelocityUtil.sendMail( Config.getMailUserExpiredTemplate(), context, Config.getMailSmtpHost(),
					Config.getMailFrom(), email,
					Config.getMailUserExpiredSubject() );
		} catch ( Exception e ) {
			log.warn( String.format( "[%s] <%s> Error sending mail", client.getName(), threadName ), e );
		}
	}*/
        
	Integer getClientId() {
		return client.getId();
	}

	Integer getComponentId() {
		return component.getId();
	}
        
        User getUser() {
            return user;
        }

        ShareUser getShareUser() {
            return shareUser;
        }
        
}