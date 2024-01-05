#include <iostream>
#include <array>

using namespace std;

const int MAX_PAL_DIST = 10;
typedef array<string, MAX_PAL_DIST> TArray;

struct TPalabras
{
    TArray palabras;
    int nPalabras;
};

bool esta(const string &texto, const TPalabras &datos)
{
    int i = 0;

    while (i < datos.nPalabras && texto != datos.palabras[i])
    {
        i++;
    }

    return i < datos.nPalabras;
}

int buscar(char c, const string &palabra)
{
    int i = 0;

    while (i < int(palabra.size()) && c != palabra[i])
    {
        i++;
    }

    return i;
}

bool palabraValida(const string &patron, const string &palabra, int x)
{
    string palAux = palabra;

    int indice = 0;
    int caracComun = 0;
    int pos; // simbolo en el que me encuentro del patron

    // patron = ALICIA    /   palabra = CREO
    while (caracComun < x && indice < int(patron.size()))
    {
        pos = buscar(patron[indice], palAux);

        if (pos < int(palabra.size())) // EJ: la primera silaba de Alicia (A) coincide con alguna de CREO
        {
            palAux[pos] = ' ';
            caracComun++;
        }
        indice++;
    }

    return caracComun >= x;
}

void leerDatos(TPalabras &datos)
{
    string patron, texto;
    int x;

    cout << "Introduzca el patron: ";
    cin >> patron;

    cout << "Introduzca el valor x: ";
    cin >> x;

    cout << "Introduzca el texto (FIN para terminar): ";
    cin >> texto;

    datos.nPalabras = 0;

    while (texto != "FIN")
    {
        if (!esta(texto, datos) && palabraValida(patron, texto, x))
        {
            datos.palabras[datos.nPalabras] = texto;
            datos.nPalabras++;
        }
        cin >> texto;
    }
}

void mostrarDatos(const TPalabras &datos)
{
    cout << "Las palabras son: " << endl;
    for (int i = 0; i < datos.nPalabras; i++)
    {
        cout << datos.palabras[i] << " ";
    }
}

int main()
{
    TPalabras datos;
    leerDatos(datos);
    mostrarDatos(datos);

    return 0;
}