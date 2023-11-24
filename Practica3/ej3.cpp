#include <iostream>
using namespace std;

int main()
{
    int pos;
    int numero;
    cout << "Ingrese la posicion en la secuencia de Fibonacci: ";
    cin >> pos;

    if (pos < 0)
    {
        cout << "La posición debe ser un número no negativo." << endl;
    }
    else
    {
        if (pos == 0)
        {
            return 0; // El primer número en la secuencia es 0
        }
        else if (pos == 1)
        {
            return 1; // El segundo número en la secuencia es 1
        }
        else
        {
            int prev1 = 0; // Inicializamos el primer número anterior
            int prev2 = 1; // Inicializamos el segundo número anterior
            int resultado = 0;

            for (int i = 2; i <= pos; i++)
            {
                resultado = prev1 + prev2;
                prev1 = prev2;
                prev2 = resultado;
            }
            numero = resultado;
        }
        cout << "El numero en la posicion " << pos << " de la secuencia de Fibonacci es: " << numero << endl;
    }

    return 0;
}