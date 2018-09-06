#include <iostream>
#include "biblioteca.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Cliente *teste = new Cliente();

    teste->setClienteNome("antonio");

    cout << teste->getClienteName();
    return 0;
}
