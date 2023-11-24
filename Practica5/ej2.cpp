#include <iostream>
using namespace std;

void leer(int &n, int &x)
{
    while (n <= 0 || x <= 0)
    {
        cout << "Introduce x: ";
        cin >> x;
        cout << "Introduce n: ";
        cin >> n;
    }
}

int potencia(int &x, int n) // n va a estar cambiando por cada recursividad
{
    int resultado;

    if (n == 0)
    {
        resultado = 1;
    }
    else
    {
        resultado = x * potencia(x, n - 1);
    }

    return resultado;
}

int main()
{
    int x, n;

    leer(x, n);
    int resultado = potencia(x, n);

    cout << resultado;

    return 0;
}