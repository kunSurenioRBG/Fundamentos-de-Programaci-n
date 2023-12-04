#include <iostream>
#include <array>
using namespace std;
const int MAX = 10;
typedef array<int, MAX> TArray;
struct TLista
{
    TArray elementos;
    int numElem;
};
void leerDatos(TLista &lista, int &repeticiones)
{
    int num;
    int cantidad;
    do
    {
        cout << "Cuantos numeros desea introducir (maximo " << MAX << "): ";
        cin >> cantidad;
    } while (cantidad <= 0 || cantidad > MAX);
    cout << "Introduzca " << cantidad << " numeros: ";
    lista.numElem = 0;
    for (int cont = 1; cont <= cantidad; cont++)
    {
        cin >> num;
        lista.elementos[lista.numElem] = num;
        lista.numElem++;
    }
    cout << "Introduzca el numero de repeticiones para realizar la criba: ";
    cin >> repeticiones;
}
void escribir(const TLista &lista)
{
    cout << "La lista cribada es: ";
    for (int i = 0; i < lista.numElem; i++)
    {
        cout << lista.elementos[i] << " ";
    }
}

bool esta(int elem, const TLista &lista)
{
    int cont = 0;
    while ((cont < lista.numElem) && (elem != lista.elementos[cont]))
    {
        cont++;
    }
    return (cont < lista.numElem);
}
int repeticiones(int elem, const TLista &lista)
{
    int res = 0;
    for (int i = 0; i < lista.numElem; i++)
    {
        if (elem == lista.elementos[i])
        {
            res++;
        }
    }
    return res;
}

void criba(int x, const TLista &lista1, TLista &lista2)
{
    lista2.numElem = 0;
    for (int i = 0; i < lista1.numElem; i++)
    {
        if ((repeticiones(lista1.elementos[i], lista1) == x) && (!esta(lista1.elementos[i], lista2)))
        {
            lista2.elementos[lista2.numElem] = lista1.elementos[i];
            lista2.numElem++;
        }
    }
}

int main()
{
    TLista lista1, lista2;
    int repeticiones;
    leerDatos(lista1, repeticiones);
    criba(repeticiones, lista1, lista2);
    escribir(lista2);
    return 0;
}
