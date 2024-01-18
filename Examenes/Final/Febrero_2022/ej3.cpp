#include <iostream>
#include <array>

using namespace std;

const int filas = 2;
const int columnas = 3;

typedef array<int, columnas> TFilas;
typedef array<TFilas, filas> TMatrizM;
typedef array<TFilas, 2 * filas> TMatrizT;

void leerMatriz(TMatrizM &m)
{
    cout << "Introduzca la matriz M (" << filas << "x" << columnas << "):\n";
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            cin >> m[i][j];
        }
    }
}

int mediaMatriz(const TMatrizM &m)
{
    int suma = 0, valores = 0;

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            suma += m[i][j];
            valores++;
        }
    }

    return suma / valores;
    // return suma / (fila*columna);
}

void copiarFilasPares(const TMatrizM &m1, TMatrizT &m2)
{
    for (int i = 0; i < filas; i++)
    {
        m2[i * 2] = m1[i];
    }
}

bool celdaValida(int fila, int columna)
{
    return fila >= 0 && fila < 2 * filas && columna >= 0 && columna < columnas;
}

int mediaVecinos(int i, int j, const TMatrizT &m2, int media)
{
    int suma = 0, vecinos = 0;

    for (int fila = i - 1; fila <= i + 1; fila++)
    {
        for (int columna = j - 1; columna <= j + 1; columna++)
        {
            if (celdaValida(fila, columna) && !(fila == i && columna == j))
            {
                vecinos++;
                if (m2[fila][columna] == 0)
                {
                    suma += media;
                }
                else
                {
                    suma += m2[fila][columna];
                }
            }
        }
    }

    return suma / vecinos;
}

void calcularFilaImpar(int i, TMatrizT &m2, int media)
{
    for (int j = 0; j < columnas; j++)
    {
        m2[i][j] = mediaVecinos(i, j, m2, media);
    }
}

void calcularFilasImpares(TMatrizT &m2, int media)
{
    for (int i = 1; i < 2 * filas; i += 2)
    {
        calcularFilaImpar(i, m2, media);
    }
}

void construirMatrizT(const TMatrizM &m1, TMatrizT &m2)
{
    int mediaM = mediaMatriz(m1);

    copiarFilasPares(m1, m2);

    calcularFilasImpares(m2, mediaM);
}

void escribir(const TMatrizT &m2)
{
    cout << "La matriz T (" << 2 * filas << "x" << columnas << ") es la siguiente:\n";
    for (int i = 0; i < 2 * filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            cout << m2[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    TMatrizM m1;
    TMatrizT m2 = {{}};

    leerMatriz(m1);
    construirMatrizT(m1, m2);
    escribir(m2);

    return 0;
}