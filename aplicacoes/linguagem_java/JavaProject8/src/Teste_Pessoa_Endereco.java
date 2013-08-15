import org.hibernate.Session;
import org.hibernate.Transaction;

public class Teste_Pessoa_Endereco
{
       public static void main(String[] args)
       {
           try
           {
                   Class.forName("com.mysql.jdbc.Driver");
                   Session sessao = HibernateUtility.getSession(); //Abrindo uma sessão
                   Transaction transaction = sessao.beginTransaction(); //Iniciando uma transação

                   Pessoa pessoa = new Pessoa();
                   pessoa.setNome("Leandro Cesar Prates");
                   pessoa.setEmail("leandro.prates@gmail.com");
                   pessoa.setTelefone("75016032");

                   Endereco endereco=new Endereco();
                   endereco.setRua("Av Joao Pessoa 408");
                   endereco.setBairro("Lauzane Paulista");
                   endereco.setCep("02440050");
                   endereco.setCidade("Sao Paulo");
                   endereco.setComplemento("nenhum");
                   endereco.setEstado("SP");

                   //pessoa.setEndereco(endereco);
                   endereco.setPessoa(pessoa);

                   sessao.save(pessoa);
                   sessao.save(endereco);

                   transaction.commit();  //Finalizando a transação
                   sessao.close();        //Fechando a sessão
           }
           catch (Exception ex)
           {
               System.out.println("Erro excecao: " + ex.getMessage() + "\nmensagem:" + ex.toString() );
           }

     }
}
