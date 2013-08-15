package utilizandolistas;

import java.util.List;
import java.util.ListIterator;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Collection;

public class Main {

    private static void removeLista(Collection<String> colecao1)
    {
        System.out.println("=====Removendo da Lista=====");

        imprimir(colecao1);

        Iterator<String> iterator1=colecao1.iterator();
        while(iterator1.hasNext())
        {
            if (iterator1.next().equals("oi"))
                iterator1.remove();
        }

        System.out.println("=====Apos a Remocao=====");
        
        imprimir(colecao1);

    }

    private static void imprimir(Collection<String> colecao1)
    {
        Iterator<String> iterator1=colecao1.iterator();
        while(iterator1.hasNext())
        {
            System.out.println(iterator1.next());
        }
        
    }

    private static void converteMinusculo(List<String> colecao1){
        
        System.out.println("=====converteMinusculo=====");
        ListIterator<String> iterator=colecao1.listIterator();
        while (iterator.hasNext())
        {
            iterator.set(iterator.next().toLowerCase());
            System.out.println("Indice: " +iterator.nextIndex() );
        }
        
    }

    public static void main(String[] args) {
        
        ArrayList<String> lista=new ArrayList<String>(2);
        String teste="oi";

        lista.add(teste);
        lista.add("TUDO");
        lista.add("bem");
        lista.add("quarto");
        lista.add("oi");

        System.out.println("Retorno Get :" + lista.get(0));

        imprimir(lista);

        // verifica se contem a palavara oi na lista
        if (lista.contains("oi"))
        {
            System.out.println("Contem:oi");
        }

        // retorna o indice de TUDO na lista criada
        System.out.println("INDICE: " +lista.indexOf("TUDO"));

        imprimir(lista);
        
        removeLista(lista);

        converteMinusculo(lista);
        
        imprimir(lista);

    }
}
