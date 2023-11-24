#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Introduzca un numero natural: ";
    cin >> n;

    int cantidad = 0;
    if (n == 0)
    {
        cantidad++;
    }

    while (n != 0)
    {
        n /= 10;
        cantidad++;
    }

    cout << "Cantidad digitos: " << cantidad;

    return 0;
}