/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */


import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import org.junit.Ignore;
import static org.junit.Assert.*;

import javacriandotestesjunit.Main;

public class JUnitTestPrincipal {

    public JUnitTestPrincipal() {
    }

    @BeforeClass
    public static void setUpClass() throws Exception {
    }

    @AfterClass
    public static void tearDownClass() throws Exception {
    }

    @Before
    public void setUp() {
    }

    @After
    public void tearDown() {
    }

    @Test
    public void testaSoma()
    {
        Main ponteiro = new Main();
        int soma=ponteiro.somar(10, 10);
        assertEquals("Somar Valor " , 20, soma);
    }

    @Test
    public void testaSubtracao()
    {
        Main ponteiro=new Main();
        int subtracao=ponteiro.subtrair(10, 10);
        assertEquals(0, subtracao);
    }

    @Ignore
    @Test
    public void testaDivisao()
    {
        Main ponteiro=new Main();
        int divisao=ponteiro.dividir(10, 10);
        assertEquals(2, divisao);
    }

    @Test
    public void testaMultiplicao()
    {
        Main ponteiro=new Main();
        int multiplicao=ponteiro.multiplicar(10, 10);
        assertEquals(100, multiplicao);
    }


}