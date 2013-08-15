#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <exception>

using namespace std;

class ClientData{

public:
    ClientData(int accountNumber=0, string lastName="", string firstName="", double balance=0.0){
        setLastName(lastName);
        setFirstName(firstName);
        setAccountNumber(accountNumber);
        setBalance(balance);
    }

    void setLastName(string lastName){
        strcpy(this->lastName,lastName.data());
    }

    void setFirstName(string firstName){
        strcpy(this->firstName,firstName.data());
    }

    void setAccountNumber(int accountNumber){
        this->accountNumber=accountNumber;
    }

    void setBalance(double balance) {
        this->balance=balance;
    }

    string getFirstName(){
        return this->firstName;
    }

    string getLastName(){
        return this->lastName;
    }

    int getAccount(){
        return this->accountNumber;
    }
    double getBalance(){
        return this->balance;
    }

    string toString(){
        string mensagem="";
        ostringstream *buffer =  new ostringstream ;
        *buffer << accountNumber;
        mensagem.append("\nFirst Name: ");
        mensagem.append(firstName);
        mensagem.append("\nLast Name: ");
        mensagem.append(lastName);
        mensagem.append("\nAccount Number: ");
        mensagem.append(buffer->str());
        mensagem.append("\nBalance: ");

        delete buffer;

        buffer =  new ostringstream ;
        *buffer << balance;
        mensagem.append(buffer->str());

        delete buffer;

        return mensagem;
    }

private:
    char lastName[20];
    char firstName[20];
    double balance;
    int accountNumber;
    //char mensagem;
};

int main(int argc, char** argv) {

    ClientData client(1,"Prates","Leandro",500.00);
    ClientData client_2;

    fstream escrita("teste.dat" , ios::out | ios::binary );

    escrita.seekp(0);
    escrita.write(reinterpret_cast<const char *>(&client), sizeof(ClientData) );
    client.setFirstName("Ariane");
    client.setAccountNumber(2);
    client.setBalance(700);
    client.setLastName("Louca");

    escrita.seekp(1*sizeof(ClientData));

    escrita.write(reinterpret_cast<const char *>(&client), sizeof(ClientData) );
    client.setFirstName("Vanessa");
    client.setAccountNumber(3);
    client.setBalance(400);
    client.setLastName("Idiota");

    escrita.seekp(2*sizeof(ClientData));
    escrita.write(reinterpret_cast<const char *>(&client), sizeof(ClientData) );
    
    escrita.close();

    cout<<"=================================="<<endl;

    cout << "Tamanho " << sizeof(ClientData) << endl ;
    cout << "Tamanho " << sizeof(client) << endl ;
    cout << "Tamanho " << sizeof(client_2) << endl ;

    sleep(2);
    
        ifstream leitura("teste.dat" , ios::in );

        leitura.read(reinterpret_cast< char * >( &client_2 ), sizeof(ClientData));

        while (!leitura.eof()){

            cout << "\nNome=" << client_2.getFirstName() << endl
                    << "Sobrenome=" << client_2.getLastName() << endl
                    << "Account="   << client_2.getAccount()  << endl
                    << "Balance="   << client_2.getBalance()  << endl;

            leitura.read(reinterpret_cast< char *>( &client_2 ), sizeof(ClientData));
        }
        leitura.close();

    return (EXIT_SUCCESS);
}

