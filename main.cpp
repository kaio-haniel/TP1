#include "dominios.hpp"
#include <iostream>
#include <clocale>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    Data d;
    if (d.setData("29/02/2024")) {
        cout << "Data válida!" << endl; // Agora o 'á' aparecerá correto
    }
    Estado e;
    if(e.setEstado(2)) {
        cout << "O estado atual é: " << e.getEstado() << endl; // Deve imprimir FAZENDO
    }
    return 0;
}
