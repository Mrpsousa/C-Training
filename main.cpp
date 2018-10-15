#include <iostream>
#include "biblioteca.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Cliente *client = new Cliente();
    
    client->consultaCliente(); //problema com o consulta cliente
    //client->frontClienteAdd(); //opc 1
    //cout << "Escolha as opçoes abaixo"
   //client->printCliente();
  // teste->ler();
    return 0;
}
