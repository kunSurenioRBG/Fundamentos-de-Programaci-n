#include <iostream>
#include <array>

using namespace std;

const int N = 4;
const int M = 3;

typedef array<int, M> TFilas;
typedef array<TFilas, N> TMatriz;

void leer(TMatriz &a)
{
    cout << "Introduzca la matriz (" << N << "x" << M << "):\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> a[i][j];
        }
    }
}

bool celdaValida(int fila, int columna)
{
    return fila >= 0 && fila < N && columna >= 0 && columna < M;
}

int media(int i, int j, const TMatriz &a)
{
    int suma = 0;
    int vecinos = 0;

    for (int fila = i - 1; fila <= i + 1; fila++)
    {
        for (int columna = j - 1; columna <= j + 1; columna++)
        {
            if (celdaValida(fila, columna))
            {
                vecinos++;
                suma += a[fila][columna];
            }
        }
    }

    return suma / vecinos;
}

void suavizado(const TMatriz &a, TMatriz &b)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            b[i][j] = media(i, j, a);
        }
    }
}

void escribir(const TMatriz &b)
{
    cout << "La matriz suavizada es: \n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << b[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main()
{
    TMatriz a, b;

    leer(a);
    suavizado(a, b);
    escribir(b);

    return 0;
}