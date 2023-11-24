#include <iostream>
using namespace std;

int main()
{
    int n, cont1 = 0, cont2 = 0;

    cout << "Dame números: ";
    cin >> n;

    while (n != 0)
    {
        if (n < 0)
        {
            cont1++; // Negativos
        }
        else
        {
            cont2++; // Positivos
        }
        cin >> n;
    }

    if (cont1 < cont2)
    {
        cout << "Hay más positivos que negativos" << endl;
    }
    else if (cont1 > cont2)
    {
        cout << "Hay más negativos que positivos" << endl;
    }
    else
    {
        cout << "Mismo número de negativos y positivos" << endl;
    }

    return 0;
}