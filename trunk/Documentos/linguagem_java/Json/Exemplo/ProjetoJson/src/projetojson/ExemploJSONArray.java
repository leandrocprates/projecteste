/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package projetojson;

/**
 *
 * @author leandro
 */
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

public class ExemploJSONArray {

	 public static void main(String[] args) {

			try {
				JSONArray array = new JSONArray();

				/*
				 * Criação do Objeto JSONObject
				 */
				Pessoa pOne = new Pessoa();

				pOne.setNome("Fernanda");
				pOne.setTelefone("987456321");

				JSONObject jsonOne = new JSONObject();

				jsonOne.put("nome", pOne.getNome());
				jsonOne.put("telefone", pOne.getTelefone());

				Pessoa pTwo = new Pessoa();

				pTwo.setNome("Caio");
				pTwo.setTelefone("123456789");

				JSONObject jsonTwo = new JSONObject();

				jsonTwo.put("nome", pTwo.getNome());
				jsonTwo.put("telefone", pTwo.getTelefone());

				array.put(jsonOne);
				array.put(jsonTwo);

				System.out.println("JSONArray: "+ array);

			} catch (JSONException e) {
				e.printStackTrace();
			}
		}
}
