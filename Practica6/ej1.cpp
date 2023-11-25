#include <iostream>
#include <array>

using namespace std;

const int TAM = 10;

typedef array<int, TAM> TArray;

void leer(TArray &numeros)
{
    cout << "Introduce 10 numeros naturales: ";
    for (int i = 0; i < TAM; i++)
    {
        cin >> numeros[i];
    }
}

int mayor(TArray &numeros)
{
    int mayor = numeros[0];
    for (int i = 1; i < TAM; i++)
    {
        if (mayor < numeros[i])
        {
            mayor = numeros[i];
        }
    }
    return mayor;
}

int main()
{
    TArray numeros = {}; // inicializar array vacio

    leer(numeros);
    cout << mayor(numeros);

    return 0;
}