#include <iostream>
#include <array>

using namespace std;

const int TAM = 10;
typedef array<int, TAM> TArray;

struct Vector
{
    TArray valores;
    int nElem;
};

void leer(Vector &vector)
{
    int num;

    cout << "Introduzca una secuencia de numeros enteros (0 para terminar y como maximo 10 numeros):";
    vector.nElem = 0;

    cin >> num;
    while (num != 0)
    {
        if (vector.nElem < TAM)
        {
            vector.valores[vector.nElem] = num;
            vector.nElem++;
        }
        cin >> num;
    }
}

int buscar(int valor, const Vector &vector)
{
    int i = 0;

    while ((i < vector.nElem) && vector.valores[i] != valor)
    {
        i++;
    }

    return i;
}

//***************************************************************************
//*********NO ORDENADOS*********
//***************************************************************************

void borrar(int valor, Vector &vector)
{
    int pos = buscar(valor, vector);

    if (pos < vector.nElem)
    {
        vector.valores[pos] = vector.valores[vector.nElem - 1];
        vector.nElem--;
    }
}

void insertar(int valor, Vector &vector)
{
    if (vector.nElem < TAM)
    {
        vector.valores[vector.nElem] = valor;
        vector.nElem++;
    }
}

//***************************************************************************
//***************************************************************************
/*

//***************************************************************************
//*********ORDENADOS*********
//***************************************************************************

void borrar(int valor, Vector &vector)
{
    int pos = buscar(valor, vector);

    // recolocar valores
    if (pos < vector.nElem)
    {
        for (int i = pos; i < vector.nElem - 1; i++) // -1 por el 0 del final
        {
            vector.valores[i] = vector.valores[i + 1];
        }
        vector.nElem--;
    }
}

int posicion(int valor, const Vector &vector)
{
    int i = 0;
    while ((i < vector.nElem) && (valor > vector.valores[i]))
    {
        i++;
    }
    return i;
}

void insertar(int num, Vector &vector)
{
    int pos;
    if (vector.nElem < TAM)
    {
        pos = posicion(num, vector);
        for (int i = vector.nElem; i > pos; i--)
        {
            vector.valores[i] = vector.valores[i - 1];
        }
        vector.valores[pos] = num;
        vector.nElem++;
    }
}

//***************************************************************************
//***************************************************************************
*/
void escribir(const Vector &vector)
{
    for (int i = 0; i < vector.nElem; i++)
    {
        cout << vector.valores[i] << " ";
    }
    cout << endl;
}

int main()
{
    Vector vector;
    int valor;

    leer(vector);

    cout << "Introduzca un numero entero a borrar del vector: ";
    cin >> valor;

    borrar(valor, vector);

    cout << "El vector despues de borrar es: ";
    escribir(vector);

    cout << "Introduzca un numero entero a insertar en el vector: ";
    cin >> valor;

    insertar(valor, vector);

    cout << "El vector despues de insertar es: ";
    escribir(vector);

    return 0;
}

/*
bool esPrimo(int numero) {
    if (numero <= 1) {
        return false;
    }

    // Verificar divisibilidad por números desde 2 hasta la raíz cuadrada del número
    for (int i = 2; i * i <= numero; ++i) {
        if (numero % i == 0) {
            return false;
        }
    }

    return true;
}
*/