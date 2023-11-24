#include <iostream>
using namespace std;
int main()
{
    int n;
    double pi = 4;
    double num = 2;
    double denom = 3;
    cout << "Introduzca un valor entero: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        pi = pi * num / denom;
        if (i % 2 != 0)
        {
            num += 2;
        }
        else
        {
            denom += 2;
        }
    }
    cout << "El valor de PI es aproximadamente " << pi;
    return 0;
}
