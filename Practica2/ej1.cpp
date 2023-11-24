#include <iostream>
using namespace std;
int main()
{
    /*
    ======== WHILE ========
    int n = 0;
    cout << "Introduce un numero mayor a 0: ";
    cin >> n;
    while (n <= 0)
    {
        cout << "Introduce un numero mayor a 0: ";
        cin >> n;
    }
    int sol = 0;
    for (int i = 1; i <= n; i++)
    {
        sol += i;
    }

    cout << "La suma de los " << n << " primeros numeros enteros positivos es "<<sol;
        return 0;
    */

    /*
    ======== FOR ========
    int solucion = 0;
    int n = 0;
    cout << "Introduce un numero mayor a 0: ";
    cin >> n;

    while (n <= 0)
    {
        cout << "Introduce un numero mayor a 0: ";
        cin >> n;
    }

    for (int i = 1; i <= n; i++)
    {
        solucion += i;
    }

    cout << "La suma de los " << n << " primeros numeros enteros positivos es " << solucion;
    return 0;
    */

    // ======== DO - WHILE ========
    int solucion = 0;
    int n = 0;
    cout << "Introduce un numero mayor a 0: ";
    cin >> n;

    while (n <= 0)
    {
        cout << "Introduce un numero mayor a 0: ";
        cin >> n;
    }

    int i = 0;
    do
    {
        solucion += i;
        i++;
    } while (i <= n);

    cout << "La suma de los " << n << " primeros numeros enteros positivos es " << solucion;
    return 0;
}
