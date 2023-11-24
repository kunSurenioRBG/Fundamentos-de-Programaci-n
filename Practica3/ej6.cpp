#include <iostream>
using namespace std;

int main()
{
    int n, posicion;
    char c;

    cout << "Escribe una posicion y 4 letras" << endl;
    cin >> n;

    for (int i = 0; i < 4; i++)
    {
        cin >> c;
        posicion = int(c) + n;

        if (posicion > int('Z'))
        {
            posicion = posicion - (int('Z') - int('A')) - 1;
        }
        cout << char(posicion);
    }

    return 0;
}