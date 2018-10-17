#include <iostream>
#include "biblioteca.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Cliente *client = new Cliente();
    int opc;

    cout << "=============== CAIXA ================" << endl;
    cout << endl;
    cout << "Selecione a opção: " << endl;
    cout << "1 : Adiciona Cliente" << endl;
    cout << "2 : Consulta Cliente" << endl;
    cin >> opc;
    system("clear");
    switch (opc)
    {
        case 1:
            client->consultaCliente(); 
            break;
        case 2:
            client->frontClienteAdd();
            break;  
    }      
    return 0;
}
