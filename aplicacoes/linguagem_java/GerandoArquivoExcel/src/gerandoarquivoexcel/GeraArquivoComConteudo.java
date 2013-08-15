
package gerandoarquivoexcel;

import java.io.FileOutputStream;
import java.io.IOException;

import org.apache.poi.hssf.usermodel.HSSFRow;
import org.apache.poi.hssf.usermodel.HSSFSheet;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;

public class GeraArquivoComConteudo {

      public static void main(String[] args) throws IOException {
            HSSFWorkbook wb = new HSSFWorkbook();
            HSSFSheet sheet1 = wb.createSheet("Planilha Um");
            HSSFSheet sheet2 = wb.createSheet("Planilha Dois");
            HSSFSheet sheet3 = wb.createSheet("Planilha Três");
            HSSFRow row = sheet1.createRow(0);
            row.createCell((short) 0).setCellValue("Isto é uma String");
            row = sheet1.createRow(20);
            row.createCell((short) 0).setCellValue(20);
            row.createCell((short) 1).setCellValue("Isto é uma String");
            FileOutputStream stream = new FileOutputStream("/home/lprates/planilha_2.xls");
            wb.write(stream);
      }

}

