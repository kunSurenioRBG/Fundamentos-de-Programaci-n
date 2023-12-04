/*
Consideremos un vector V que contiene N valores naturales (array de naturales de tamaño N,
siendo N una constante cualquiera). Definimos el centro c del vector V como el índice entre 1 y
N-2 que verifica la siguiente propiedad:

(no se muestra por vscode)

Esta propiedad no siempre se verifica; en ese caso, decimos que el vector no tiene centro.
Diseña un procedimiento centroVector que reciba como parámetro un vector V y nos
devuelva dos valores como parámetros: el primero indica si existe o no el centro del vector, y el
segundo, indica el índice en el que se encuentra el centro en caso de existir. Diseña la función
principal (main) para probar el funcionamiento del procedimiento.
A continuación, se detallan dos ejemplos (suponemos que N = 5):
1
er Ejemplo:
El contenido del vector es: 6 2 3 0 1
El centro de este vector es el índice 1 (casilla donde está el 2) ya que
al calcular los sumatorios:
- Sumatorio izquierda: (1-0)*V[0] = 1*6 = 6
- Sumatorio derecha: (2-1)*V[2]+(3-1)*V[3]+(4-1)*V[4] = 1*3+2*0+3*1 = 6
2º Ejemplo:
El contenido del vector es: 1 2 1 1 0
Este vector no tiene centro
*/

#include <iostream>
#include <array>
using namespace std;
const int N = 5;
typedef array<int, N> TVector;
// Otra opción es usar abs de <cmath>
int valorAbsoluto(int v)
{
    int res;
    if (v < 0)
    {
        res = -v;
    }
    else
    {
        res = v;
    }
    return res;
    // return (v < 0) ? -v : v;
}
// Otra opción es hacerlo con dos funciones, una para cada sumatorio
int sumaPesos(const TVector &v, int inicio, int fin, int centro)
{
    int suma = 0;
    for (int i = inicio; i <= fin; i++)
    {
        suma = suma + valorAbsoluto(centro - i) * v[i];
    }
    return suma;
}

void centroVector(const TVector &v, bool &existe, int &centro)
{
    existe = false;
    centro = 1;
    while (centro <= N - 2 && !existe)
    {
        if (sumaPesos(v, 0, centro - 1, centro) == sumaPesos(v, centro + 1, N - 1, centro))
        {
            existe = true;
        }
        else
        {
            centro++;
        }
    }
}
void leer(TVector &v)
{
    cout << "Introduzca " << N << " numeros naturales: " << endl;
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
}
int main()
{
    TVector v;
    bool existe;
    int centro;
    leer(v);
    centroVector(v, existe, centro);
    if (existe)
    {
        cout << "El centro de este vector es el indice " << centro << endl;
    }
    else
    {
        cout << "Este vector no tiene centro " << endl;
    }
}