#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED
#include <iostream>
#include <fstream>
#include <string>

class Cliente
{
public: 
    void cadastroCliente(char *, int, int, char); //nome, data_entrada, ID, sx
    void excluirCliente(char *);
    void editarCliente(char *);
    void saldoMaiorQ(double); // lista devedores maior que x
    void saldoMenorQ(double); // lista devedores menor que x
    //void consultarDividaTotal(void);
    //void efetuarPagamento(std::string);
    void consultaCliente(char *); // lista os dados do cliente x
    void consultaSaldoCliente(char *); // mostra o saldo do cliente x
    void setClienteNome(char *);
    void setClienteDataEntrada(int);
    void setClienteSexo(char);
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
    char sexo;
    double saldo;
};

//Sets
void Cliente::setClienteNome(char *nomeIn)
{
    strcpy(nome, nomeIn);
}

void Cliente::setClienteDataEntrada(int dateIn)
{
    date = dateIn;
}

void Cliente::setClienteSexo(char sexoIn)
{
    sexo = sexoIn;
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

void cadastroCliente(char *, int, int, char) //nome, data_entrada, ID, sx
{
    ofstream myfile ("example.txt");
    if (myfile.is_open())
    {
        myfile << "This is a line.\n";
        myfile << "This is another line.\n";
        myfile.close();
    }
  else cout << "Unable to open file";
}

void ler (void){
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

// reading a text file

using namespace std;

int main () {
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

  return 0;
}[/code]


enquanto esse outro tem tudo o q você precisa pra escrever nele:
[code]// writing on a text file
#include <iostream>
#include <fstream>
using namespace std;

int main () {
  ofstream myfile ("example.txt");
  if (myfile.is_open())
  {
    myfile << "This is a line.\n";
    myfile << "This is another line.\n";
    myfile.close();
  }
  else cout << "Unable to open file";
  return 0;
}

#endif 
