/*
 * ejercicio1.cpp
 *
 *  Nombre;
 *  Numero PC:
 */

#include <iostream>
#include <array>

using namespace std;

const int N = 4;
const int M = 5;
typedef array<int, M> TFila;
typedef array<TFila, N> TMatriz;

bool sonFilasEspejo(const TFila &f1, const TFila &f2)
{
    int co = 0;

    while (co < M && f1[co] == f2[M - 1 - co])
    {
        co++;
    }

    return co >= M;
}

bool sonEspejo(const TMatriz &m1, const TMatriz &m2)
{
    int fi = 0;

    while (fi < N && sonFilasEspejo(m1[fi], m2[fi]))
    {
        fi++;
    }

    return fi >= N;
}

int main()
{
    TMatriz m1 = {{{{1, 2, 3, 4, 5}},
                   {{6, 7, 8, 9, 10}},
                   {{11, 12, 13, 14, 15}},
                   {{16, 17, 18, 19, 20}}}};

    TMatriz m2 = {{{{5, 4, 3, 2, 1}},
                   {{10, 9, 8, 7, 6}},
                   {{15, 14, 13, 12, 11}},
                   {{20, 19, 18, 17, 16}}}};

    TMatriz m3 = {{{{5, 4, 3, 2, 1}},
                   {{10, 9, 8, 7, 6}},
                   {{15, 14, 13, 12, 11}},
                   {{20, 1, 18, 17, 16}}}};

    if (sonEspejo(m1, m2))
    {
        cout << "Las matrices son espejo una de la otra" << endl;
    }
    else
    {
        cout << "Las matrices no son espejo una de la otra" << endl;
    }

    if (sonEspejo(m1, m3))
    {
        cout << "Las matrices son espejo una de la otra" << endl;
    }
    else
    {
        cout << "Las matrices no son espejo una de la otra" << endl;
    }
}
