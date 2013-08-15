/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1;

/**
 *
 * @author leandro
 */
class Counter {

	private int count = 0;

	Counter () {

	}

	synchronized void increment() {
		count++;
	}

	int getCount() {
		return count;
	}
}