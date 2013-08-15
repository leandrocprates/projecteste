import java.util.List;
import org.hibernate.Query;
import org.hibernate.Session;
import org.hibernate.Transaction;


public class Teste2 {
       public static void main(String[] args) {
               Session sessao = HibernateUtility.getSession(); 
               Transaction transaction = sessao.beginTransaction(); 
               Curso curso = new Curso();
               curso.setNome("Desenvolvimento de Software"); 
               curso.setDescricao("Curso só pra programadores");

               Disciplina disciplina = new Disciplina ();
               disciplina.setNome("Sistemas Operacionais");
               disciplina.setEmenta("Curso de Sistemas Operacionais");
               disciplina.setCurso(curso);

               sessao.save(curso);
               sessao.save(disciplina);

               Query query = sessao.createQuery("from Disciplina");
               List lista = query.list();

               for (int i=0 ; i<lista.size() ; i++)
               {
                   Disciplina disciplina2 = (Disciplina)lista.get(i);
                   System.out.println("Obtido o valor : "+disciplina2.getId());
               }
               
               transaction.commit();
               sessao.close();
       }
}
