/*
Escribe un programa que lea tres números enteros y que diga cuál de ellos
es el mayor
estricto (único), o una indicación de que no existe. Por ejemplo, si se
introducen los números
7, 9 y -2, la salida será una indicación de que el mayor estricto es el
9. En cambio, si se
introducen los números 7, 9 y 9, la salida será una indicación de que no
hay mayor estricto
*/
#include <iostream>
using namespace std;
int main()
{
    int n;
    int mayor;
    int cont = 0;
    cout << "Introduzca una serie de 3 numeros enteros:" << endl;
    cin >> mayor;
    for (int i = 1; i < 3; i++)
    {
        cin >> n;
        if (n == mayor)
        {
            cont++;
        }
        if (n > mayor)
        {
            mayor = n;
        }
    }
    if (cont > 0)
    {
        cout << "No existe mayor estricto.";
    }
    else
    {
        cout << "El numero mayor estricto es " << mayor;
    }
    return 0;
}