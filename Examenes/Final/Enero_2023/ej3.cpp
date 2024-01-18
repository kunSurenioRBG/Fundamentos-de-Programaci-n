#include <iostream>
#include <array>

using namespace std;

const int TAM = 9;

typedef array<int, TAM> TFila;
typedef array<TFila, TAM> TMatriz;

struct Numeros
{
    int nelms = 0;
    TFila elms;
};

void anadirNumero(int numero, Numeros &n)
{
    if (n.nelms < int(n.elms.size()))
    {
        n.elms[n.nelms] = numero;
        n.nelms++;
    }
}
int buscarPosicion(int numero, const Numeros &n)
{
    int pos = -1;
    bool encontrado = false;
    for (int i = 0; i < n.nelms && !encontrado; i++)
    {
        if (n.elms[i] == numero)
        {
            pos = i;
            encontrado = true;
        }
    }
    return pos;
}
void procesarNumero(int numero, Numeros &n, bool &comprobante)
{
    if (numero != 0)
    {
        int pos = buscarPosicion(numero, n);
        if (pos < 0)
        {
            anadirNumero(numero, n);
        }
        else
        {
            comprobante = false;
        }
    }
}

bool todosVecinosDistintos(const TMatriz &t, int fila, int columna)
{
    bool resultado = true;
    Numeros n;
    for (int ff = fila - 1; ff <= fila + 1 && resultado; ff++)
    {
        for (int cc = columna - 1; cc <= columna + 1 && resultado; cc++)
        {
            int numero = t[ff][cc];
            procesarNumero(numero, n, resultado);
        }
    }
    return resultado;
}

bool regionesValidas(const TMatriz &t)
{
    bool resultado = true;

    for (int i = 0; i < int(t.size()); i++)
    {
        for (int j = 0; j < int(t.size()); j++)
        {
            resultado = todosVecinosDistintos(t, i, j);
        }
    }

    return resultado;
}

// ---------------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------------

bool todosNumerosDistintosF(const TMatriz &t, int fila)
{
    bool resultado = true;
    Numeros n;
    for (int c = 0; c < int(t[fila].size()) && resultado; c++)
    {
        int numero = t[fila][c];
        procesarNumero(numero, n, resultado);
    }
    return resultado;
}

bool filasValidas(const TMatriz &t)
{
    bool resultado = true;
    for (int f = 0; f < int(t.size()) && resultado; f++)
    {
        resultado = todosNumerosDistintosF(t, f);
    }
    return resultado;
}

// ---------------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------------

bool todosNumerosDistintosC(const TMatriz &t, int columna)
{
    bool resultado = true;
    Numeros n;
    for (int f = 0; f < int(t.size()) && resultado; f++)
    {
        int numero = t[f][columna];
        procesarNumero(numero, n, resultado);
    }
    return resultado;
}

bool columnasValidas(const TMatriz &t)
{
    bool resultado = true;
    for (int c = 0; c < int(t.size()) && resultado; c++)
    {
        resultado = todosNumerosDistintosC(t, c);
    }
    return resultado;
}

// ---------------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------------

bool tableroValido(const TMatriz &t)
{
    return (filasValidas(t) && columnasValidas(t) && regionesValidas(t));
}

int main()
{
    TMatriz tablero1 =
        {{{{5, 3, 0, 0, 7, 0, 0, 0, 0}},
          {{6, 0, 0, 1, 9, 5, 0, 0, 0}},
          {{0, 9, 8, 0, 0, 0, 0, 6, 0}},
          {{8, 0, 0, 0, 6, 0, 0, 0, 3}},
          {{4, 0, 0, 8, 0, 3, 0, 0, 1}},
          {{7, 0, 0, 0, 2, 0, 0, 0, 6}},
          {{0, 6, 0, 0, 0, 0, 2, 8, 0}},
          {{0, 0, 0, 4, 1, 9, 0, 0, 5}},
          {{0, 0, 0, 0, 8, 0, 0, 7, 9}}}};
    TMatriz tablero2 =
        {{{{5, 3, 0, 0, 7, 0, 0, 0, 0}},
          {{6, 0, 0, 1, 9, 5, 0, 0, 0}},
          {{0, 9, 8, 0, 0, 0, 0, 6, 0}},
          {{8, 0, 3, 0, 6, 0, 0, 0, 3}},
          {{4, 0, 0, 8, 0, 3, 0, 0, 1}},
          {{7, 0, 0, 0, 2, 0, 0, 0, 6}},
          {{0, 6, 0, 0, 0, 0, 2, 8, 0}},
          {{0, 0, 0, 4, 1, 9, 0, 0, 5}},
          {{0, 0, 0, 0, 8, 0, 0, 7, 9}}}};
    TMatriz tablero3 =
        {{{{5, 3, 0, 0, 7, 0, 0, 0, 0}},
          {{6, 0, 0, 1, 9, 5, 0, 0, 0}},
          {{0, 9, 8, 0, 2, 0, 0, 6, 0}},
          {{8, 0, 0, 0, 6, 0, 0, 0, 3}},
          {{4, 0, 0, 8, 0, 3, 0, 0, 1}},
          {{7, 0, 0, 0, 2, 0, 0, 0, 6}},
          {{0, 6, 0, 0, 0, 0, 2, 8, 0}},
          {{0, 0, 0, 4, 1, 9, 0, 0, 5}},
          {{0, 0, 0, 0, 8, 0, 0, 7, 9}}}};
    TMatriz tablero4 =
        {{{{5, 3, 0, 0, 7, 0, 6, 0, 0}},
          {{6, 0, 0, 1, 9, 5, 0, 0, 0}},
          {{0, 9, 8, 0, 0, 0, 0, 6, 0}},
          {{8, 0, 0, 0, 6, 0, 0, 0, 3}},
          {{4, 0, 0, 8, 0, 3, 0, 0, 1}},
          {{7, 0, 0, 0, 2, 0, 0, 0, 6}},
          {{0, 6, 0, 0, 0, 0, 2, 8, 0}},
          {{0, 0, 0, 4, 1, 9, 0, 0, 5}},
          {{0, 0, 0, 0, 8, 0, 0, 7, 9}}}};
    if (tableroValido(tablero1))
    {
        cout << "El tablero1 es un sudoku VALIDO" << endl;
    }
    else
    {
        cout << "El tablero1 es un sudoku NO VALIDO" << endl;
    }
    if (tableroValido(tablero2))
    {
        cout << "El tablero2 es un sudoku VALIDO" << endl;
    }
    else
    {
        cout << "El tablero2 es un sudoku NO VALIDO" << endl;
    }
    if (tableroValido(tablero3))
    {
        cout << "El tablero3 es un sudoku VALIDO" << endl;
    }
    else
    {
        cout << "El tablero3 es un sudoku NO VALIDO" << endl;
    }
    if (tableroValido(tablero4))
    {
        cout << "El tablero4 es un sudoku VALIDO" << endl;
    }
    else
    {
        cout << "El tablero4 es un sudoku NO VALIDO" << endl;
    }

    return 0;
}