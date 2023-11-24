#include <iostream>
using namespace std;

int main()
{
    int dividendo, divisor;
    int cociente = 0;
    int resto = 0;

    // Solicitar al usuario que ingrese los números
    cout << "Ingrese el dividendo: ";
    cin >> dividendo;
    cout << "Ingrese el divisor: ";
    cin >> divisor;

    // Verificar si el divisor es igual a cero
    if (divisor == 0)
    {
        cout << "No se puede dividir por cero." << endl;
    }
    else
    {
        // Calcular el cociente y el resto mediante restas sucesivas
        while (dividendo >= divisor)
        {
            dividendo -= divisor;
            cociente++;
        }
        resto = dividendo;

        // Mostrar los resultados
        cout << "Cociente: " << cociente << endl;
        cout << "Resto: " << resto << endl;
    }

    return 0;
}
