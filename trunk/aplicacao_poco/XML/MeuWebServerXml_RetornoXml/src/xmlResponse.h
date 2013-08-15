
#include <iostream>
#include <sstream>
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


//resposta: <gkpromo><promo>gkconfig->get_Promo_Nome()</promo><status>ERRO_REQUISICAO</status></gkpromo>

class xmlResponse
{

public :

    xmlResponse(){};
    ~xmlResponse(){};
    
    void xmlWriteResponse(std::ostringstream &resposta)
    {

        try
        {
            AutoPtr<Document> pDoc = new Document;

            AutoPtr<Element> pRoot = pDoc->createElement("gkpromo"); // inicia xml: <gkpromo></gkpromo>

            AutoPtr<Element> pRoot2 = pDoc->createElement("promo");
            AutoPtr<Text> pText1 = pDoc->createTextNode("Kraft");
            pRoot2->appendChild(pText1);
            pRoot->appendChild(pRoot2); // coloca tudo dentro de <gkpromo></gkpromo>

            pRoot2 = pDoc->createElement("status");
            pText1 = pDoc->createTextNode("ERRO_REQUISICAO");
            pRoot2->appendChild(pText1);
            pRoot->appendChild(pRoot2); // coloca tudo dentro de <gkpromo></gkpromo>

            pDoc->appendChild(pRoot); // gera um xml de retorno

            // escreve a saida na tela
            DOMWriter writer;
            writer.setNewLine(XMLWriter::NEWLINE_DEFAULT );

            writer.setOptions(XMLWriter::WRITE_XML_DECLARATION); // formas de saida do xml, ver abaixo

            writer.writeNode(resposta, pDoc);
        }
        catch (Poco::XML::XMLException &e)
        {
            std::cout<< e.displayText()  << std::endl;
        }
        
    }


private:
    
};

