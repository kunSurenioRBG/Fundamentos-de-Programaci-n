#include <iostream>
#include <array>

using namespace std;

const int MAX = 6;

int contarDestacados(const array<int, MAX> &numeros)
{
    int destacados = 0;

    for (int i = 1; i < MAX - 1; ++i)
    {
        if (numeros[i] >= numeros[i - 1] && numeros[i] >= numeros[i + 1])   // mayor o igual al antecedente y consecuente
        {
            destacados++;
        }
    }

    return destacados;
}

int main()
{
    array<int, MAX> numeros;

    cout << "Introduzca una coleccion de " << MAX << " numeros enteros separados por espacios en blanco: ";

    for (int i = 0; i < MAX; ++i)
    {
        cin >> numeros[i];
    }

    int destacados = contarDestacados(numeros);

    cout << "En esa coleccion hay " << destacados << " numeros destacados.\n";

    return 0;
}
