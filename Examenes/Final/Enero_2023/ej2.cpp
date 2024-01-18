#include <iostream>
#include <array>

using namespace std;

const int MAX_PAL_DIST = 15;

typedef array<string, MAX_PAL_DIST> TArray;

struct TPalabras
{
    TArray palabras;
    int nPalabras;
};

bool esta(const string &palabra, const TPalabras &datos)
{
    int i = 0;

    while (i < datos.nPalabras && palabra != datos.palabras[i])
    {
        i++;
    }

    return i < datos.nPalabras;
}

int buscarLetra(char letra, const string &locograma)
{
    int pos = -1;
    bool encontrado = false;
    int i = 0;

    while (i < int(locograma.size()) && !encontrado)
    {
        if (locograma[i] == letra)
        {
            pos = i;
            encontrado = true;
        }
        i++;
    }

    return pos;
}

void comprobarLetras(const string &palabra, const string &locograma, bool &esLaOstiaDeLocograma)
{
    int i = 0;

    while (i < int(palabra.size()) && esLaOstiaDeLocograma)
    {
        int pos = buscarLetra(palabra[i], locograma);
        if (pos < 0)
        {
            esLaOstiaDeLocograma = false;
        }
        i++;
    }
}

bool esLocograma(const string &palabra, const string &locograma)
{
    bool esLaOstiaDeLocograma = true;

    if (int(palabra.size()) != int(locograma.size()))
    {
        esLaOstiaDeLocograma = false;
    }
    else
    {
        comprobarLetras(palabra, locograma, esLaOstiaDeLocograma);
        comprobarLetras(locograma, palabra, esLaOstiaDeLocograma);
    }

    return esLaOstiaDeLocograma;
}

void escribir(const TPalabras &datos)
{
    cout << "Las palabras que son locogramas son: \n";
    for (int i = 0; i < datos.nPalabras; i++)
    {
        cout << datos.palabras[i] << " \n";
    }
}

int main()
{
    TPalabras datos;
    string palabra, locograma;

    cout << "Introduzca un texto (FIN para terminar): \n";
    cin >> palabra;
    datos.nPalabras = 0;
    while (palabra != "FIN")
    {
        locograma = palabra;
        cin >> palabra;
        while (palabra != "FIN")
        {
            if (esLocograma(palabra, locograma) && !esta(palabra, datos))
            {
                datos.palabras[datos.nPalabras] = palabra;
                datos.nPalabras++;
            }
            cin >> palabra;
        }
    }

    escribir(datos);

    return 0;
}