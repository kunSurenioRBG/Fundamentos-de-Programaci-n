#include <iostream>
using namespace std;
int main()
{
    int n, x, suma = 0;
    cout << "Introduzca numero de modelos de coche: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cout << "Precio modelo " << i << ": ";
        cin >> x;
        suma += x;
    }
    cout << "El valor medio de los 4 modelos de coche asciende a: " << suma / n << " euros ";
    return 0;
}
