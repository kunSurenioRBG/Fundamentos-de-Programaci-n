#include <iostream>
using namespace std;

double primeros100(int n)
{
    return n * 0.5;
}
double sig150(int n)
{
    return n * 0.35;
}
double resto(int n)
{
    return n * 0.25;
}
double calcularPrecio(int n)
{
    double precio = 1;
    if (n <= 100)
    {
        precio += primeros100(n);
    }
    else if (n <= 150)
    {
        precio += primeros100(100) + sig150(n - 100);
    }
    else
    {
        precio += primeros100(100) + sig150(150) + resto(n - 250);
    }
    return precio;
}

int main()
{
    int n;
    cout << "Introduzca el consumo del contador: ";
    cin >> n;
    cout << "El importe a pagar es: " << calcularPrecio(n);
    return 0;
}