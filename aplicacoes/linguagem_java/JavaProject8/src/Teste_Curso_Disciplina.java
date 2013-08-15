
import org.hibernate.Session;
import org.hibernate.Transaction;


public class Teste_Curso_Disciplina
{
       public static void main(String[] args)
       {
           try
           {
                   Class.forName("com.mysql.jdbc.Driver");
                   Session sessao = HibernateUtility.getSession(); //Abrindo uma sessão
                   Transaction transaction = sessao.beginTransaction(); //Iniciando uma transação
                   Curso curso = new Curso(); //Instanciando um objeto transiente
                   curso.setNome("Desenvolvimento de Software"); //Preenchendo as propriedades do objeto
                   curso.setDescricao("Curso so pra programadores");
                   sessao.save(curso);   //Transformando o objeto transiente em um objeto
                                         //persistente no banco de dados

                   Disciplina disciplina=new Disciplina();
                   disciplina.setId((Integer)1);
                   disciplina.setNome("matematica");
                   disciplina.setEmenta("1");
                   disciplina.setCurso(curso);
                   sessao.save(disciplina);

                   transaction.commit();  //Finalizando a transação
                   sessao.close();        //Fechando a sessão
           }
           catch (Exception ex)
           {
               System.out.println("Erro excecao: " + ex.getMessage() + "\nmensagem:" + ex.toString() );
           }

     }
}
