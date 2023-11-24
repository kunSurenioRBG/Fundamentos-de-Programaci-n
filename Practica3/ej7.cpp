#include <iostream>
using namespace std;

int main()
{
    int a, b, c, cont;
    cout << "Dame a,b y c: ";
    cin >> a >> b >> c;

    cont = 0;
    for (int i = a; i <= b; i++)
    {
        if (i % c == 0)
        {
            cont++;
        }
    }

    cout << "Hay " << cont << " numeros.";

    return 0;
}