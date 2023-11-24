#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    while (n <= 0)
    {
        cout << "Introduzca un numero: ";
        cin >> n;
    }
    for (int f = 1; f <= n; f++)
    {
        for (int c = 1; c <= n; c++)
        {
            if ((f + c) % 2) // usando el modulo para diferenciar en que columna ira el siguiente signo
            {
                cout << "o";
            }
            else
            {
                cout << "x";
            }
        }
        cout << endl;
    }
    return 0;
}