#include <iostream>
#include "biblioteca.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Cliente *client = new Cliente();
    bool insert = true;
    //vai assim Nome,data,CPF,Fone
    //salva assim Fone#data#CPF#Nome
    //consultaCliente("jose");
    do{
        string nome, cpf, data, fone;
        int opc;
        
        cout << "Insira os dados do Cliente: "<< endl;                           
        cout << "Nome: ";                                                        
        cin >> nome;
        cout << "CPF: ";                                                         
        cin >> cpf;
        cout << "Telefone: ";                                                    
        cin >> fone;    
        cout << "Data: ";                                                        
        cin >> data;
    
        client->cadastroCliente(nome,data,cpf,fone);
        //client1 = client->loadCliente(); 
        //delete[]client;
        
        cout << "Deseja inserir outro cliente?  1 = SIM  /=/  0 = NÃO" << endl;   
        cin >> opc;
        if(!opc)
            insert = false;
        system("clear");
        //consertar o print
    }while(insert);
   client->printCliente();
  // teste->ler();
    return 0;
}
