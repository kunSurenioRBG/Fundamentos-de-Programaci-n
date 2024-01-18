#include <iostream>
#include <array>

using namespace std;

const int FILAS = 7;
const int COLUMNAS = 12;

typedef array<char, COLUMNAS> TFila;
typedef array<TFila, FILAS> TMatriz;

// Función para calcular el cuadrado de un número
int cuadrado(int x)
{
    return x * x;
}

// Función para calcular el diámetro de la figura en la matriz
double diametro(const TMatriz &matriz)
{
    pair<int, int> punto1, punto2;
    int maxDistanciaCuadrado = 0;

    for (int i = 0; i < FILAS; ++i)
    {
        for (int j = 0; j < COLUMNAS; ++j)
        {
            if (matriz[i][j] == '*')
            {
                for (int x = i; x < FILAS; ++x)
                {
                    for (int y = j; y < COLUMNAS; ++y)
                    {
                        if (matriz[x][y] == '*')
                        {
                            int distanciaCuadrado = cuadrado(i - x) + cuadrado(j - y);
                            if (distanciaCuadrado > maxDistanciaCuadrado)
                            {
                                maxDistanciaCuadrado = distanciaCuadrado;
                                punto1 = {i, j};
                                punto2 = {x, y};
                            }
                        }
                    }
                }
            }
        }
    }

    cout << "Puntos extremos: (" << punto1.first << ", " << punto1.second << ") y (" << punto2.first << ", " << punto2.second << ")" << endl;

    
    return maxDistanciaCuadrado;
}

int main()
{
    // Dadas estas dos matrices, el ejercicio consiste en hallar sus diametros
    TMatriz imagen1 = {{
        {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}},
        {{' ', ' ', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}},
        {{' ', '*', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' '}},
        {{'*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' '}},
        {{'*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' '}},
        {{' ', '*', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' '}},
        {{' ', ' ', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}},
    }};
    TMatriz imagen2 = {{
        {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}},
        {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}},
        {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}},
        {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}},
        {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' '}},
        {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', '*', ' '}},
        {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' '}},
    }};

    cout << "Diametro circunferencia1: " << diametro(imagen1) << endl;

    cout << "Diametro circunferencia2: " << diametro(imagen2) << endl;

    return 0;
}