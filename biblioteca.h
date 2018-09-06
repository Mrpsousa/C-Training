#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED
#include <string.h>

class Cliente
{
public: 
    void cadastroCliente(char *, int, int, char); //nome, data_entrada, ID, sexo
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

#endif 
