/*
Escribe un programa lea de teclado un número natural (debe ser mayor de 0
y menor de 10)
que representa el número de filas de una determinada pirámide de dígitos
y que muestre por
pantalla dicha pirámide. El formato de la misma será como la que se
muestra a continuación,
para una entrada de 5 filas:
        1
      1 2 1
    1 2 3 2 1
  1 2 3 4 3 2 1
1 2 3 4 5 4 3 2 1
*/

#include <iostream>
using namespace std;

void leerNum(int &n)
{
    while (n <= 0 || n >= 10)
    {
        cout << "Introduce un numero natural entre 0 y 10: ";
        cin >> n;
    }
}

void espacios(int x)
{
    for (int i = x - 1; i != 0; i--)
    {
        cout << " ";
    }
}

void escribir(int n)
{
    // numeros del 1 al n
    for (int i = 1; i <= n; i++)
    {
        cout << i;
    }
    // numeros del n-1 al 1;
    for (int i = (n - 1); i > 0; i--)
    {
        cout << i;
    }
    cout << endl;
}

int main()
{
    int n = 0;
    leerNum(n);
    for (int fila = 1; fila <= n; fila++)
    {
        espacios(n - fila);
        escribir(fila);
    }
    return 0;
}
