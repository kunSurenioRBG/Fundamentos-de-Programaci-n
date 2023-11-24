#include <iostream>
using namespace std;

int main()
{
    int n;
    int posicion = 1;
    cout << "Introduzca una secuencia de numeros acabada en 0: ";
    cin >> n;

    bool hayAbundante = false; // para comprobar que hay al menos 1 n.abundante

    while (n != 0 && !hayAbundante)
    {
        int resultado = 0;
        for (int i = 1; i < n; i++)
        {
            if (n % i == 0)
            {
                resultado += i;
            }
        }

        hayAbundante = (resultado > n); // habra un n.abudante cuando el resultado sea mayor que n

        if (!hayAbundante)
        {
            posicion++;
            cin >> n; // salto al siguiente numero 
        }
        else
        {
            cout << "Si existe al menos un numero abundante, " << n << ", en la posicion " << posicion << ".";
        }
    }

    if (!hayAbundante)
    {
        cout << "No existe ningun numero abundante";
    }

    return 0;
}