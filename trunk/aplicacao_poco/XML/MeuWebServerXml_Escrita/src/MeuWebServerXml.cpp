
#include <iostream>
#include <string>

#include "Poco/DOM/Document.h"
#include "Poco/DOM/DOMWriter.h"
#include "Poco/XML/XMLWriter.h"
#include "Poco/DOM/Element.h"
#include "Poco/DOM/AutoPtr.h"
#include "Poco/DOM/Text.h"
#include "Poco/DOM/Attr.h"

#include "Poco/XML/XMLException.h"

using Poco::XML::Document;
using Poco::XML::DOMWriter;
using Poco::XML::XMLWriter;
using Poco::XML::Element;
using Poco::XML::AutoPtr;
using Poco::XML::Text;
using Poco::XML::Attr;
using Poco::XML::XMLString;


// exemplo de saida :

// KraftBahiaSalvadorvalor0
// <promocao>
//        <promo_nome>Kraft</promo_nome>
//        <super_grupo>Bahia</super_grupo>
//        <grupo id="1">Salvador</grupo>
//        <serie cupom="100">valor0</serie>
// </promocao>

// <promocao><promo_nome>Kraft</promo_nome><super_grupo>Bahia</super_grupo><grupo id="1">Salvador</grupo><serie cupom="100">valor0</serie></promocao>



int main ()
{
    try
    {
        AutoPtr<Document> pDoc = new Document;

        AutoPtr<Element> pRoot = pDoc->createElement("promocao"); // inicia xml: <promocao></promocao>

        AutoPtr<Element> pRoot2 = pDoc->createElement("promo_nome");
        AutoPtr<Text> pText1 = pDoc->createTextNode("Kraft");
        pRoot2->appendChild(pText1);
        pRoot->appendChild(pRoot2); // coloca tudo dentro de <promocao></promocao>

        pRoot2 = pDoc->createElement("super_grupo");
        pText1 = pDoc->createTextNode("Bahia");
        pRoot2->appendChild(pText1);
        pRoot->appendChild(pRoot2); // coloca tudo dentro de <promocao></promocao>
        
        pRoot2 = pDoc->createElement("grupo");
        pText1 = pDoc->createTextNode("Salvador");
        pRoot2->setAttribute("id" , "1");
        pRoot2->appendChild(pText1);
        pRoot->appendChild(pRoot2); // coloca tudo dentro de <promocao></promocao>


        pRoot2 = pDoc->createElement("serie");
        Attr* pAttr1 = pDoc->createAttribute("cupom");
        pAttr1->setValue("100");
        pText1 = pDoc->createTextNode("valor0");
        pRoot2->setAttributeNode(pAttr1);
        pRoot2->appendChild(pText1);

        pRoot->appendChild(pRoot2); // coloca tudo dentro de <promocao></promocao>

        pDoc->appendChild(pRoot); // gera um xml de retorno

/*******************************************************************************/

        // innerText retorna somante os valores do xml : exemplo:
        // KraftBahiaSalvadorvalor0
        XMLString innerText  = pRoot->innerText();
        std::cout << innerText << std::endl;


        //AutoPtr<Text>    pText  = pDoc->createTextNode("promodentro");
        //pDoc->insertBefore(pText, pRoot2); // insere este texto antes do no pRoot2



/*******************************************************************************/

        // escreve a saida na tela
        DOMWriter writer;
        writer.setNewLine(XMLWriter::NEWLINE_DEFAULT );

        writer.setOptions(XMLWriter::PRETTY_PRINT); // formas de saida do xml, ver abaixo

        // saida utilizando : XMLWriter::WRITE_XML_DECLARATION
        // <?xml version="1.0" encoding="UTF-8"?><promocao/><super_grupo/>

        // saida utilizando : XMLWriter::CANONICAL
        // <promocao/><super_grupo/>

        // saida utilizando : XMLWriter::PRETTY_PRINT
        // <promocao/>
        // <super_grupo/>

        // primeiro parametro onde sera escrita a saida : "cout: saida padrao"
        // segundo pametro xml escrito
        writer.writeNode(std::cout, pDoc);
    }
    catch (Poco::XML::XMLException &e)
    {
        std::cout<< e.displayText()  << std::endl;
    }

    return 0;
}
