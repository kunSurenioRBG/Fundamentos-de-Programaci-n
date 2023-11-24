#include <iostream>
using namespace std;

int main()
{
    char dia;
    int start;
    int saltoLinea = 0;
    bool ultimoDia = false;

    cout << "Introduzca el dia que cae el primero del mes: ";
    cin >> dia;

    switch (dia)
    {
    case 'L':
        start = 0;
        break;

    case 'M':
        start = 1;
        break;

    case 'X':
        start = 2;
        break;

    case 'J':
        start = 3;
        break;

    case 'V':
        start = 4;
        break;

    case 'S':
        start = 5;
        break;

    case 'D':
        start = 6;
        break;

    default:
        break;
    }

    for (int i = 0; i < start; i++)
    {
        cout << ".. ";
        saltoLinea++;
    }

    while (!ultimoDia)
    {
        
    }
}