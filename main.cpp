#include <iostream>
#include "biblioteca.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Cliente *teste = new Cliente();

    //vai assim Nome,data,CPF,Fone
    //salva assim Fone#data#CPF#Nome
    
    teste->cadastroCliente("Nome","data","CPF","Fone");

   teste->ler();
    return 0;
}
