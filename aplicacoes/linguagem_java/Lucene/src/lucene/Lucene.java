/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package lucene;

import java.io.IOException;
import org.apache.lucene.analysis.standard.StandardAnalyzer;
import org.apache.lucene.document.Document;
import org.apache.lucene.document.Field;
import org.apache.lucene.index.IndexWriter;
import org.apache.lucene.queryParser.ParseException;
import org.apache.lucene.queryParser.QueryParser;
import org.apache.lucene.search.IndexSearcher;
import org.apache.lucene.search.Query;
import org.apache.lucene.search.ScoreDoc;
import org.apache.lucene.search.TopScoreDocCollector;
import org.apache.lucene.store.Directory;
import org.apache.lucene.store.RAMDirectory;
import org.apache.lucene.util.Version;

/**
 *
 * @author lprates
 */
public class Lucene {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException, ParseException {
        
        // Cria o analyzador  
        StandardAnalyzer analyzer = new StandardAnalyzer(Version.LUCENE_36);  

        // Diretório virtual para o índice  
        Directory indexDirectory = new RAMDirectory();  

        // Cria o arquivo com tamanho ilimitado.  
        IndexWriter w = new IndexWriter(indexDirectory, analyzer, true,  
            IndexWriter.MaxFieldLength.UNLIMITED);  

        // Adiciona 4 documentos.  
        addDoc(w, "Lucene in Action");   
        addDoc(w, "Lucene for Dummies");  
        addDoc(w, "Managing Gigabytes");  
        addDoc(w, "The Art of Computer Science");  

        // Fecha o arquivo.  
        w.close();          

        // Faz o parse da consulta e cria uma query do lucene.  
        Query q = new QueryParser(Version.LUCENE_36,"title", analyzer).parse("lcene");  

        int maxHits = 10;  

        // Cria o acesso ao índice  
        IndexSearcher searcher = new IndexSearcher(indexDirectory);  

        // Prepara a coleção de resultado  
        //TopDocCollector collector = new TopDocCollector(maxHits);  
        
        TopScoreDocCollector collector = TopScoreDocCollector.create(maxHits, true);

        // Faz a pesquisa  
        searcher.search(q, collector);  

        // Separa os 10 itens mais relevantes para a consulta.  
        ScoreDoc[] hits = collector.topDocs().scoreDocs;  

        // Imprime os documentos retornados.  
        System.out.println("Found " + hits.length + " hits.");  
        for (int i = 0; i < hits.length; ++i) {  
            int docId = hits[i].doc;  
            Document d = searcher.doc(docId);  
            System.out.println((i + 1) + ". " + d.get("title"));  
        }  

        searcher.close();
        
    }
    
    
    private static void addDoc(IndexWriter w, String text) throws IOException {  
        Document doc = new Document();  
        doc.add(new Field("title", text, Field.Store.YES, Field.Index.ANALYZED));  
        w.addDocument(doc);  
    }  


}
