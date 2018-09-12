#include <iostream>
#include "biblioteca.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Cliente *teste = new Cliente();
    bool insert = true;
    //vai assim Nome,data,CPF,Fone
    //salva assim Fone#data#CPF#Nome
    
    do{
        Cliente *client = new Cliente();
        char nome[100];
        char data[10];
        char cpf[12];
        char fone[20];
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
        delete[]client;
        //insert = false;
        cout << "Deseja inserir outro cliente?  1 = SIM  /=/  0 = NÃO" << endl;
        cin >> opc;
        if(!opc)
            insert = false;
        system("clear");
    }while(insert);
   
   teste->ler();
    return 0;
}
