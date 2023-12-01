#include <iostream>
#include <array>

const int MAX = 5;

using namespace std;

// Definición del tipo de datos TLista
typedef array<int, MAX> TLista;

// Función para leer una lista desde la entrada estándar
void leerLista(TLista &lista)
{
    int valor;
    int indice = 0;
    
    while (valor != 0)
    {
        cin >> valor;
        if (indice < MAX)
        {
            lista[indice] = valor;
        }
        indice++;
    }
}

// Función para mostrar el contenido de una lista
void mostrarLista(const TLista &lista)
{
    for (int i = 0; i < MAX && lista[i] != 0; ++i)
    {
        cout << lista[i] << " ";
    }
    cout << endl;
}

// Función para verificar si dos listas son encajables
bool sonEncajables(const TLista &lista1, const TLista &lista2)
{
    bool encajables = true;
    int indice1 = 0;
    int indice2 = 0;

    while (lista1[indice1] != 0 && lista2[indice2] != 0)
    {
        // Ignorar elementos negativos
        while (lista1[indice1] < 0)
        {
            ++indice1;
        }
        while (lista2[indice2] < 0)
        {
            ++indice2;
        }

        // Verificar si los elementos positivos coinciden
        if (lista1[indice1] != lista2[indice2])
        {
            encajables = false;
            break;
        }

        ++indice1;
        ++indice2;
    }

    return encajables;
}

int main()
{
    TLista lista1, lista2;
    
    cout << "Introduzca la primera lista (maximo " << MAX << " numeros separados por espacios, finalice con 0):\n";
    leerLista(lista1);
    cout << "Introduzca la segunda lista (maximo " << MAX << " numeros separados por espacios, finalice con 0):\n";
    leerLista(lista2);

    cout << "lista1 = ";
    mostrarLista(lista1);
    cout << "lista2 = ";
    mostrarLista(lista2);

    bool encajables = sonEncajables(lista1, lista2);

    if (encajables)
    {
        cout << "Las listas SI son encajables\n";
    }
    else
    {
        cout << "Las listas NO son encajables\n";
    }

    return 0;
}
