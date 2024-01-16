#include <iostream>
#include <array>

using namespace std;

const int MAX_PAL_DIST = 20;
const int MAX_CAR_PATRON = 5;

typedef array<string, MAX_PAL_DIST> TPalabras_Comunes;

struct TPalabrasConLetras
{
    TPalabras_Comunes palabras;
    int nPalabras;
};

struct TPalabras
{
    char letra;
    TPalabrasConLetras lista_palabras;
};

typedef array<TPalabras, MAX_CAR_PATRON> TArrayLetras;

struct TDatos
{
    TArrayLetras letras;
    int nLetras;
};

bool esta_letra(char letra, const TDatos &letras)
{
    int i = 0;

    while (i < letras.nLetras && letra != letras.letras[i].letra)
    {
        i++;
    }

    return i < letras.nLetras;
}

void rellenarLetrasPatron(const string &patron, TDatos &datos)
{
    datos.nLetras = 0;

    for (int i = 0; i < int(patron.size()); i++)
    {
        if (!esta_letra(patron[i], datos))
        {
            datos.letras[datos.nLetras].letra = patron[i];
            datos.letras[datos.nLetras].lista_palabras.nPalabras = 0;
            datos.nLetras++;
        }
    }
}

bool contieneLetra(const string &palabra, char letra)
{
    int i = 0;

    while (i < int(palabra.size()) && palabra[i] != letra)
    {
        i++;
    }

    return i < int(palabra.size());
}

bool estaPalabra(const string &palabra, const TPalabrasConLetras &palabras)
{
    int i = 0;

    while (i < palabras.nPalabras && palabra != palabras.palabras[i])
    {
        i++;
    }

    return i < palabras.nPalabras;
}

void procesarPalabra(const string &palabra, TDatos &datos)
{
    for (int i = 0; i < datos.nLetras; i++)
    {
        if (contieneLetra(palabra, datos.letras[i].letra) && !estaPalabra(palabra, datos.letras[i].lista_palabras))
        {
            datos.letras[i].lista_palabras.palabras[datos.letras[i].lista_palabras.nPalabras] = palabra;
            datos.letras[i].lista_palabras.nPalabras++;
        }
    }
}

void escribirDatosPorLetra(const TPalabras &datosPorLetra)
{
    cout << datosPorLetra.letra << " ";
    for (int i = 0; i < datosPorLetra.lista_palabras.nPalabras; i++)
    {
        cout << datosPorLetra.lista_palabras.palabras[i] << " ";
    }
    cout << endl;
}

void escribirDatos(const TDatos &datos)
{
    cout << "\nPalabras que comparten letra con las letras del patron: " << endl;

    for (int i = 0; i < datos.nLetras; i++)
    {
        escribirDatosPorLetra(datos.letras[i]);
    }
}

int main()
{
    TDatos datos;
    string patron, palabra;

    do
    {
        cout << "Introduce un patron (longitud maxima = " << MAX_CAR_PATRON << " ): ";
        cin >> patron;
    } while (int(patron.size()) > MAX_CAR_PATRON);

    rellenarLetrasPatron(patron, datos);

    cout << "Introduce un texto (FIN para terminar): ";
    cin >> palabra;

    while (palabra != "FIN")
    {
        procesarPalabra(palabra, datos);
        cin >> palabra;
    }

    escribirDatos(datos);

    return 0;
}