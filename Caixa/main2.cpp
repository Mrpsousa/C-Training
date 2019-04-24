#include <iostream>
#include "biblioteca3.h"

using namespace std;

int main ()
{
    Cliente *client = new Cliente();

    client->cadastroCliente("zeta","dois","tres","quato");
    return 0;
}