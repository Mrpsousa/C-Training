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
    void ler(void); // para teste
    void cadastroCliente(string, string, string, string); 
    void excluirCliente(char*);
    void editarCliente(char*);
    //void consultarDividaTotal(void);
    //void efetuarPagamento(std::string);
    void consultaSaldoCliente(string); // mostra o saldo do cliente x
    void consultaCliente(void);
    int addClienteCompra(void);
    void setClienteNome(string);
    void setClienteSaldo(double);
    void setClienteDataEntrada(string);
    void setClienteCpf(string);
    void setClienteFone(string);
    int getClienteId();
    string getClienteName();
    double getClienteSaldo();
    string getClienteDataEntrada();
    string getClienteCpf();
    string getClienteFone();
    double getClienteSaldoByName();
    double getClienteSaldoById();
    char *split();
    void printAllCliente(void);
    void loadCliente(void);
    void frontClienteAdd(void);
private:
    string nome;
    string date;
    int id;
    string cpf;
    double saldo;
    string fone;
};


class utilities
{
public:
    string toString(Cliente *);
};

vector <Cliente> myvetor;

void consultaCliente(char*); // lista os dados do cliente x

//Sets
void Cliente::setClienteNome(string nomeIn) {this->nome = nomeIn; }

void Cliente::setClienteSaldo(double saldoIn) {this->saldo += saldoIn; }

void Cliente::setClienteFone(string foneIn) {this->fone = foneIn;}

void Cliente::setClienteDataEntrada(string dateIn) {this->date = dateIn;}

void Cliente::setClienteCpf(string cpfIn) {this->cpf = cpfIn;}

//Gets
string Cliente::getClienteDataEntrada(void) {return this->date;}

double Cliente::getClienteSaldo() {return this->saldo;}

int Cliente::getClienteId() {return this->id;}

string Cliente::getClienteName() {return this->nome;}

string Cliente::getClienteCpf() {return this->cpf;}

string Cliente::getClienteFone() {return this->fone;}


int Cliente::addClienteCompra()
{
    string nomeIn; 
    double valorIn;

    cout << "Cliente: " << endl;
    cin >> nomeIn;
    cout << "Valor da Compra: " << endl;
    cin >> valorIn;
    
    Cliente *client = new Cliente;
    utilities *util = new utilities;

    remove("example.txt");
    client->loadCliente();
    vector<Cliente>::iterator it = myvetor.begin();
    do
    {    
        for(; it != myvetor.end(); it++)
        {
            if(it->getClienteName() == nomeIn)
            {
                it->setClienteSaldo(valorIn);
                fstream myfile ("example.txt", ios::out|ios::app);
                for(; it != myvetor.end(); it++)
                {       
                    if (myfile.is_open())
                    {
                        myfile << util->toString();
                        myfile.close();
                    }
                    else cout << "Unable to open file"; 
                }
                return 0;    
            }
        }
    }while(it != myvetor.end());
    cout << "Cliente Não existe" << endl;
    //quando terminar a operação de add valor de compra, deleter arquivo txt, 
    //realocar todo pessoal do vetor em 1 texto novo
}
double Cliente::getClienteSaldoByName()
{

}

double Cliente::getClienteSaldoById()
{

}

string utilities::toString(Cliente *client)
{
    string nomeL, dataL, cpfL, foneL, saldoL, block;
    
    saldoL = client->getClienteSaldo();
    nomeL = client->getClienteName(); 
    dataL = client->getClienteDataEntrada();
    cpfL = client->getClienteCpf();
    foneL = client->getClienteFone();

   return block += nomeL + "\n" + foneL  + "\n" + dataL + "\n"  + cpfL + "\n" + saldoL + "\n";
}

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

 
void Cliente::loadCliente(void)
 {
    string line;
    double val;
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
            getline (myfile,line);
            val = atof(line.c_str());
            aux->setClienteSaldo(val);
            myvetor.push_back(*aux); // leio do arq de texto e jogo no vector
            
        }
    myfile.close();
  }else cout << "Unable to open file"; 
}




void Cliente::consultaCliente(void)
{
    Cliente *client = new Cliente;
    bool consut = true, flag = false;
    string nome;
    int i = 0, opc;

    client->loadCliente();
    vector<Cliente>::iterator it = myvetor.begin();
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
            it = myvetor.begin();
    }while(consut);
}


void Cliente::frontClienteAdd()
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
