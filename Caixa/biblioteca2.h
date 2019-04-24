#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <set>
#include <vector>

//OLHA2 : https://www.inf.pucrs.br/~pinho/PRGSWB/STL/stl.html

using namespace std;



class Cliente
{
public:
    //sets
    void setClienteNome(string);
    void setClienteSaldo(double);
    void setClienteDataEntrada(string);
    void setClienteCpf(string);
    void setClienteFone(string);
    //gets
    int getClienteId();
    string getClienteName();
    double getClienteSaldo();
    string getClienteDataEntrada();
    string getClienteCpf();
    string getClienteFone();
    //métodos
    void cadastroCliente(string, string, string, string); 
    vector<Cliente> *loadCliente(void);
    void printAllCliente(void);
    void consultaCliente(void);
    void frontClienteAdd(void);
private:
    string nome;
    string date;
    int id;
    string cpf;
    double saldo;
    string fone;
};

//classe com metodos que são comuns a várias classes
class utilities
{
public:
    string toString(Cliente *client);
};

//vector global
vector <Cliente> myvetor;

//Sets cliente
void Cliente::setClienteNome(string nomeIn) {this->nome = nomeIn; }

void Cliente::setClienteSaldo(double saldoIn) {this->saldo += saldoIn; }

void Cliente::setClienteFone(string foneIn) {this->fone = foneIn;}

void Cliente::setClienteDataEntrada(string dateIn) {this->date = dateIn;}

void Cliente::setClienteCpf(string cpfIn) {this->cpf = cpfIn;}

//Gets cliente
string Cliente::getClienteDataEntrada(void) {return this->date;}

double Cliente::getClienteSaldo() {return this->saldo;}

int Cliente::getClienteId() {return this->id;}

string Cliente::getClienteName() {return this->nome;}

string Cliente::getClienteCpf() {return this->cpf;}

string Cliente::getClienteFone() {return this->fone;}


//metodo - utilities
string utilities::toString(Cliente *client)
{
    string block, saldo;
    
   return block += client->getClienteName(); + "\n" + client->getClienteFone();  + "\n" + client->getClienteDataEntrada(); + "\n"  + client->getClienteCpf(); + "\n" + saldo = client->getClienteSaldo(); + "\n";
}

//método - Cliente
void Cliente::cadastroCliente(string nomeIn, string dataEntradaIn, string cpfIn, string foneIn) 
{
    Cliente *person = new Cliente();
    utilities *util = new utilities();

    person->setClienteNome(nomeIn);
    person->setClienteDataEntrada(dataEntradaIn);
    person->setClienteCpf(cpfIn);
    person->setClienteFone(foneIn);
    person->setClienteSaldo(0);
    
    fstream myfile ("example.txt", ios::out|ios::app);
    if (myfile.is_open())
    {
        myfile << util->toString(person);
        myfile.close();
    }
    else cout << "Unable to open file";
    
}

//método - Cliente - retorna vector com todos os clientes salvos em txt
vector<Cliente> *Cliente::loadCliente(void)
 {
    vector <Cliente> *vetorAux;
    string line;
    double val;
    char *aux_str;
    ifstream myfile ("example.txt");
    if (myfile.is_open())
    {
        while (!myfile.eof() )
        {
            Cliente *aux = new Cliente;

            getline(myfile,line);
            aux->setClienteNome(line);
            getline (myfile,line);
            aux->setClienteFone(line);
            getline (myfile,line);
            aux->setClienteDataEntrada(line);
            getline (myfile,line);
            aux->setClienteCpf(line);
            getline (myfile,line);
            val = atof(line.c_str());
            aux->setClienteSaldo(val);
            vetorAux->push_back(*aux); // leio do arq de texto e jogo no vector
        
        }
    myfile.close();
  }else cout << "Unable to open file"; 
  return vetorAux;
}

//Método cliente
void Cliente::consultaCliente(void)
{
    Cliente *client = new Cliente;
    bool consut = true, flag = false;
    string nome;
    int i = 0, opc;
    vector<Cliente> *vectorAux;
    vectorAux = client->loadCliente();
    vector<Cliente>::iterator it = vectorAux->begin();
    
    do
    {    
        cout <<"Nome do Cliente: ";
        cin >> nome;
        for(; it != myvetor.end(); it++)
        {
            if(it->getClienteName() == nome)
            {
                cout << "Nome: " << it->getClienteName() << "\n" << "CPF: " << it->getClienteCpf() << "\n" << "Telefone: " << it->getClienteFone() << "\n" << "Data de Entrada: " << it->getClienteDataEntrada() << "\n" << "Saldo: " << it->getClienteSaldo() << endl;             
                flag = true;
            }
            i++;
            
        }
            if (flag == false)
                cout << "ERRO. Não foi encontrado cliente com esse nome." << endl;
            flag = false;
            cout << "Deseja Consultar outro cliente?  1 = SIM  /=/  0 = NÃO" << endl;   
            cin >> opc;
            if(!opc)
                consut = false;
            system("clear");
            //consertar o print
            it = vectorAux->begin();
    }while(consut);
}

//Método Cliente

void Cliente::frontClienteAdd(void)
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
            cout << "Valor do saldo inciado automaticamente com ZERO";
        
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
}

//Método cliente
void Cliente::printAllCliente(void)
{
    Cliente *client = new Cliente;
    client->loadCliente();

    vector<Cliente>::iterator it = myvetor.begin();
    while(it != myvetor.end()) 
    {
       cout << "Nome: " << it->getClienteName() << "\n" << "CPF: " << it->getClienteCpf() << "\n" << "Telefone: " << it->getClienteFone() << "\n" << "Data de Entrada: " << it->getClienteDataEntrada() << "\n" << "Saldo: " << it->getClienteSaldo() << endl;
       it++;
    }
    
}

#endif