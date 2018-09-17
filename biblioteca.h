#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <time.h>
#include <stdlib.h>

OLHA : https://www.inf.pucrs.br/~pinho/PRGSWB/STL/stl.html

using namespace std;


class Cliente
{
public: 
    void ler(void); // para teste
    string toString(void);
    void cadastroCliente(char*, char*, char*, char*); 
    void excluirCliente(char*);
    void editarCliente(char*);
    void saldoMaiorQ(double); // lista devedores maior que x
    void saldoMenorQ(double); // lista devedores menor que x
    //void consultarDividaTotal(void);
    //void efetuarPagamento(std::string);
    void consultaSaldoCliente(char*); // mostra o saldo do cliente x
    void setClienteNome(char*);
    void setClienteDataEntrada(char*);
    void setClienteCpf(char*);
    void setClientefone(char*);
    int getClienteId();
    char *getClienteName();
    char *getClienteDataEntrada();
    char *getClienteCpf();
    char *getClienteFone();
    char *getClienteNameById();
    double getClienteSaldoByName();
    double getClienteSaldoById();
    char *split();
    


private:
    char nome[100];
    char date[10];
    int id;
    char cpf[12];
    double saldo;
    char fone[20];
};

void consultaCliente(char*); // lista os dados do cliente x
void loadCliente(void);
void printCliente(Cliente *);
std::set <Cliente> arv;


//Sets
void Cliente::setClienteNome(char *nomeIn) {strcpy(this->nome, nomeIn);}

void Cliente::setClientefone(char *foneIn) {strcpy(this->fone, foneIn);}

void Cliente::setClienteDataEntrada(char *dateIn) {strcpy(this->date, dateIn);}

void Cliente::setClienteCpf(char *cpfIn) {strcpy(this->cpf, cpfIn);}

//Gets
char* Cliente::getClienteDataEntrada(void) {return this->date;}

int Cliente::getClienteId() {return this->id;}

char *Cliente::getClienteName() {return this->nome;}

char *Cliente::getClienteCpf() {return this->cpf;}

char *Cliente::getClienteFone() {return this->fone;}


char *Cliente::getClienteNameById()
{

}

double Cliente::getClienteSaldoByName()
{

}

double Cliente::getClienteSaldoById()
{

}

void Cliente::printCliente(class *input)
{
    cout << "Nome: " << input->getClienteName() << "\n" << "CPF: " << input->getClienteCpf() << "\n" << "Telefone: " << input->getClienteFone() << "\n" << "Data de Entrada: " << input->getClienteDataEntrada() << endl;
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

void Cliente::cadastroCliente(char *nomeIn, char *dataEntradaIn, char *cpfIn, char *foneIn) 
{
    Cliente *person = new Cliente();

    person->setClienteNome(nomeIn);
    person->setClienteDataEntrada(dataEntradaIn);
    person->setClienteCpf(cpfIn);
    person->setClientefone(foneIn);
    
    fstream myfile ("example.txt", ios::out|ios::app);
    if (myfile.is_open())
    {
        myfile << person->toString();
        myfile.close();
    }
    else cout << "Unable to open file";
    
}


 
void Cliente::loadCliente(void)
 {
    string line;
    Cliente *aux = new Cliente;
    ifstream myfile ("example.txt");
    if (myfile.is_open())
    {
        while (! myfile.eof() )
        {
            getline (myfile,line);
            aux->setClienteName(line);
            getline (myfile,line);
            aux->setClienteFone(line);
            getline (myfile,line);
            aux->setClienteDataEntrada(line);
            getline (myfile,line);
            aux->setClienteCpf(line);
            
        }
    myfile.close();
    printCliente(aux);
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
