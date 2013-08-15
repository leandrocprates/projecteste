package gerandoarquivoexcel;

import java.io.FileOutputStream;
import java.io.IOException;

import org.apache.poi.hssf.usermodel.HSSFSheet;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;

public class GeraArquivoComPlanilha {

      public static void main(String[] args) throws IOException {
            HSSFWorkbook wb = new HSSFWorkbook();
            HSSFSheet sheet1 = wb.createSheet("Planilha Um");
            HSSFSheet sheet2 = wb.createSheet("Planilha Dois");
            HSSFSheet sheet3 = wb.createSheet("Planilha Três");
            FileOutputStream stream = new FileOutputStream("/home/lprates/planilha_1.xls");
            wb.write(stream);
      }

}


