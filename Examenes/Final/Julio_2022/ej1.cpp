#include <iostream>
#include <array>

using namespace std;

const int TAM = 10;

typedef array<int, TAM> TArray;

void leer(TArray &array)
{
    int entero;

    cout << "Introduce 10 numeros enteros: " << endl;
    for (int i = 0; i < TAM; i++)
    {
        cin >> entero;
        array[i] = entero;
    }
}

int mayorLongitud(const TArray &array)
{
    int mayor = 0;
    int longitud = 1;

    for (int i = 1; i < TAM; i++)
    {
        if (array[i - 1] > array[i])
        {
            if (longitud > mayor)
            {
                mayor = longitud;
            }
            longitud = 0;
        }
        longitud++;
    }

    // para comprobar si la ultima sucesion es la de mayor longitud
    if (longitud > mayor)
    {
        mayor = longitud;
    }

    return mayor;
}

int main()
{
    TArray array;

    leer(array);

    cout << "La longitud de la mayor sub-sucesion es: " << mayorLongitud(array) << endl;

    return 0;
}