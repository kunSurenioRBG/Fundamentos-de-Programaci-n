#include <iostream>
using namespace std;

int main()
{
    int n;
    int max_asteriscos = 2;

    do
    {
        cout << "Ingrese un numero natural menor que 10: ";
        cin >> n;
    } while (n <= 0 || n >= 10);

    for (int i = n; i >= 1; i--)
    {
        // Números descendentes en el lado izquierdo del triángulo
        for (int j = i; j >= 1; j--)
        {
            cout << j;
        }
        // incremento de 2 en 2 los * de separacion
        for (int j = 1; j <= max_asteriscos; j++)
        {
            cout << "*";
        }
        // Números ascendentes en el lado derecho del triángulo
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }

        max_asteriscos += 2;
        cout << endl;
    }

    return 0;
}
