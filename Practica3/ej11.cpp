#include <iostream>
using namespace std;

int main()
{
    unsigned N;
    unsigned d = 0;
    unsigned cont = 0;

    cout << "Dame número: ";
    cin >> N;

    do
    {
        d = N % 10;

        if (d % 2 == 0)
        {
            cont++;
        }

        N = N / 10;

    } while (N != 0);

    cout << "El número de pares es: " << cont << endl;

    return 0;
}