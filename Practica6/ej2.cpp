#include <iostream>
#include <array>

using namespace std;

const int TAM = 50;

typedef array<int, TAM> TArray;

struct TEstaturas
{
    TArray estaturas;
    int nEstaturas;
};

void leer(TEstaturas &e)
{
    cout << "Cuantas estaturas vas a introducir (MAX: 50): " << endl;
    cin >> e.nEstaturas;

    while (e.nEstaturas < 0 || e.nEstaturas > 50)
    {
        cout << "Cuantas estaturas vas a introducir (MAX: 50): " << endl;
        cin >> e.nEstaturas;
    }

    cout << "Introduzca las " << e.nEstaturas << " estaturas: " << endl;
    for (int i = 0; i < e.nEstaturas; i++)
    {
        cin >> e.estaturas[i];
    }
}

double media(const TEstaturas &e)
{
    double suma = 0;

    for (int i = 0; i < e.nEstaturas; i++)
    {
        suma += e.estaturas[i];
    }

    return suma / e.nEstaturas;
}

int masAlto(TEstaturas &e, double med)
{
    int suma = 0;

    for (int i = 0; i < e.nEstaturas; i++)
    {
        if (med < e.estaturas[i])
        {
            suma++;
        }
    }
    return suma;
}

int masBajo(TEstaturas &e, double med)
{
    int suma = 0;

    for (int i = 0; i < e.nEstaturas; i++)
    {
        if (med > e.estaturas[i])
        {
            suma++;
        }
    }
    return suma;
}

int main()
{
    TEstaturas e;

    leer(e);
    double med = media(e);
    cout << "La media es: " << med << endl;
    cout << "Numero de alumnos mas altos que la media: " << masAlto(e, med) << endl;
    cout << "Numero de alumnos mas bajos que la media: " << masBajo(e, med) << endl;

    return 0;
}