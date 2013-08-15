/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package projetojson;

/**
 *
 * @author leandro
 */
import org.json.JSONException;
import org.json.JSONObject;

public class ExemploJSONObject {

	public static void main(String[] args) {

		try {
			Pessoa pessoa = new Pessoa();

			pessoa.setNome("Fernanda");
			pessoa.setTelefone("123456789");

			JSONObject jsonObj = new JSONObject();

			jsonObj.put("nome", pessoa.getNome());
			jsonObj.put("telefone", pessoa.getTelefone());

			System.out.println(jsonObj);

		} catch (JSONException e) {
			e.printStackTrace();
		}
	}
}