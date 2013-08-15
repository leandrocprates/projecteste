public class Endereco {

	private String bairro;

	private String cep;

	private String cidade;

	private String complemento;

	private String estado;

	private Integer id;

	private Integer numero;

	private Pessoa pessoa;

	private String rua;

	/**
	 * @return Returns the bairro.
	 */
	public String getBairro() {
		return bairro;
	}

	/**
	 * @return Returns the cep.
	 */
	public String getCep() {
		return cep;
	}

	/**
	 * @return Returns the cidade.
	 */
	public String getCidade() {
		return cidade;
	}

	/**
	 * @return Returns the complemento.
	 */
	public String getComplemento() {
		return complemento;
	}

	/**
	 * @return Returns the estado.
	 */
	public String getEstado() {
		return estado;
	}

	/**
	 * @return Returns the id.
	 */
	public Integer getId() {
		return id;
	}

	/**
	 * @return Returns the numero.
	 */
	public Integer getNumero() {
		return numero;
	}

	/**
	 * @return Returns the pessoa.
	 */
	public Pessoa getPessoa() {
		return pessoa;
	}

	/**
	 * @return Returns the rua.
	 */
	public String getRua() {
		return rua;
	}

	/**
	 * @param bairro
	 *            The bairro to set.
	 */
	public void setBairro(String bairro) {
		this.bairro = bairro;
	}

	/**
	 * @param cep
	 *            The cep to set.
	 */
	public void setCep(String cep) {
		this.cep = cep;
	}

	/**
	 * @param cidade
	 *            The cidade to set.
	 */
	public void setCidade(String cidade) {
		this.cidade = cidade;
	}

	/**
	 * @param complemento
	 *            The complemento to set.
	 */
	public void setComplemento(String complemento) {
		this.complemento = complemento;
	}

	/**
	 * @param estado
	 *            The estado to set.
	 */
	public void setEstado(String estado) {
		this.estado = estado;
	}

	/**
	 * @param id
	 *            The id to set.
	 */
	public void setId(Integer id) {
		this.id = id;
	}

	/**
	 * @param numero
	 *            The numero to set.
	 */
	public void setNumero(Integer numero) {
		this.numero = numero;
	}

	/**
	 * @param pessoa
	 *            The pessoa to set.
	 */
	public void setPessoa(Pessoa pessoa) {
		this.pessoa = pessoa;
	}

	/**
	 * @param rua
	 *            The rua to set.
	 */
	public void setRua(String rua) {
		this.rua = rua;
	}
}
