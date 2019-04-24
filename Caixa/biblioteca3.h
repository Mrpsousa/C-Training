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
    
    block += client->getClienteName(); + "\n" + client->getClienteFone();  + "\n" + client->getClienteDataEntrada(); + "\n"  + client->getClienteCpf(); + "\n" + saldo = client->getClienteSaldo(); + "\n";
    cout << " S = " << block;//teste
    return block;
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
        //cout << util->toString(person);
        myfile << util->toString(person);
        myfile.close();
       // cout << "sucess";   
    }
    else cout << "Unable to open file";   
}

#endif