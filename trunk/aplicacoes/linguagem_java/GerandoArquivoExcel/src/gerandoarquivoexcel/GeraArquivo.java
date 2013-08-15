
package gerandoarquivoexcel;

import java.io.FileOutputStream;
import java.io.IOException;

import org.apache.poi.hssf.usermodel.HSSFWorkbook;

public class GeraArquivo {

      public static void main(String[] args) throws IOException {
            HSSFWorkbook wb = new HSSFWorkbook();
            FileOutputStream stream = new FileOutputStream("/home/lprates/planilha.xls");
            wb.write(stream);
      }
}

