/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package com.mycompany.javaapplicaton3;

import java.util.Iterator;
import org.apache.poi.openxml4j.opc.OPCPackage;
import org.apache.poi.ss.usermodel.Cell;
import org.apache.poi.ss.usermodel.Row;
import org.apache.poi.xssf.usermodel.XSSFSheet;
import org.apache.poi.xssf.usermodel.XSSFWorkbook;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 *
 * @author lprates
 */
public class LerArquivo {
    
    private static final Logger logger = LoggerFactory.getLogger(LerArquivo.class);
    
    public static void main(String args[]){

        logger.info("Hello World!");
        
        try{
            
            //File excel =  new File ("C:/Users/lprates/Documents/arquivo2013.xlsx");
            //FileInputStream fis = new FileInputStream(excel);
            
            OPCPackage pkg = OPCPackage.open("C:/Users/lprates/Documents/arquivo2013.xlsx");
            XSSFWorkbook myWorkBook  = new XSSFWorkbook(pkg); 
            
            // Return first sheet from the XLSX workbook
            XSSFSheet mySheet = myWorkBook.getSheetAt(0);
           
            // Get iterator to all the rows in current sheet
            Iterator<Row> rowIterator = mySheet.iterator();
           
            // Traversing over each row of XLSX file
            while (rowIterator.hasNext()) {
                Row row = rowIterator.next();

                // For each row, iterate through each columns
                Iterator<Cell> cellIterator = row.cellIterator();
                while (cellIterator.hasNext()) {

                    Cell cell = cellIterator.next();

                    switch (cell.getCellType()) {
                        case Cell.CELL_TYPE_STRING:
                            System.out.print(cell.getStringCellValue() + "\t");
                            break;
                        case Cell.CELL_TYPE_NUMERIC:
                            System.out.print(cell.getNumericCellValue() + "\t");
                            break;
                        case Cell.CELL_TYPE_BOOLEAN:
                            System.out.print(cell.getBooleanCellValue() + "\t");
                            break;
                        default :
                            System.out.print("Nada");
                    }
                }
                System.out.println("");
            }            
            
        }catch (Exception ex){
            logger.error(ex.toString());
        }
        
        
    }
    
    
}
