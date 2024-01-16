#include <iostream>
#include <array>

using namespace std;

const int MAX_PAL_DIST = 20;

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

bool caracteresOrdenados(const string &palabra)
{
    int i = 0;

    while (i < int(palabra.size()) - 1 && palabra[i] <= palabra[i + 1]) // -1 hasta la pelultima letra para comparar con la ultima letra
    {
        i++;
    }

    return i >= int(palabra.size()) - 1;
}

void escribir(const TDatos &datos)
{
    cout << "Las palabras cuyos caracteres estan ordenados son: " << endl;
    for (int i = 0; i < datos.nPalabras; i++)
    {
        cout << datos.palabras[i] << " ";
    }
}

void leerDatos(TDatos &datos)
{
    string palabra;

    cout << "Introduzca el texto (FIN para terminar): ";
    cin >> palabra;

    datos.nPalabras = 0;

    while (palabra != "FIN")
    {
        if (!esta(palabra, datos) && caracteresOrdenados(palabra))
        {
            datos.palabras[datos.nPalabras] = palabra;
            datos.nPalabras++;
        }
        cin >> palabra;
    }
}

int main()
{
    TDatos datos;

    leerDatos(datos);
    escribir(datos);

    return 0;
}
