#include <iostream>
using namespace std;

void espaciosSup(int n)
{
    for (int i = n; i > 0; i--)
    {
        cout << " ";
    }
}

void asteriscosSup(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "* ";
    }
}

void trigSup(int &n)
{
    for (int fila = 1; fila <= n; fila++)
    {
        espaciosSup(n - fila);
        asteriscosSup(fila);
        cout << endl;
    }
}

void espaciosInf(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << " ";
    }
}

void asteriscosInf(int n)
{
    for (int i = n; i > 0; i--)
    {
        cout << "* ";
    }
}

void trigInf(int &n)
{
    for (int fila = 1; fila <= n; fila++)
    {
        espaciosInf(fila);
        asteriscosInf(n - fila);
        cout << endl;
    }
}


int main()
{
    int n;
    cout << "Introduce un numero natural: ";
    cin >> n;
    trigSup(n);
    trigInf(n);
    return 0;
}
