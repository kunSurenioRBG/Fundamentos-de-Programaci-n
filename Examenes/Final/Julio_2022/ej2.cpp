#include <iostream>
#include <array>

using namespace std;

const int MAX_PAL_DIST = 15;

typedef array<string, MAX_PAL_DIST> TArray;

struct TDatos
{
    TArray palabras;
    int nPalabras;
};

bool esta(const string &palabra, const TDatos &datos)
{
    int i = 0;

    while (i < datos.nPalabras && palabra != datos.palabras[i])
    {
        i++;
    }

    return i < datos.nPalabras;
}

int sumaASCII(const string &palabra)
{
    int suma = 0;

    for (int i = 0; i < int(palabra.size()); i++)
    {
        suma += int(palabra[i]);
    }

    return suma;
}

void mostrar(const TDatos &datos)
{
    cout << "Las palabras que cumplen la condicion son: " << endl;
    for (int i = 0; i < datos.nPalabras; i++)
    {
        cout << datos.palabras[i] << " ";
    }
}

int main()
{
    TDatos datos;
    string patron, palabra;
    int ASCIIPatron;

    cout << "Introduzca el patron: ";
    cin >> patron;

    ASCIIPatron = sumaASCII(patron);

    cout << "Introduzca el texto (FIN para terminar): ";
    cin >> palabra;

    datos.nPalabras = 0;

    while (palabra != "FIN")
    {
        if (!esta(palabra, datos) && ASCIIPatron == sumaASCII(palabra))
        {
            datos.palabras[datos.nPalabras] = palabra;
            datos.nPalabras++;
        }
        cin >> palabra;
    }

    mostrar(datos);

    return 0;
}