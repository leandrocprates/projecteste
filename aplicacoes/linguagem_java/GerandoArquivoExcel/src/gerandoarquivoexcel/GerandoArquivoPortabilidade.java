package gerandoarquivoexcel;

import java.io.IOException;
import java.util.logging.Level;
import org.apache.log4j.PropertyConfigurator;
import org.apache.log4j.Logger;
import java.util.Properties;
import java.io.FileInputStream;

import java.sql.DriverManager;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import java.util.ListIterator;
import java.util.ArrayList;

import java.io.FileOutputStream;
import java.text.SimpleDateFormat;
import java.util.Date;
import org.apache.poi.hssf.usermodel.HSSFRow;
import org.apache.poi.hssf.usermodel.HSSFSheet;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;

public class GerandoArquivoPortabilidade {

    private Properties properties ;
    private Logger log ;
    private String host , usuario , senha  , banco ;
    private String diretorio;
    
    ArrayList<Integer> vetor;
    Connection conexao = null ;

    public GerandoArquivoPortabilidade(){
            
        try {
            properties = new Properties();
            properties.load(new FileInputStream("/home/lprates/tmp/log4j.properties"));
            PropertyConfigurator.configure(properties);
            log  = Logger.getLogger("teste");

        } catch (IOException ex) {
            log.warn("Erro ao Carregar arquivo de Configuracao: "+ex.getMessage());
        }
    }

    public void inicializando () throws IOException
    {
        properties=new Properties();
        properties.load(new FileInputStream("/home/lprates/tmp/configuracao.properties"));
        host = properties.getProperty("host");
        usuario = properties.getProperty("usuario");
        senha = properties.getProperty("senha");
        banco = properties.getProperty("banco");
        diretorio = properties.getProperty("diretorio");

        log.debug("HOST=" +host + " USUARIO="+ usuario + "\nSENHA=" + senha + " BANCO=" + banco + " DIRETORIO="+diretorio );
    }

    public void conectar() throws ClassNotFoundException , SQLException
    {
        try{
            Class.forName("com.mysql.jdbc.Driver");
            conexao = DriverManager.getConnection("jdbc:mysql://"+host+"/"+banco , usuario, senha);
        }catch (SQLException ex){
            log.warn("Erro ao Conectar no Banco de Dados: "+ex.getMessage());
        }
    }

    public void buscarCarrierOperadoras() throws SQLException
    {
        Statement  statement = null ;
        ResultSet resultset = null ;
        vetor = new ArrayList<Integer>();

        try {
            
            statement = conexao.createStatement();
            resultset=statement.executeQuery("select carrier_id from numbering.carrier");
            
            while ( resultset.next()){
                vetor.add(resultset.getInt(1));
                log.debug("Carrier Id = " + resultset.getInt(1) );
            }

        } catch (SQLException ex) {
            log.warn("Erro ao buscar Carrier na Base da Numbering: "+ex.getMessage());
            resultset.close();
            statement.close();
        }
    }

    public String geraData()
    {
        SimpleDateFormat formatador = new SimpleDateFormat("ddMMyyyy");
        Date data = new Date();
        String data_atual = formatador.format(data);
        return data_atual ;
    }

    public void montaArquivoSaida(ResultSet resultado ) throws SQLException  
    {
        String telefone = null ;
        String dominio = null ;

        HSSFWorkbook wb = new HSSFWorkbook();
        HSSFSheet sheet1 = wb.createSheet("Planilha_Um");

        resultado.last();
        int numero = resultado.getRow();
        resultado.beforeFirst();

        log.debug("Numero de Registros Obtidos = "+numero);

        try {

            while (resultado.next() ){

                telefone = resultado.getBigDecimal("Phone_Number").toString();
                dominio  = resultado.getString("Src_Domain");

                HSSFRow row = sheet1.createRow((resultado.getRow()-1));

                row.createCell((short) 0).setCellValue(Double.parseDouble(telefone));
                row.createCell((short) 1).setCellValue(dominio);
                
            }

            if (numero>0){
                FileOutputStream stream = new FileOutputStream(diretorio+"/portabilidade_"+dominio+"_"+geraData()+".xls");
                wb.write(stream);
            }

        } catch ( IOException ex){
            log.warn("Erro Ao Gerar Arquivo Excel : " + ex.getMessage());
        }
    }

    public void obtendoRegistro(){

        Statement  statement = null ;
        ResultSet  resultset = null ;

        ListIterator<Integer> iterator = vetor.listIterator();

        try {

            while ( iterator.hasNext()) {

                int i  = iterator.next();
                log.debug("Carrier NUM = "+i);
                String query =  "SELECT r.Phone_Number AS Phone_Number, ifnull(c.domain_id,'FORA_DO_RANGE') AS Src_Domain FROM portability.register r inner join  portability.register_to_carrier rc on r.SPID = rc.SPID left join numbering.phone_range pr on pr.area_code = substr(r.Phone_Number,1,2) and  substr(r.Phone_Number,3) BETWEEN pr.start_range AND pr.end_range left join  numbering.carrier c on pr.carrier_id = c.carrier_id  WHERE  rc.domain_id is not NULL   AND  Insert_TimeStamp  between date_format(subdate(now(), 1),'%Y%m%d000000')  and  date_format(subdate(now(), 1),'%Y%m%d235959') and c.carrier_id="+i;
                log.debug("Query Executada = "+query);

                statement = conexao.createStatement();
                resultset=statement.executeQuery(query);
                montaArquivoSaida(resultset);
                resultset.close();
                statement.close();
            }

        } catch (SQLException ex) {
            java.util.logging.Logger.getLogger(GerandoArquivoPortabilidade.class.getName()).log(Level.SEVERE, null, ex);
        }

    }

    public static void main (String args[]){

        try {
                GerandoArquivoPortabilidade g = new GerandoArquivoPortabilidade();
                g.inicializando();
                g.conectar();
                g.buscarCarrierOperadoras();
                g.obtendoRegistro();
                
        } catch (Exception ex) {
            java.util.logging.Logger.getLogger(GerandoArquivoPortabilidade.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

}


