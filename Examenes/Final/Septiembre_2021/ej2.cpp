#include <iostream>
#include <array>

using namespace std;

const int MAX = 20;
typedef array<int, MAX> TArray;

struct TDatos
{
    TArray montones;
    int nMontones;
};

void leerDatos(TDatos &datos)
{
    cout << "Introduzca el numero de montones: ";
    cin >> datos.nMontones;
    cout << "Introduzca el numero de cartas de cada monton: ";
    for (int i = 0; i < datos.nMontones; i++)
    {
        cin >> datos.montones[i];
    }
}

void escribir(const TDatos &datos)
{
    for (int i = 0; i < datos.nMontones; i++)
    {
        cout << datos.montones[i] << " ";
    }
    cout << "\n";
}

bool terminado(const TDatos &datos)
{
    int i = 0;

    while (i < datos.nMontones && datos.montones[i] == i + 1)
    {
        i++;
    }

    return i >= datos.nMontones;
}

void desplazoIzquierda(TDatos &datos, int contador)
{
    for (int i = contador; i < datos.nMontones - 1; i++)
    {
        datos.montones[i] = datos.montones[i + 1];
    }
    datos.nMontones--;
}

void reorganizar(TDatos &datos)
{
    int contador = 0;
    int nuevoMonton = 0;

    while (contador < datos.nMontones)
    {
        datos.montones[contador]--;
        nuevoMonton++;
        if (datos.montones[contador] == 0)
        {
            desplazoIzquierda(datos, contador);
        }
        else
        {
            contador++;
        }
    }
    datos.montones[datos.nMontones] = nuevoMonton;
    datos.nMontones++;
}

int main()
{
    TDatos datos;

    leerDatos(datos);
    escribir(datos);
    while (!terminado(datos))
    {
        reorganizar(datos);
        escribir(datos);
    }

    return 0;
}