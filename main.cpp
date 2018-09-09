#include <iostream>
#include "biblioteca.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Cliente *teste = new Cliente();

    teste->cadastroCliente("casa",123,324,"carro");

   // teste->ler();
    return 0;
}
