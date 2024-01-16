#include <iostream>
#include <array>

using namespace std;

const int TAM = 7;

typedef array<int, TAM> TFilas;
typedef array<TFilas, TAM> TMatriz;

void inicializar(TMatriz &pascal)
{
    for (int i = 0; i < TAM; i++)
    {
        pascal[0][i] = 1;
        pascal[i][0] = 1;
    }
}

void construir(TMatriz &pascal)
{
    inicializar(pascal);

    for (int i = 1; i < TAM - 1; i++)
    {
        for (int j = 1; j < TAM - 1; j++)
        {
            pascal[i][j] = pascal[i - 1][j] + pascal[i][j - 1];
        }
    }
}

void escribir(const TMatriz &pascal)
{
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM - i; j++)
        {
            cout << pascal[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    TMatriz pascal = {{}}; // rellenar matriz a 0

    construir(pascal);
    escribir(pascal);

    return 0;
}
