package javaapplication1;

public class Main {

    enum Status
    {
        OK(1,2),
        NOK(3,4);

        Status(int x,int y)
        {
            valor_1=x;
            valor_2=y;
        }

        int getValor_1()
        {
                return valor_1 ;
        }

        int getValor_2()
        {
                return valor_2 ;
        }
        
        int valor_1;
        int valor_2;
    };
    
    public static void main(String[] args) {

        Status status=Status.OK;

        switch (status)
        {
            case OK:
                System.out.println("Status OK"); break;
            case NOK:
                System.out.println("Status NOK"); break;
        }

        System.out.println("Valores Enum:");
        
        for ( Status e :  Status.values() )
        {
            System.out.println(e);
            System.out.printf("%d , %d\n" , e.valor_1,e.valor_2);
            System.out.printf("%d , %d\n" , e.getValor_1(),e.getValor_2());
        }
        
        System.out.println(Status.valueOf("OK"));
     
    }
}
