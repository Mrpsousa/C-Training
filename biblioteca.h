#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>

using namespace std;

class Cliente
{
public: 
    void ler(void);
    void cadastroCliente(char *, int, int, char *); 
    void excluirCliente(char*);
    void editarCliente(char*);
    void saldoMaiorQ(double); // lista devedores maior que x
    void saldoMenorQ(double); // lista devedores menor que x
    //void consultarDividaTotal(void);
    //void efetuarPagamento(std::string);
    void consultaCliente(char*); // lista os dados do cliente x
    void consultaSaldoCliente(char*); // mostra o saldo do cliente x
    void setClienteNome(char*);
    void setClienteDataEntrada(int);
    void setClienteCpf(char*);
    void setClientefone(char*);
    int getDataEntrada();
    int getClienteId();
    char *getClienteName();
    char *getClienteNameById();
    double getClienteSaldoByName();
    double getClienteSaldoById();
    


private:
    char nome[100];
    int date;
    int id;
    char cpf[12];
    double saldo;
    char fone[100];
};

//Sets
void Cliente::setClienteNome(char *nomeIn)
{
    strcpy(nome, nomeIn);
}


void Cliente::setClientefone(char *foneIn)
{
    strcpy(nome, foneIn);
}

void Cliente::setClienteDataEntrada(int dateIn)
{
    date = dateIn;
}

void Cliente::setClienteCpf(char *cpfIn)
{
    strcpy(cpf, cpfIn);
}

//Gets
int Cliente::getDataEntrada(void)
{
    return date;
}

int Cliente::getClienteId()
{
    return id;
}

char *Cliente::getClienteName()
{
    return nome;
}

char *Cliente::getClienteNameById()
{

}

double Cliente::getClienteSaldoByName()
{

}

double Cliente::getClienteSaldoById()
{

}

void Cliente::cadastroCliente(char *nome, int dataEntrada, char *cpf, char *fone) 
{
    Cliente *person = new Cliente();

    person->setClienteNome(nome);
    person->setClienteDataEntrada(dataEntrada);
    person->setClienteCpf(cpf);
    person->setClientefone(fone);

   ofstream myfile ("example.txt");
    if (myfile.is_open())
    {
        myfile << person;
        myfile.close();
    }
  else cout << "Unable to open file";
}


void Cliente::ler (void){
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
}

#endif 
