
package testando_threads;

import java.util.concurrent.Executors;
import java.util.concurrent.ExecutorService;
import java.util.logging.Level;
import java.util.logging.Logger;

class Main extends Thread
{
    private int variavel_compartilhada=0;

    @Override
    public void run(){
        int i = 0 ;

        while (i<500){
            synchronized (this){
                variavel_compartilhada++;
                System.out.println("Variavel numero: "+variavel_compartilhada+" Thread Name: "+Thread.currentThread().getName());
            }
            i++;
        }
    }
}

public class Testando_ExecucaoParalela {

    public static void main(String[] args) {

        Main teste = new Main ();
        Thread thread_1 = new Thread(teste);
        Thread thread_2 = new Thread(teste);
        Thread thread_3 = new Thread(teste);
        Thread thread_4 = new Thread(teste);
        thread_1.start();
        thread_2.start();
        thread_3.start();
        thread_4.start();

        try {
            thread_1.join();
            thread_2.join();
            thread_3.join();
            thread_4.join();
        } catch (InterruptedException ex) {
            Logger.getLogger(Testando_ExecucaoParalela.class.getName()).log(Level.SEVERE, null, ex);
        }


        System.out.println("Thread Name: "+Thread.currentThread().getName());
    }
}