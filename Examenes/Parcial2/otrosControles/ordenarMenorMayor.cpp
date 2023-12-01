#include <iostream>
#include <array>

using namespace std;

const int TAM = 6;

typedef array<int, TAM> TArray;

void leer(TArray &valores)
{
    int valor;

    cout << "Introduce un array de valores (MAX: 6 valores): " << endl;
    for (int i = 0; i < TAM; i++)
    {
        cin >> valor;
        valores[i] = valor;
    }
}

void ordenar(TArray &valores)
{
    int aux;

    for (int i = 0; i < valores.size(); i++)
    {
        for (int j = 0; j < valores.size(); j++)
        {
            if (valores[j] >= valores[i])
            {
                aux = valores[i];
                valores[i] = valores[j];
                valores[j] = aux;
            }
        }
        cout << endl;
    }
}
void escribir(const TArray &valores)
{
    for (int i = 0; i < valores.size(); i++)
    {
        cout << valores[i] << " ";
    }
}

int main()
{
    TArray valores;

    leer(valores);
    cout << "El array antes de ordenarlo: " << endl;
    escribir(valores);

    ordenar(valores);

    cout << "El array despues de ordenarlo: " << endl;
    escribir(valores);

    return 0;
}