#include <iostream>
#include <array>

using namespace std;

const int MAX_PAL_DIST = 20;

typedef array<string, MAX_PAL_DIST> TArray;

struct TPalabras
{
    TArray palabras;
    int nPalabra;
};

bool esta(const string &palabra, const TPalabras &datos)
{
    int i = 0;

    while (i < datos.nPalabra && datos.palabras[i] != palabra)
    {
        i++;
    }

    return i < datos.nPalabra;
}

int sumaASCII(const string &palabra)
{
    int suma = 0;

    for (int i = 0; i < int(palabra.size()); i++)
    {
        suma += palabra[i];
    }

    return suma;
}

void leerPalabras(TPalabras &datos)
{
    string palabra;
    int sumaASCIIPrimera;

    cout << "Introduce un texto (FIN para terminar): ";
    cin >> palabra;

    datos.nPalabra = 0;
    sumaASCIIPrimera = sumaASCII(palabra);

    cin >> palabra;

    while (palabra != "FIN")
    {
        if (!esta(palabra, datos) && sumaASCII(palabra) < sumaASCIIPrimera)
        {
            datos.palabras[datos.nPalabra] = palabra;
            datos.nPalabra++;
        }

        cin >> palabra;
    }
}

// ordenacion burbuja
void ordenar(TPalabras &datos)
{
    string temp;

    for (int i = 0; i < datos.nPalabra - 1; i++)
    {
        for (int j = 0; j < datos.nPalabra - i - 1; j++)
        {
            if (datos.palabras[j] > datos.palabras[j + 1])
            {
                temp = datos.palabras[j];
                datos.palabras[j] = datos.palabras[j + 1];
                datos.palabras[j + 1] = temp;
            }
        }
    }
}

void mostrarPalabras(const TPalabras &datos)
{
    cout << endl;
    cout << "Las palabras que son menores que CREO son:" << endl;
    for (int i = 0; i < datos.nPalabra; i++)
    {
        cout << datos.palabras[i] << " ";
    }
}

int main()
{
    TPalabras datos;
    leerPalabras(datos);
    ordenar(datos);
    mostrarPalabras(datos);

    return 0;
}