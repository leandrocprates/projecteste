/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package com.mycompany.javaapplicaton3;

import com.company.model.Reg0150;
import com.company.model.Reg0200;
import com.company.model.RegC100_C170;
import com.myjeeva.poi.ExcelReader;
import com.myjeeva.poi.ExcelSheetCallback;
import com.myjeeva.poi.ExcelWorkSheetHandler;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.apache.poi.openxml4j.exceptions.InvalidFormatException;
import org.apache.poi.openxml4j.opc.OPCPackage;
import org.apache.poi.util.IOUtils;


/**
 *
 * @author lprates
 * 
 * read large excel in java
 * 
 * http://www.coderanch.com/t/424181/open-source/Read-xls-xlsx-file-format
 * http://svn.apache.org/repos/asf/poi/trunk/src/examples/src/org/apache/poi/xssf/eventusermodel/XLSX2CSV.java
 * http://www.wenda.io/questions/1377351/error-while-reading-large-excel-files-xlsx-via-apache-poi.html
 * 
 * http://www.coderanch.com/t/592519/open-source/apache-POI-excel-reading-examples
 * http://javaprogramming.language-tutorial.com/2012/09/reading-large-excel-files.html
 * 
 * 
 * https://github.com/jeevatkm/excelReader/blob/master/src/test/java/com/myjeeva/poi/ExcelWorkSheetHandlerTest.java
 * https://github.com/jeevatkm/excelReader
 * http://myjeeva.com/read-excel-through-java-using-xssf-and-sax-apache-poi.html
 * 
 * 
 * http://www.aspose.com/blogs/aspose-products/aspose-cells-product-family/archive/2014/01/21/read-large-excel-files-with-lightcells-api-and-find-cells-based-on-formatting-in-aspose.cells-for-java-7.7.1.html
 * 
 */
public class LerArquivo2 {

    private static final Log LOG = LogFactory.getLog(LerArquivo2.class);

  /**
   * @param args
   * @throws Exception
   */
  public static void main(String[] args) throws Exception {
    String SAMPLE_PERSON_DATA_FILE_PATH = "C:/Users/lprates/Documents/arquivo2013.xlsx";

    // Input File initialize
    File file = new File(SAMPLE_PERSON_DATA_FILE_PATH);
    InputStream inputStream = new FileInputStream(file);

    // Excel Cell Mapping
    Map<String, String> cellMapping0150 = new HashMap<String, String>();
    cellMapping0150.put("HEADER", "REG,COD_PART,NOME,COD_PAIS,CNPJ,CPF,IE,COD_MUN,SUFRAMA,END,NUM,COMPL,BAIRRO,BPE_VIGENCIA_FIN");
    cellMapping0150.put("A", "reg");
    cellMapping0150.put("B", "codPart");
    cellMapping0150.put("C", "nome");
    cellMapping0150.put("D", "codPais");
    cellMapping0150.put("E", "cnpj");
    cellMapping0150.put("F", "cpf");
    cellMapping0150.put("G", "ie");
    cellMapping0150.put("H", "codMun");
    cellMapping0150.put("I", "suframa");
    cellMapping0150.put("J", "end");
    cellMapping0150.put("K", "num");
    cellMapping0150.put("L", "compl");
    cellMapping0150.put("M", "bairro");
    cellMapping0150.put("N", "bpeVigenciaFin");
    

    // Excel Cell Mapping
    Map<String, String> cellMapping0200 = new HashMap<String, String>();
    cellMapping0200.put("HEADER", "REG,COD_ITEM,DESCR_ITEM,COD_BARRA,COD_ANT_ITEM,UNID_INV,TIPO_ITEM,COD_NCM,EX_IPI,COD_GEN,COD_LST,ALIQ_ICMS");
    cellMapping0200.put("A", "reg");
    cellMapping0200.put("B", "codItem");
    cellMapping0200.put("C", "descrItem");
    cellMapping0200.put("D", "codBarra");
    cellMapping0200.put("E", "codAntItem");
    cellMapping0200.put("F", "unidInv");
    cellMapping0200.put("G", "tipoItem");
    cellMapping0200.put("H", "codNcm");
    cellMapping0200.put("I", "exIpi");
    cellMapping0200.put("J", "codGen");
    cellMapping0200.put("K", "codLst");
    cellMapping0200.put("L", "aliqIcms");
    

    // Excel Cell Mapping
    Map<String, String> cellMappingC100_C170 = new HashMap<String, String>();
    cellMappingC100_C170.put("A", "campo1");
    cellMappingC100_C170.put("B", "campo2");
    cellMappingC100_C170.put("C", "campo3");
    cellMappingC100_C170.put("D", "campo4");
    cellMappingC100_C170.put("E", "campo5");
    cellMappingC100_C170.put("F", "campo6");
    cellMappingC100_C170.put("G", "campo7");
    cellMappingC100_C170.put("H", "campo8");
    cellMappingC100_C170.put("I", "campo9");
    cellMappingC100_C170.put("J", "campo10");
    cellMappingC100_C170.put("K", "campo11");
    cellMappingC100_C170.put("L", "campo12");
    cellMappingC100_C170.put("M", "campo13");
    cellMappingC100_C170.put("N", "campo14");
    cellMappingC100_C170.put("O", "campo15");
    cellMappingC100_C170.put("P", "campo16");
    cellMappingC100_C170.put("Q", "campo17");
    cellMappingC100_C170.put("R", "campo18");
    cellMappingC100_C170.put("S", "campo19");
    cellMappingC100_C170.put("T", "campo20");
    cellMappingC100_C170.put("U", "campo21");
    cellMappingC100_C170.put("V", "campo22");
    cellMappingC100_C170.put("W", "campo23");
    cellMappingC100_C170.put("X", "campo24");
    cellMappingC100_C170.put("Y", "campo25");
    cellMappingC100_C170.put("Z", "campo26");

    cellMappingC100_C170.put("AA", "campo27");
    cellMappingC100_C170.put("AB", "campo28");
    cellMappingC100_C170.put("AC", "campo29");
    cellMappingC100_C170.put("AD", "campo30");
    cellMappingC100_C170.put("AE", "campo31");
    cellMappingC100_C170.put("AF", "campo32");
    cellMappingC100_C170.put("AG", "campo33");
    cellMappingC100_C170.put("AH", "campo34");
    cellMappingC100_C170.put("AI", "campo35");
    cellMappingC100_C170.put("AJ", "campo36");
    cellMappingC100_C170.put("AK", "campo37");
    cellMappingC100_C170.put("AL", "campo38");
    cellMappingC100_C170.put("AM", "campo39");
    cellMappingC100_C170.put("AN", "campo40");
    cellMappingC100_C170.put("AO", "campo41");
    cellMappingC100_C170.put("AP", "campo42");
    cellMappingC100_C170.put("AQ", "campo43");
    cellMappingC100_C170.put("AR", "campo44");
    cellMappingC100_C170.put("AS", "campo45");
    cellMappingC100_C170.put("AT", "campo46");
    cellMappingC100_C170.put("AU", "campo47");
    cellMappingC100_C170.put("AV", "campo48");
    cellMappingC100_C170.put("AW", "campo49");
    cellMappingC100_C170.put("AX", "campo50");
    cellMappingC100_C170.put("AY", "campo51");
    cellMappingC100_C170.put("AZ", "campo52");

    cellMappingC100_C170.put("BA", "campo53");
    cellMappingC100_C170.put("BB", "campo54");
    cellMappingC100_C170.put("BC", "campo55");
    cellMappingC100_C170.put("BD", "campo56");
    cellMappingC100_C170.put("BE", "campo57");
    cellMappingC100_C170.put("BF", "campo58");
    cellMappingC100_C170.put("BG", "campo59");
    cellMappingC100_C170.put("BH", "campo60");
    cellMappingC100_C170.put("BI", "campo61");
    cellMappingC100_C170.put("BJ", "campo62");
    cellMappingC100_C170.put("BK", "campo63");
    cellMappingC100_C170.put("BL", "campo64");
    cellMappingC100_C170.put("BM", "campo65");
    cellMappingC100_C170.put("BN", "campo66");
    cellMappingC100_C170.put("BO", "campo67");
    cellMappingC100_C170.put("BP", "campo68");
    cellMappingC100_C170.put("BQ", "campo69");
    cellMappingC100_C170.put("BR", "campo70");
    cellMappingC100_C170.put("BS", "campo71");
    
    
    // The package open is instantaneous, as it should be.
    OPCPackage pkg = null;
    try {

      ExcelWorkSheetHandler<Reg0150> workSheetHandler =
          new ExcelWorkSheetHandler<Reg0150>(Reg0150.class, cellMapping0150);

      pkg = OPCPackage.open(inputStream);

      ExcelSheetCallback sheetCallback = new ExcelSheetCallback() {
        private int sheetNumber = 0;
                
        public void startSheet(int sheetNum, String sheetName) {
          this.sheetNumber = sheetNum;
          System.out.println("Started processing sheet number=" + sheetNumber
              + " and Sheet Name is '" + sheetName + "'");
        }

        @Override
        public void endSheet() {
          System.out.println("Processing completed for sheet number=" + sheetNumber);
        }

        public void startSheet(int sheetNum) {
          System.out.println("Started processing sheet number=" + sheetNum);
        }
          
      };

      
      /*** Leitura Registro 0150 ***/
      
      System.out.println("Constructor: pkg, workSheetHandler, sheetCallback");
      ExcelReader example1 = new ExcelReader(pkg, workSheetHandler, sheetCallback);
      example1.process("0150");

      if (workSheetHandler.getValueList().isEmpty()) {
        // No data present
        LOG.error("sHandler.getValueList() is empty");
      } else {

        LOG.info(workSheetHandler.getValueList().size()
            + " no. of records read from given excel worksheet successfully.");

        // Displaying data ead from Excel file
        displayPersonList(workSheetHandler.getValueList());
      }

    
      /*** Leitura Registro 0200 ***/
      
      ExcelWorkSheetHandler<Reg0200> workSheetHandler0200 =
          new ExcelWorkSheetHandler<Reg0200>(Reg0200.class, cellMapping0200);
      
      ExcelReader example2 = new ExcelReader(pkg, workSheetHandler0200, null);
      example2.process("0200");

      if (workSheetHandler0200.getValueList().isEmpty()) {
        
        LOG.error("sHandler.getValueList() is empty");
      } else {

        LOG.info(workSheetHandler0200.getValueList().size()
            + " no. of records read from given excel worksheet successfully.");

        displayPersonList0200(workSheetHandler0200.getValueList());
      }
      
      
      /*** Leitura Registro C100 e C170 ***/
      
      ExcelWorkSheetHandler<RegC100_C170> workSheetHandlerC100_C170 =
          new ExcelWorkSheetHandler<RegC100_C170>(RegC100_C170.class, cellMappingC100_C170, 4 );
      workSheetHandlerC100_C170.setVerifiyHeader(false);
      
      ExcelReader example3 = new ExcelReader(pkg, workSheetHandlerC100_C170, null);
      example3.process("201302");

      if (workSheetHandlerC100_C170.getValueList().isEmpty()) {
        
        LOG.error("sHandler.getValueList() is empty");
      } else {

        LOG.info(workSheetHandlerC100_C170.getValueList().size()
            + " no. of records read from given excel worksheet successfully.");

        displayPersonListC100_C170(workSheetHandlerC100_C170.getValueList());
      }

      
    
    } catch (RuntimeException are) {
      LOG.error(are.getMessage(), are.getCause());
    } catch (InvalidFormatException ife) {
      LOG.error(ife.getMessage(), ife.getCause());
    } catch (IOException ioe) {
      LOG.error(ioe.getMessage(), ioe.getCause());
    } finally {
      IOUtils.closeQuietly(inputStream);
      try {
        if (null != pkg) {
          pkg.close();
        }
      } catch (IOException e) {
        // just ignore IO exception
      }
    }
  }

  private static void displayPersonList(List<Reg0150> reg0150) {
    System.out.println("Id\tCodPart\tNome\tCodigo do Pais\t\tCNPJ\t\tCPF");
    System.out.println("--\t----\t------\t-------------\t\t---\t\t------");
    for (Reg0150 p : reg0150) {
      System.out.println(String.format("%s\t%s\t%s\t%s\t%s\t%s", p.getReg(), p.getCodPart(),
          p.getNome(), p.getCodPais(), p.getCnpj(), p.getCpf()));
    }
  }
  
  private static void displayPersonList0200(List<Reg0200> reg0200) {
    System.out.println("Id\tCodItem\tDesc Item\tCodigo de Barra\t\tCod Ant Item\t\tUnid Inv");
    System.out.println("--\t----\t------\t-------------\t\t---\t\t------");
    for (Reg0200 p : reg0200) {
      System.out.println(String.format("%s\t%s\t%s\t%s\t%s\t%s", p.getReg(), p.getCodItem(),
          p.getDescrItem(), p.getCodBarra(), p.getCodAntItem(), p.getUnidInv()));
    }
  }

  private static void displayPersonListC100_C170(List<RegC100_C170> regC100_C170) {
    System.out.println("Campo1\tCampo2\tCampo3\tCampo4\t\tCampo5\t\tCampo6");
    System.out.println("--\t----\t------\t-------------\t\t---\t\t------");
    for (RegC100_C170 p : regC100_C170) {
      System.out.println(String.format("%s\t%s\t%s\t%s\t%s\t%s", p.getCampo1(), p.getCampo2(),
          p.getCampo3(), p.getCampo4(), p.getCampo5(), p.getCampo6() ));
    }
  }
  
  
}
