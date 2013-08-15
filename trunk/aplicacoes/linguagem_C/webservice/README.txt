
Efetuar a busca no google : creating c++ web service from wsdl

Sites uteis para criar o webservice : 

http://users.skynet.be/pascalbotte/rcx-ws-doc/gsoap.htm

http://www.dfki.de/~sberg/smartweb/sysgroup/gSoapDevelopment_new.html


Compilacao baixar gsoap-2.8 descompactar  no diretorio . 

Executar :   ./configure 
             make 
             sudo make install 

Compilar o programa : 

g++ -I /home/lprates/gmude/gsoap-2.8/  -o  teste_cliente  teste_client.c soapC.c soapClient.c    /home/lprates/gmude/gsoap-2.8/gsoap/stdsoap2.c

executar : ./teste_cliente


