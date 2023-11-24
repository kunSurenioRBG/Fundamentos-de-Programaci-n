#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Introduzca numero de mes: ";
    cin >> n;
    switch (n)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        cout << "Este mes tiene 31 dias";
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        cout << "Este mes tiene 30 dias";
        break;
    case 2:
        cout << "Este mes tiene 28 dias";
        break;
    default:
        cout << "Mes incorrecto";
    }
    return 0;
}