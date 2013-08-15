import java.util.Set;

public class Professor extends Pessoa {
 
	private String titulo;
	 
	private Set turmas;
	
	/**
	 * @return Returns the titulo.
	 */
	public String getTitulo() {
		return titulo;
	}
	/**
	 * @param titulo The titulo to set.
	 */
	public void setTitulo(String titulo) {
		this.titulo = titulo;
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
 
