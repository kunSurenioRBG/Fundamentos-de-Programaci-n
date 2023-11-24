/*
Escribe un programa que lea un número entero desde teclado y nos diga si
es o no negativo
*/
#include <iostream>
using namespace std;
bool negativo(int n)
{
    return n < 0;
}
int main()
{
    int n;
    cout << "Introduzca un numero entero: " << endl;
    cin >> n;
    if (negativo(n))
    {
        cout << "El numero es negativo.";
    }
    else
    {
        cout << "El numero es positivo.";
    }
    return 0;
}