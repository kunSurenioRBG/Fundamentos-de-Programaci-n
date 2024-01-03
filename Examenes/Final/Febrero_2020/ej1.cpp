#include <iostream>
#include <cmath>

using namespace std;

bool esPrimo(int primo)
{
    if (primo == 2)
    {
        return true;
    }
    else if (primo % 2 == 0) // numero pares no son primos
    {
        return false;
    }
    else
    {
        // comprobamos divisores impares, desde el 3
        for (int i = 3; i < sqrt(primo); i += 2)
        {
            if (primo % i == 0)
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    int primo = 0;
    int mayorPrimo = -1;

    cout << "Introduce una secuencia de enteros positivos acabada en 0: " << endl;
    cin >> primo;

    while (primo != 0)
    {
        if (primo > mayorPrimo && esPrimo(primo))
        {
            mayorPrimo = primo;
        }

        cin >> primo;
    }

    if (mayorPrimo == -1)
    {
        cout << "No hay ningun primo en la secuencia";
    }
    else
    {
        cout << "El mayor primo de la secuencia es: " << mayorPrimo;
    }

    return 0;
}