/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package manipulandoarquivos;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;

/**
 *
 * @author leandro
 */
public class UtilizandoClasseFile {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

        File file=new File("/home/leandro");

        if ( file.exists() ) {
            if ( file.isDirectory() ) {
                System.out.println("Nome do Diretorio : " + file.getName());
                System.out.println("Nome do Diretorio : " + file.getPath());
                System.out.println("Nome do Diretorio : " + file.getAbsolutePath());
            }
            else if (file.isFile()){
                System.out.println("Nome do Arquivo : " + file.getName());
                System.out.println("Nome do Arquivo : " + file.getPath());
            }
        }
        
        File arquivos[]=file.listFiles();
        for ( int i=0 ; i< arquivos.length ; i++){
           System.out.println(arquivos[i]);
        }

        System.out.println("Buscando o Diretorio:");
        for (File arquivo : file.listFiles()) {
            if (arquivo.getName().equals("netbeans-6.8") ){
                System.out.println(arquivo.toString());
            }
        }
    }

}
