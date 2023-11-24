#include <iostream>
using namespace std;

void leerDatos(int &a, int &b)
{
    while ((a <= 0 || b <= 0) && (a >= b))
    {
        cout << "Introduzca dos numeros naturales: ";
        cin >> a >> b;
    }
}

int sumaDiv(int n)
{
    int suma = 0;
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            suma += i;
        }
    }
    return suma;
}

bool sonAmigos(int a, int b)
{
    return (sumaDiv(a) == b) && (sumaDiv(b) == a);
}

int main()
{
    int a = 0, b = 0;
    leerDatos(a, b);
    if (sonAmigos(a, b))
    {
        cout << "Son amigos :D";
    }
    else
    {
        cout << "No son amigos D:";
    }
    return 0;
}
