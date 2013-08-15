/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package br.com.okto.send;

import br.com.okto.basicmodel.exception.BDException;
import br.com.okto.basicmodel.service.bean.ConnectionPropBeanC3PO;
import br.com.okto.corporate.bd.TargetBD;
import br.com.okto.corporate.bean.Batch;
import br.com.okto.corporate.bean.Client;
import br.com.okto.corporate.bean.Component;
import br.com.okto.corporate.bean.GKResponseEnum;
import br.com.okto.corporate.bean.LayoutItem;
import br.com.okto.corporate.bean.Message;
import br.com.okto.corporate.bean.Target;
import br.com.okto.corporate.bean.TargetStatusEnum;
import br.com.okto.corporate.bean.User;
import br.com.okto.corporate.bean.UserLimitTypeEnum;
import br.com.okto.corporate.util.HTTPClient;
import java.io.UnsupportedEncodingException;
import java.net.URLEncoder;
import java.util.Calendar;
import java.util.List;
import java.util.Map;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import org.apache.commons.httpclient.URIException;
import org.apache.commons.httpclient.methods.GetMethod;
import org.apache.commons.lang.StringUtils;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

import org.quartz.Job;
import org.quartz.JobDataMap;
import org.quartz.JobExecutionContext;
import org.quartz.JobExecutionException;
import org.quartz.Scheduler;
import org.quartz.SchedulerException;

/**
 *
 * @author lprates
 */
public class SendMessage implements Job {

    private static final Log log = LogFactory.getLog( SendMessage.class );
    private static ConnectionPropBeanC3PO cpb = DB.getAppDB();
    private Target target = null;
    private Client client = null;
    private User user = null;
    private Batch batch = null;
    private Component component = null; 
    private List<LayoutItem> variables = null;
    private Message message = null; 
    private ShareUser shareUser = null;
    private String threadName ; 
    private String appid;
    private Scheduler sched;
    private SentComponentMessage setComponentMessage = null;
    private Object monitorTime = null;
    
    private ExecutorService pool = Executors.newSingleThreadExecutor();
    
    public SendMessage() {
    }

    public void execute(JobExecutionContext context) throws JobExecutionException {
        
        boolean envia_middle=false;
        int qtdPercentualEnvio=0; 
        
        JobDataMap dataMap = context.getJobDetail().getJobDataMap();
        Map< String, Object > mapParamJob = dataMap.getWrappedMap();
        
        client = (Client) mapParamJob.get("client");
        user = (User) mapParamJob.get("user");
        batch = (Batch) mapParamJob.get("batch");
        component = (Component) mapParamJob.get("component");
        variables = (List<LayoutItem>) mapParamJob.get("variables");
        shareUser = (ShareUser) mapParamJob.get("shareUser");
        threadName = (String) mapParamJob.get("threadName");
        appid = (String) mapParamJob.get("appid"); 
        sched= (Scheduler) mapParamJob.get("sched");
        setComponentMessage= (SentComponentMessage) mapParamJob.get("setComponentMessage");
        envia_middle=dataMap.getBoolean("envia_middle");
        qtdPercentualEnvio=dataMap.getInt("qtdPercentualEnvio");
        monitorTime = (Object) mapParamJob.get("monitorTime");

        JobDataMap triggerDataMap = context.getTrigger().getJobDataMap();
        target = (Target) triggerDataMap.get("target");
        message = (Message) triggerDataMap.get("message" );
        
        long messageSobra = 0;
        long messageUsada = 0;
        long qtdStatusMessage=0;

        
        try {

            CheckLimits checkLimits = new CheckLimits ( batch, component, client, user , shareUser, threadName, false );
            checkLimits.verifyLimits();
            
            if ( !checkLimits.checkBatchStatus( false ) ) {
                throw new IllegalStateException();
            }
            
            if ( user != null ) {

                //valida somente usuarios com limitacao de envio limit_qtd
                if ( user.getLimitType() != UserLimitTypeEnum.LIMIT_PERIOD ){

                    messageSobra=shareUser.decrementMessagesRemaining();
                    messageUsada=shareUser.incrementMessagesUsed();

                    if ( messageSobra < 0 ){
                        user.setLimitPassed(true);
                        user.setLocked(true);
                        log.warn("Acabaram os creditos de envio QTD");
                        throw new IllegalStateException();
                    }
                    
                }
                
            }
            
            //envia notificacao a cada percentual enviado
            if ( batch.getSendMiddle() != 0 ) {

                if ( envia_middle ){
                    qtdStatusMessage=setComponentMessage.incrementMessagesSent();
                    
                    if ( qtdStatusMessage == qtdPercentualEnvio ){
                        pool.execute(new SendSms( client , batch , component ));
                        qtdStatusMessage=0;
                    }
                }
            }
            
            sendMessage( variables, target );
            
            //adiciona retentativa 3 vezes 
            if (target.getStatus() == TargetStatusEnum.GATEWAY_ERROR && target.getRetryCount() < 20 ){
                throw new JobExecutionException();
            }
            
        } catch ( BDException ex ) {
            log.error(String.format("Error : [%s]" , ex) );
            
        } catch(IllegalStateException IEx){
            try {
                
                synchronized(monitorTime){
                    monitorTime.notify();
                }
                sched.pauseAll();
                sched.clear();
            } catch (SchedulerException ex) {
                
            }
        
        } catch (JobExecutionException ex){
            
            try {
                Thread.sleep(Config.getSleepError());
                ex.setRefireImmediately(true);
                throw ex;
            } catch (InterruptedException ex1) {
                
            }
            
        } catch (Exception ex){

        } finally {
            pool.shutdown();
        }
        
    }
    
    
    private void sendMessage( List<LayoutItem> variables, Target target ) throws BDException {
            String messageText = StringUtils.EMPTY;
            try {
                    messageText = message.getFinalText( target.getCarrierId(), variables, target );
                    if ( messageText != null ) {
                            sendMessageToGK( target, messageText );
                    }
            } catch ( Exception e ) {
                    target.setStatus( TargetStatusEnum.INTERNAL_ERROR );
                    log.error( String.format( "[%s] <%s> Error in target [%d] Message [%s] ", client.getName(), threadName,
                                    target.getId() , e ) );
            }
            target.setText( messageText );
            TargetBD.getInstance().update( target, client.getDbName(), cpb );
    }
    

    private void sendMessageToGK( Target target, String messageText ) throws UnsupportedEncodingException, URIException {

            String gkRet = "ERROR";
            Long wSerial = 0L;

            GetMethod method = new GetMethod( Config.getGatewayURL() );

            method.setQueryString( String.format( "user=%s&pwd=%s&appid=%s&phone=%d&appmsgid=%s&msgtext=%s",
                            Config.getGatewayUser(), Config.getGatewayPwd(), appid,
                            Long.parseLong( StringUtils.replaceChars( target.getMsgPhone() , "()- " , "" ) ), target.getId(), URLEncoder.encode( messageText, "UTF-8" ) ) );

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
                            log.error( String.format( "[%s] <%s> Error sending message to GK - Message [%s]", client.getName(),
                                            threadName, e ) );
                    } finally {
                            method.releaseConnection();
                    }
            }

            setTargetStatus( target, gkRet, wSerial );
    }

    private void setTargetStatus( Target target, String gkRet, Long wSerial ) {
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
    }

}
