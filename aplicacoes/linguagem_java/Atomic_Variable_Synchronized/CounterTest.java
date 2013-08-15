/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1;

import java.util.concurrent.atomic.AtomicInteger;

/**
 *
 * @author leandro
 */

/****  Teste usando synchronized ***/


public class CounterTest {

	public static void main(String[] args) {

                long startTime = System.nanoTime();
            
		Counter counter = new Counter();

		for(int i=0; i< 160000; i++) {
			//This loop to get rid of any hotspot optimizations
			counter.increment();
		}

		for(int i=0; i< 150000; i++) {
			counter.increment();
		}

		long endTime = System.nanoTime();
		double processingTime = (endTime - startTime)/Math.pow(10, 6);

		System.out.println("Processing Time (msec): " + processingTime + " Count: " + counter.getCount());

	}

}


/****  Teste usando variavel atomica ***/


/*
public class CounterTest {

	public static void main(String[] args) {
            
                long startTime = System.nanoTime();
            
		AtomicInteger counter = new AtomicInteger(0);

		for(int i=0; i< 160000; i++) {
			//This loop to get rid of any hotspot optimizations
			counter.incrementAndGet();
		}

		for(int i=0; i< 150000; i++) {
			counter.incrementAndGet();
		}

		long endTime = System.nanoTime();
		double processingTime = (endTime - startTime)/Math.pow(10, 6);

		System.out.println("Processing Time (msec): " + processingTime + " Count: " + counter.intValue());

	}

}
*/

/*
public class CounterTest {

	public static void main(String[] args) {
            
                long startTime = System.nanoTime();
            
		AtomicInteger counter = new AtomicInteger(0);

		for(int i=0; i<1000; i++) {
			Runnable runnable = new WorkerThread(counter);
			Thread t = new Thread(runnable);
			t.start();
		}

                long endTime = System.nanoTime();
		double processingTime = (endTime - startTime)/Math.pow(10, 6);

                System.out.println("Processing Time (msec): " + processingTime );
                
	}

}

class WorkerThread implements Runnable {

	AtomicInteger count = null;

	WorkerThread(AtomicInteger counter) {
		this.count = counter;
	}

	public void run() {
		int value = this.count.incrementAndGet();
		System.out.println(value);
	}
}
*/
