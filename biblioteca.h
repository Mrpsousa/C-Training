#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <set>
#include <vector>

//OLHA : https://www.inf.pucrs.br/~pinho/PRGSWB/STL/stl.html

using namespace std;

class Cliente
{
public: 
    void ler(void); // para teste
    string toString(void);
    void cadastroCliente(string, string, string, string); 
    void excluirCliente(char*);
    void editarCliente(char*);
    void saldoMaiorQ(double); // lista devedores maior que x
    void saldoMenorQ(double); // lista devedores menor que x
    //void consultarDividaTotal(void);
    //void efetuarPagamento(std::string);
    void consultaSaldoCliente(string); // mostra o saldo do cliente x
    void setClienteNome(string);
    void setClienteDataEntrada(string);
    void setClienteCpf(string);
    void setClienteFone(string);
    int getClienteId();
    string getClienteName();
    string getClienteDataEntrada();
    string getClienteCpf();
    string getClienteFone();
    char *getClienteNameById();
    double getClienteSaldoByName();
    double getClienteSaldoById();
    char *split();
    void printCliente(void);
    void loadCliente(void);

private:
    string nome;
    string date;
    int id;
    string cpf;
    double saldo;
    string fone;
};
vector <Cliente> myvetor;

void consultaCliente(char*); // lista os dados do cliente x


//Sets
void Cliente::setClienteNome(string nomeIn) {this->nome = nomeIn; }

void Cliente::setClienteFone(string foneIn) {this->fone = foneIn;}

void Cliente::setClienteDataEntrada(string dateIn) {this->date = dateIn;}

void Cliente::setClienteCpf(string cpfIn) {this->cpf = cpfIn;}

//Gets
string Cliente::getClienteDataEntrada(void) {return this->date;}

int Cliente::getClienteId() {return this->id;}

string Cliente::getClienteName() {return this->nome;}

string Cliente::getClienteCpf() {return this->cpf;}

string Cliente::getClienteFone() {return this->fone;}


char *Cliente::getClienteNameById()
{

}

double Cliente::getClienteSaldoByName()
{

}

double Cliente::getClienteSaldoById()
{

}

string Cliente::toString(void)
{
    string nomeL, dataL, cpfL, foneL, block;
    
    nomeL = getClienteName(); 
    dataL = getClienteDataEntrada();
    cpfL = getClienteCpf();
    foneL = getClienteFone();

   return block += nomeL + "\n" + foneL  + "\n" + dataL + "\n"  + cpfL + "\n";
}

void Cliente::cadastroCliente(string nomeIn, string dataEntradaIn, string cpfIn, string foneIn) 
{
    Cliente *person = new Cliente();

    person->setClienteNome(nomeIn);
    person->setClienteDataEntrada(dataEntradaIn);
    person->setClienteCpf(cpfIn);
    person->setClienteFone(foneIn);
    
    fstream myfile ("example.txt", ios::out|ios::app);
    if (myfile.is_open())
    {
        myfile << person->toString();
        myfile.close();
    }
    else cout << "Unable to open file";
    
}


void Cliente::printCliente(void)
{
    Cliente *client = new Cliente;
    client->loadCliente();

    vector<Cliente>::iterator it = myvetor.begin();
    for(it; it != myvetor.end(); it++)
    {
       cout << "Nome: " << it->getClienteName() << "\n" << "CPF: " << it->getClienteCpf() << "\n" << "Telefone: " << it->getClienteFone() << "\n" << "Data de Entrada: " << it->getClienteDataEntrada() << endl;
    }
    
}

 
void Cliente::loadCliente(void)
 {
    string line;
    char *aux_str;
    Cliente *aux = new Cliente;
    ifstream myfile ("example.txt");
    if (myfile.is_open())
    {
        while (!myfile.eof() )
        {
            getline(myfile,line);
            aux->setClienteNome(line);
            getline (myfile,line);
            aux->setClienteFone(line);
            getline (myfile,line);
            aux->setClienteDataEntrada(line);
            getline (myfile,line);
            aux->setClienteCpf(line);
            myvetor.push_back(*aux); // leio do arq de texto e jogo no vector
        }
    myfile.close();
  }else cout << "Unable to open file"; 
}


/*void Cliente::ler (void){
    string line;
    ifstream myfile ("example.txt");
    if (myfile.is_open())
    {
        while (! myfile.eof() )
        {
            getline (myfile,line);
            cout << line << endl;
            
        }
    myfile.close();
  }

  else cout << "Unable to open file"; 
}*/

#endif 
