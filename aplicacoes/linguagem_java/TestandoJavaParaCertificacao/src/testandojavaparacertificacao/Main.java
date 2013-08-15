package testandojavaparacertificacao;

interface teste_interface{
    String endereco="Joao Pessoa";
}

interface teste_interface_2 extends teste_interface{
    String endereco_2="Joao Pessoa2";
}

class TesteConcreta{
    private String nome  ;

    public String getNome(){
        return nome;
    }

    public void setNome(String nome){
        this.nome=nome;
    }
}

abstract class TesteAbstrata extends TesteConcreta{

    public abstract int getTelefone();
    public abstract void setTelefone(int telefone);
    
}

class TesteAbstract2 extends TesteAbstrata{

    private int telefone ;
    
    @Override
    public int getTelefone() {
        return telefone;
    }

    @Override
    public void setTelefone(int telefone) {
        this.telefone=telefone;
    }

}


public class Main {


    public static void TesteSwitch(){
        
        int x =1 ;

        switch(x){
            case 0:
                System.out.println("Zero");break;
            case 1:
                System.out.println("Um");
            case 2:
                System.out.println("Dois");
            case 3:
                System.out.println("Tres");
        }
        
    }


    public static void main(String[] args) {
        TesteAbstract2 teste  = new TesteAbstract2();
        teste.setNome("leandro");
        teste.setTelefone(75016032);
        System.out.println("Nome:"+teste.getNome() +" Telefone:"+teste.getTelefone());
        System.out.println("Endereco :"+teste_interface.endereco);
        System.out.println("Endereco2 :"+teste_interface_2.endereco);
        System.out.println("Endereco2 :"+teste_interface_2.endereco_2);

        Main.TesteSwitch();
    }
}
