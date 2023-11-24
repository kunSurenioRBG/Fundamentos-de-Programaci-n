#include <iostream>
using namespace std;

int main()
{
    int n;
    bool esDiabolico = false;
    int seisDiabolico = 0;

    cout << "Indique un numero (>= 0): ";
    cin >> n;

    while (n < 0)
    {
        cout << "Indique un numero (>= 0): ";
        cin >> n;
    }

    int i = 0;
    while (i <= n || !esDiabolico)
    {
        int digito = n / 10;
        if (digito == 6)
        {
            cout<<digito;
            seisDiabolico++;
            n /= 10; // eliminar el ultimo digito
            i++;
        }
        else
        {
            n /= 10; // eliminar el ultimo digito
            i++;
        }

        if (seisDiabolico == 3)
        {
            esDiabolico = true;
        }
    }

    if (seisDiabolico >= 3)
    {
        cout << "Si es diabolico";
    }
    else
    {
        cout << "No es diabolico";
    }

    return 0;
}