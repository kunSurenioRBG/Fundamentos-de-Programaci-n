/*
Escribe un programa que calcule e imprima por pantalla los N primeros
números primos,
siendo N un número natural que se introduce por teclado. Por ejemplo, si
N = 8, los primos
que se mostrarán por pantalla son 2, 3, 5, 7, 11, 13, 17, 19
*/

#include <iostream>
using namespace std;

void leerDatos(int &n);
bool primo(int &n);

int main()
{
    int n = 0;
    leerDatos(n);
    int cont = n;
    int aux = 2;
    while (cont > 0)
    {
        if (primo(aux))
        {
            cont--;
            cout << aux << " ";
        }
        aux++;
    }
    return 0;
}

void leerDatos(int &n)
{
    while (n <= 0)
    {
        cout << "Introduzca un numero natural: ";
        cin >> n;
    }
}

bool primo(int &n)
{
    bool ok = true;
    int posDiv = 2;
    while (ok && posDiv <= n / 2)
    {
        if (n % posDiv == 0)
        {
            ok = false;
        }
        posDiv++;
    }
    return ok;
}