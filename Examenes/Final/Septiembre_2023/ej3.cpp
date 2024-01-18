#include <iostream>
#include <array>
using namespace std;

const int N = 3;
const int M = 4;

typedef array<int, M> TFilas;
typedef array<TFilas, N> TMatriz;

typedef array<int, N * M> TArray;

struct Reg
{
    TArray arr;
    int tam = 0;
};
void leer(TMatriz &a)
{
    cout << "Introduzca la matriz " << N << "x" << M << " (por filas) :" << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> a[i][j];
        }
    }
}

int contarRepeticiones(const TMatriz &a, int num)
{
    int cont = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (a[i][j] == num)
            {
                cont++;
            }
        }
    }
    return cont - 1;
}

bool esta(const Reg &a, int b)
{
    bool encontrado = false;
    int i = 0;
    while ((!encontrado) && (i < a.tam))
    {
        if(a.arr[i] == b)
        {
            encontrado = true;
        }
        i++;
    }
    return encontrado;
}

void anyadir(const TMatriz &a, Reg &b)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (!esta(b, a[i][j]))
            {
                b.arr[b.tam] = a[i][j];
                b.tam++;
            }
        }
    }
}

//busqueda binaria
void filtrarPorRepeticiones(Reg &a, const TMatriz &mat)
{
    int auxi;
    for (int i = 0; i < a.tam; i++)
    {
        if (contarRepeticiones(mat, a.arr[i]) <= contarRepeticiones(mat, a.arr[i + 1]))
        {
            auxi = a.arr[i];
            a.arr[i] = a.arr[i + 1];
            a.arr[i + 1] = auxi;
        }
    }
}

void mostrar(const Reg &a, int &k)
{
    cout << "Los valores que mas se repiten son: ";
    for (int i = 0; ((i < k) && (i < a.tam)); i++)
    {
        cout << a.arr[i] << " ";
    }
}

int main()
{
    TMatriz a;
    int k;
    Reg rep;

    cout << "Introduzca k: ";
    cin >> k;

    cout << endl;
    leer(a);

    cout << endl;
    anyadir(a, rep);

    filtrarPorRepeticiones(rep, a);

    mostrar(rep, k);
    return 0;
}
