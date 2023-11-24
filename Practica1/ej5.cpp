#include <iostream>
using namespace std;
double calcularPrecio(int n)
{
    return (n * 100) + (n * 100 * 0.12);
}
double aplicarDescuento(double n)
{
    return calcularPrecio(n) - (calcularPrecio(n) * 0.05);
}
int main()
{
    int n;
    cout << "Numero de unidades adquiridas: ";
    cin >> n;
    if (calcularPrecio(n) > 300)
    {
        cout << "Se aplica un descuento del 5%" << endl;
        cout << "El precio total a pagar es: " << aplicarDescuento(n) << " euros ";
    }
    else
    {
        cout << "El precio total a pagar es: " << calcularPrecio(n) << " euros ";
    }
    return 0;
}