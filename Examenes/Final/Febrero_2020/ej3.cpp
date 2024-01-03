#include <iostream>
#include <array>
#include <String>

using namespace std;

const int MAX = 10;

// cada persona tiene un nombre y el gastos gastado
struct TPersona
{
    string nombre;
    double gastos;
};

// cada una de las personas, junto con sus datos, se guardan en el array
typedef array<TPersona, MAX> TArray;

// total de todas las personas, junto con los datos de cada una
struct TDatos
{
    TArray personas;
    int nPersonas;
};

int esta(const string &nombre, const TDatos &datos)
{
    int i = 0;

    while (i < datos.nPersonas && nombre != datos.personas[i].nombre)
    {
        i++;
    }

    return i;
}

void almacenar(TDatos &datos, const TPersona &usuario)
{
    int posicion = esta(usuario.nombre, datos);

    if (posicion < datos.nPersonas)
    {
        datos.personas[posicion].gastos += usuario.gastos;
    }
    else
    {
        datos.personas[datos.nPersonas] = usuario;
        datos.nPersonas++;
    }
}

void leerDatos(TDatos &datos, TPersona &usuario)
{
    datos.nPersonas = 0;

    cout << "Introduzca nombre y gastos (FIN para terminar): " << endl;
    cout << "Nombre: ";
    cin >> usuario.nombre;
    while (usuario.nombre != "FIN")
    {
        cout << "Gastos: ";
        cin >> usuario.gastos;
        almacenar(datos, usuario);
        cout << "Nombre: ";
        cin >> usuario.nombre;
    }
}

void mostrar(const TDatos &datos)
{
    cout << endl;
    for (int i = 0; i < datos.nPersonas; i++)
    {
        cout << datos.personas[i].nombre << " ha gastado en comun " << datos.personas[i].gastos << endl;
    }
}

double calcularMedia(const TDatos &datos)
{
    double suma = 0;

    for (int i = 0; i < datos.nPersonas; i++)
    {
        suma += datos.personas[i].gastos;
    }

    return suma / datos.nPersonas;
}

void calcularYMostrarPagosRecibos(const TDatos &datos, double media)
{
    double diferencia = 0;

    for (int i = 0; i < datos.nPersonas; i++)
    {
        diferencia = datos.personas[i].gastos - media;
        if (diferencia == 0)
        {
            cout << datos.personas[i].nombre << " esta a la par" << endl;
        }
        else if (diferencia < 0)
        {
            cout << datos.personas[i].nombre << " debe pagar " << -diferencia << endl;
        }
        else
        {
            cout << datos.personas[i].nombre << " debe recibir " << diferencia << endl;
        }
    }
}

bool gastosAjustado(const TDatos &datos, double media)
{
    int i = 0;

    while (i < datos.nPersonas && media - 0.01 <= datos.personas[i].gastos && datos.personas[i].gastos <= media + 0.01)
    {
        i++;
    }

    return i >= datos.nPersonas;
}

// posPersPagarMas sera la posicion de la persona con menos gastos
// posPersRecibirMas sera la posicion de la persona con mas gastos
void encontrarPosiciones(const TDatos &datos, int &posPersonaPagarMas, int &posPersonaRecibirMas)
{
    posPersonaPagarMas = 0;
    posPersonaRecibirMas = 0;

    for (int i = 0; i < datos.nPersonas; i++)
    {
        if (datos.personas[i].gastos > datos.personas[posPersonaRecibirMas].gastos)
        {
            posPersonaRecibirMas = i;
        }
        else if (datos.personas[i].gastos < datos.personas[posPersonaPagarMas].gastos)
        {
            posPersonaPagarMas = i;
        }
    }
}

void ajustarCuentasYMostrarPagos(TDatos &datos, double media)
{
    int posPersonaPagarMas, posPersonaRecibirMas;
    double cantidadPagar, cantidadRecibir, transferencia;

    while (!gastosAjustado(datos, media))
    {
        encontrarPosiciones(datos, posPersonaPagarMas, posPersonaRecibirMas);

        cantidadPagar = media - datos.personas[posPersonaPagarMas].gastos;
        cantidadRecibir = datos.personas[posPersonaRecibirMas].gastos - media;

        if (cantidadPagar < cantidadRecibir)
        {
            transferencia = cantidadPagar;
        }
        else
        {
            transferencia = cantidadRecibir;
        }

        cout << datos.personas[posPersonaPagarMas].nombre << " paga " << transferencia << " a " << datos.personas[posPersonaRecibirMas].nombre << endl;
        datos.personas[posPersonaPagarMas].gastos += transferencia;
        datos.personas[posPersonaRecibirMas].gastos -= transferencia;
    }
}

int main()
{
    TDatos datos;
    TPersona usuario;
    double media;

    leerDatos(datos, usuario);
    mostrar(datos);
    media = calcularMedia(datos);
    cout << endl;
    cout << "La media de gastos es comun es " << media << endl;
    cout << endl;
    calcularYMostrarPagosRecibos(datos, media);
    cout << endl;
    ajustarCuentasYMostrarPagos(datos, media);

    return 0;
}