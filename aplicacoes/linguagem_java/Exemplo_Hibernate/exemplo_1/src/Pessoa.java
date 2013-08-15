public class Pessoa {
 
	private String nome;
	 
	private String email;
	 
	private String telefone;
	 
	private Endereco endereco;

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
	 * @return Returns the email.
	 */
	public String getEmail() {
		return email;
	}
	/**
	 * @param email The email to set.
	 */
	public void setEmail(String email) {
		this.email = email;
	}
	/**
	 * @return Returns the endereço.
	 */
	public Endereco getEndereco() {
		return endereco;
	}
	/**
	 * @param endereço The endereço to set.
	 */
	public void setEndereco(Endereco endereço) {
		this.endereco = endereço;
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
	 * @return Returns the telefone.
	 */
	public String getTelefone() {
		return telefone;
	}
	/**
	 * @param telefone The telefone to set.
	 */
	public void setTelefone(String telefone) {
		this.telefone = telefone;
	}
}
 
