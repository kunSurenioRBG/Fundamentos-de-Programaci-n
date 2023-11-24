/*
Escribe un programa que lea un carácter del teclado y compruebe si el
carácter es una letra,
en cuyo caso la salida debe ser “Es letra”, o si el carácter es un punto
(‘.’), en cuyo caso la
salida debe ser “Es punto”. Si el carácter no es ni una letra ni un punto
la salida debe ser
“Error”.
*/
#include <iostream>
using namespace std;
int main()
{

    char c;
    cout << "Introduzca un caracter: " << endl;
    cin >> c;
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
    {
        cout << "Es letra.";
    }
    else if (c == '.')
    {
        cout << "Es punto.";
    }
    else
    {
        cout << "Error.";
    }

    return 0;
}