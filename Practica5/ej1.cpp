#include <iostream>
using namespace std;

void leer(int &n)
{
    do
    {
        cout << "Introduce un numero entero mayor que 0: " << endl;
        cin >> n;
    } while (n < 0);
}
// si paso la variable como valor, no se modifica al sacarla
// si paso la variable como referencia, al devolver la variable en la funcion, modifico su valor
int sumatorio(int &n, int &suma) // n podria pasarla por valor (no modifico) pero seria copiar 2 veces el valor en memoria = INEFICIENTE!!! 
{
    for (int i = 1; i <= n; i++)
    {
        suma += i;
    }

    return suma;
}

int main()
{
    int n;
    int suma = 0;

    leer(n);
    sumatorio(n, suma);

    cout << suma;

    return 0;
}