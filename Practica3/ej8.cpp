#include <iostream>
using namespace std;

int main()
{
    int t, horas, dias, seg, min;
    cout << "Dime el tiempo en segundos" << endl;
    cin >> t;

    dias = t / (60 * 60 * 24);
    t = t % (60 * 60 * 24);
    horas = t / (60 * 60);
    t = t % (60 * 60);
    min = t / 60;
    seg = t % 60;

    if (dias != 0)
    {
        if (dias == 1)
        {
            cout << dias << " dia," << endl;
        }
        else
        {
            cout << dias << " dias," << endl;
        }
    }
    if (horas != 0)
    {
        if (horas == 1)
        {
            cout << horas << " hora," << endl;
        }
        else
        {
            cout << horas << " horas," << endl;
        }
    }
    if (min != 0)
    {
        if (min == 1)
        {
            cout << min << " minuto," << endl;
        }
        else
        {
            cout << min << " minutos," << endl;
        }
    }
    if (seg != 0)
    {
        if (seg == 1)
        {
            cout << seg << " segundo." << endl;
        }
        else
        {
            cout << seg << " segundos." << endl;
        }
    }
}