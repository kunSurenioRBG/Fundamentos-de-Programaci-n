#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Introduzca el valor de n: " << endl;
    cin >> n;
    while (n < 3)
    {
        cout << "Introduzca el valor de n: " << endl;
        cin >> n;
    }
    int cont = 0;

    while (cont != n)
    {
        if (cont == 0 || cont == n - 1)
        {
            for (int i = 0; i < n; i++)
            {
                cout << "&";
            }
            cout << endl;
        }
        else
        {
            for (int j = 0; j < n - cont - 1; j++)
            {
                cout << " ";
            }
            cout << "&" << endl;
        }

        cont++;
    }

    return 0;
}