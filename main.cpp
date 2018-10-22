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
    cout << "3 : Listar Clientes" << endl;
    cin >> opc;
    system("clear");
    switch (opc)
    {
        case 1:
            client->frontClienteAdd();
            break;
        case 2:
            client->consultaCliente(); 
            break;
        case 3:
            cout << "Função nao Implementada ainda" << endl; 
            break;  
    }      
    return 0;
}
