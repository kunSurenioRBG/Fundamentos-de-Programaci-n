#include <iostream>
using namespace std;
int main()
{
    char c;
    int caracteres = 0;
    cout << "Introduzca el texto terminado en un punto: " << endl;
    cin.get(c);
    while (c != '.')
    {
        caracteres++;
        cout << int(c) << " " << endl; // int(c) devuelve el valor ASCII del caracter
        cin.get(c);
    }
    cout << "Numero de caracteres leidos: " << caracteres;
    return 0;
}
