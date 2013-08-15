package utilizandoarray;

import java.util.Arrays;

public class Main
{
    public static void main(String[] args)
    {
        int array[]={12,34,2,76,5,97,67};
        int array2[]={12,34,2,76,5,97,67};

        Arrays.sort(array);
        Arrays.sort(array2);
        boolean igual= Arrays.equals(array, array2);

        if(igual)
        {
            System.out.println("Os dois vetores sao iguais.");
        }
        else
        {
            System.out.println("Os dois vetores sao diferentes.");
        }

        for (int z : array)
        {
            System.out.print(z+",");
        }

        int result = Arrays.binarySearch(array,67);
        if (result==-1)
        {
            System.out.println("Nao encontrou nenhum resultado.");
        }
        else
        {
            System.out.println("Encontrado indice: " +result );
        }

        int array3[]=new int[10];
        Arrays.fill(array3,0,2,2);
        Arrays.fill(array3,2,10,1);

        for (int t:array3)
        {
            System.out.print(t+",");
        }
        
        String array_completo=Arrays.toString(array3);
        System.out.print("\nArray Completo:"+array_completo+"\n");

        String array_string[]=new String[3];
        array_string[0]="Oi 0";
        array_string[1]="Oi 1";
        array_string[2]="Oi 2";
        for (String palavra : array_string)
        {
            System.out.print(palavra+",");
        }
        
    }
}
