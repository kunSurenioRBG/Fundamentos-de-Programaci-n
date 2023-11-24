#include <iostream>
using namespace std;

int main()
{
    int n, cont;

    cout << "Escribe el numero" << endl;
    cin >> n;

    cont = 0;
    while (n != 1)
    {
        if (n % 2 == 0)
        {
            n = n / 2;
        }
        else
        {
            n = (n * 3) + 1;
        }
        cont++;
    }

    cout << "En " << cont << " pasos hemos encontrado el 1" << endl;
}