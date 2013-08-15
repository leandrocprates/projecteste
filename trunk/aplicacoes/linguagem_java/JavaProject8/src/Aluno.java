import java.util.Set;

public class Aluno extends Pessoa {
 
	private String matricula;
	 
	private Set turmas;
	 
	/**
	 * @return Returns the matricula.
	 */
	public String getMatricula() {
		return matricula;
	}
	/**
	 * @param matricula The matricula to set.
	 */
	public void setMatricula(String matricula) {
		this.matricula = matricula;
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
	
	public String toString() {
		return this.getNome() + " " + this.getMatricula() + " "+ this.getEndereco();
	}
	
}
 
