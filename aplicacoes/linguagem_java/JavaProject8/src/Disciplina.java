import java.util.Set;

public class Disciplina {
 
	private String nome;
	 
	private String ementa;
	 
	private Set turmas;
	 
	private Curso curso;
	
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
	 * @return Returns the curso.
	 */
	public Curso getCurso() {
		return curso;
	}
	/**
	 * @param curso The curso to set.
	 */
	public void setCurso(Curso curso) {
		this.curso = curso;
	}
	/**
	 * @return Returns the ementa.
	 */
	public String getEmenta() {
		return ementa;
	}
	/**
	 * @param ementa The ementa to set.
	 */
	public void setEmenta(String ementa) {
		this.ementa = ementa;
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
	 * @return Returns the turmas.
	 */
	public Set getTurmas() {
		return turmas;
	}
	/**
	 * @param turmas The turmas to set.
	 */
	public void setTurmas(Set turmas) {
		this.turmas = turmas;
	}
}
 
