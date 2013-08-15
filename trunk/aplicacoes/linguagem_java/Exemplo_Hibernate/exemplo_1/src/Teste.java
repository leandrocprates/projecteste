
import org.hibernate.Session;
import org.hibernate.Transaction;


public class Teste {
       public static void main(String[] args) {
               Session sessao = HibernateUtility.getSession(); //Abrindo uma sessão
               Transaction transaction = sessao.beginTransaction(); //Iniciando uma transação
               Curso curso = new Curso(); //Instanciando um objeto transiente
               curso.setNome("Desenvolvimento de Software"); //Preenchendo as propriedades do objeto
               curso.setDescricao("Curso só pra programadores");
               sessao.save(curso);   //Transformando o objeto transiente em um objeto
                                     //persistente no banco de dados
               transaction.commit();  //Finalizando a transação
               sessao.close();        //Fechando a sessão
       }
}
