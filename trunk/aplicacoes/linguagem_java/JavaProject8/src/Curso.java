import java.util.Set;

public class Curso {
 
	private String descricao;
	 
	private String nome;
	 
	private Set disciplinas;
	 
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
	 * @return Returns the descricao.
	 */
	public String getDescricao() {
		return descricao;
	}
	/**
	 * @param descricao The descricao to set.
	 */
	public void setDescricao(String descricao) {
		this.descricao = descricao;
	}
	/**
	 * @return Returns the disciplinas.
	 */
	public Set getDisciplinas() {
		return disciplinas;
	}
	/**
	 * @param disciplinas The disciplinas to set.
	 */
	public void setDisciplinas(Set disciplinas) {
		this.disciplinas = disciplinas;
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
}
 
