import java.util.Set;

public class Turma {
 
	private String nome;
	 
	private Set alunos;
	 
	private Disciplina disciplina;
	 
	private Professor professor;

	private Integer id;
	
	
	
	/**
	 * @return Returns the id.
	 */
	public Integer getId() {
		return id;
	}
	/**
	 * @param id The id to set.
	 */
	public void setId(Integer id) {
		this.id = id;
	}	
	
	/**
	 * @return Returns the alunos.
	 */
	public Set getAlunos() {
		return alunos;
	}
	/**
	 * @param alunos The alunos to set.
	 */
	public void setAlunos(Set alunos) {
		this.alunos = alunos;
	}
	/**
	 * @return Returns the disciplina.
	 */
	public Disciplina getDisciplina() {
		return disciplina;
	}
	/**
	 * @param disciplina The disciplina to set.
	 */
	public void setDisciplina(Disciplina disciplina) {
		this.disciplina = disciplina;
	}
	/**
	 * @return Returns the nome.
	 */
	public String getNome() {
		return nome;
	}
	/**
	 * @param nome The nome to set.
	 */
	public void setNome(String nome) {
		this.nome = nome;
	}
	/**
	 * @return Returns the professor.
	 */
	public Professor getProfessor() {
		return professor;
	}
	/**
	 * @param professor The professor to set.
	 */
	public void setProfessor(Professor professor) {
		this.professor = professor;
	}
}
 
