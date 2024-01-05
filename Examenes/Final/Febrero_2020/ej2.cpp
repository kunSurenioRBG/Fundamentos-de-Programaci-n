#include <iostream>
#include <array>

using namespace std;
const int N = 3;

typedef array<int, N> TFilas;
typedef array<TFilas, N> TMatriz;

void leerMatriz(TMatriz &matriz)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> matriz[i][j];
        }
    }
}

void imprimirMatriz(const TMatriz &matriz)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}
/*
bool estocastica(const TMatriz &matriz)
{
   bool esEstocastica = true;
   int suma = 0;

   for (int i = 0; i < N; i++)
   {
       while (esEstocastica = true)
       {
           suma = 0;
           for (int j = 0; j < N; j++)
           {
               suma += matriz[i][j];
           }

           if (suma != 100)
           {
               return esEstocastica = false;
           }
       }
   }

   return esEstocastica;
}
*/

int sumaColumna(const TMatriz &m, int columna)
{
    int suma = 0;

    for (int i = 0; i < N; i++)
    {
        suma += m[i][columna];
    }

    return suma;
}

bool columnasValidas(const TMatriz &m, int valorSuma)
{
    int columna = 0;

    while (columna < N && sumaColumna(m, columna) == valorSuma)
    {
        columna++;
    }

    return columna >= N;
}

bool filaValida(const TFilas &f, int valorSuma)
{
    int columna = 0; 
    int suma = 0;
    bool valoresValidos = true;

    while (columna < N && valoresValidos)
    {
        if (f[columna] < 0 || f[columna] >= 100)
        {
            valoresValidos = false;
        }
        else
        {
            suma += f[columna];
            columna++;
        }
    }

    return valoresValidos && suma == valorSuma; // no haya valores negativos y la suma sea 100
}

bool filasValidas(const TMatriz &m, int valorSuma)
{
    bool correcta = true;
    int fila = 0;

    // itero con while -> cuanWdo no encuentre una fila valida, correcta = false y dejo de iterar
    while (fila < N && correcta)
    {
        correcta = filaValida(m[fila], valorSuma);
        fila++;
    }

    return correcta;
}

bool esEstocastica(const TMatriz &matriz)
{
    // en filasValidas hago la comprobacion de que los valores (no haya negativos) son correctos. No vuelvo a repetir en columnasValidas
    return filasValidas(matriz, 100) && columnasValidas(matriz, 100);
}

int main()
{
    TMatriz matriz = {{}}; // inicializada a 0

    cout << "Introduce los numeros enteros para una matriz cuadrada de " << N << "x" << N << ":" << endl;
    leerMatriz(matriz);

    cout << "La matriz introducida es: " << endl;
    imprimirMatriz(matriz);

    if (esEstocastica(matriz))
    {
        cout << "La matriz introducida SI es doblemente estocastica normalizada";
    }
    else
    {
        cout << "La matriz introducida NO es doblemente estocastica normalizada";
    }

    return 0;
}