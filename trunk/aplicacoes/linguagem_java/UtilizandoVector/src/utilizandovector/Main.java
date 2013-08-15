package utilizandovector;

import java.util.Vector;
import java.util.ListIterator;
import java.util.Collections;


public class Main {

    public static void main(String[] args) {

        Vector<String> vetor = new Vector<String>();

        vetor.add("Leandro");
        vetor.add("Ariane");
        vetor.add("Vanessa");

        if (!vetor.isEmpty())
        {
            if (vetor.contains("Vanessa"))
            {
                System.out.println("Vetor contain Vanessa no indice: " + vetor.indexOf("Vanessa") );
            }
        }

        ListIterator<String> list = vetor.listIterator();

        while (list.hasNext())
        {
            System.out.println("Nome : " + list.next());
        }

        Collections.sort(vetor);
        list = vetor.listIterator();

        while (list.hasNext())
        {
            System.out.println("Nome : " + list.next());
        }
    }
}
