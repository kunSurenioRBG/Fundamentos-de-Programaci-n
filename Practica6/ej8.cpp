/*
Los alumnos de informática desean celebrar una comida un día del presente mes en el que
puedan acudir todos. Se pide realizar un algoritmo que recoja de cada alumno los días que le
vendría bien ir a la comida, e imprima los días concordantes para todos los alumnos o una
indicación de que no hay. Los datos se introducirán por teclado. Primero se introducirá el
número de alumnos que intervienen. Después, por cada alumno se introducirá una única línea
con los números de los días libres separados por espacios (un 0 para terminar). Dos ejemplos
de ejecución:

Numero de alumnos a introducir: 3
Introduzca los dias preferidos por el alumno 1 (introduzca un 0 para
terminar): 3 5 7 15 20 0
Introduzca los dias preferidos por el alumno 2 (introduzca un 0 para
terminar): 4 6 15 18 20 0
Introduzca los dias preferidos por el alumno 3 (introduzca un 0 para
terminar): 15 20 25 0
Los dias comunes son: 15 20
Numero de alumnos a introducir: 2
Introduzca los dias preferidos por el alumno 1 (introduzca un 0 para
terminar): 2 4 7 0
Introduzca los dias preferidos por el alumno 2 (introduzca un 0 para
terminar): 3 8 15 20 0
Los dias comunes son: No hay ningun dia comun
*/

#include <iostream>
#include <array>

using namespace std;

const int MAX_DIAS = 31;
typedef array<int, MAX_DIAS> TAdias;

struct TDias
{
    int tam;
    TAdias dias;
};

const int MAX_ALUM = 20;
typedef array<TDias, MAX_ALUM> TAalumnos;

struct TAlumnos
{
    int num;
    TAalumnos alumnos;
};

const int TMAX = 32;
typedef array<int, TMAX> Tfrec;

bool esValidoDia(int d)
{
    return (d > 0 && d <= 31);
}

bool estaDia(int d, const TDias &ld)
{
    bool ok = false;
    int i = 0;
    while (i < ld.tam && ld.dias[i] != d)
    {
        i++;
    }

    if (i < ld.tam)
    {
        ok = true;
    }
    return ok;
}

void leerDiasAlumnos(TAlumnos &la)
{
    int dia;

    do
    {
        cout << "Numero de alumnos a introducir (MAX " << MAX_ALUM << "): ";
        cin >> la.num;
    } while (la.num < 0 || la.num > 20);

    for (int i = 0; i < la.num; i++)
    {

        cout << "Introduzca los dias preferidos por el alumno " << i + 1 << "  (introduzca un 0 para terminar): ";
        cin >> dia;

        la.alumnos[i].tam = 0;
        while (la.alumnos[i].tam < MAX_DIAS && dia != 0)
        {
            if (esValidoDia(dia) && !estaDia(dia, la.alumnos[i]))
            {
                la.alumnos[i].dias[la.alumnos[i].tam] = dia;
                la.alumnos[i].tam++;
            }
            cin >> dia;
        }
    }
}

void mostrarDias(const TDias &ld)
{
    for (int i = 0; i < ld.tam; i++)
    {
        cout << ld.dias[i] << " ";
    }
    cout << endl;
}

void mostrarDiasAlumnos(const TAlumnos &la)
{
    for (int i = 0; i < la.num; i++)
    {
        cout << "Dias preferidos para el alumno " << i + 1 << ": ";
        mostrarDias(la.alumnos[i]);
    }
    cout << endl;
}

void contarDias(const TAlumnos &la, Tfrec &f)
{
    f = {{}};

    for (int i = 0; i < la.num; i++)
    {
        for (int j = 0; j < la.alumnos[i].tam; j++)
        {
            f[la.alumnos[i].dias[j]]++;
        }
    }
}

void calcular(const TAlumnos &la, TDias &d)
{
    Tfrec f;
    contarDias(la, f);
    d.tam = 0;

    for (int i = 1; i < TMAX; i++)
    {
        if (d.tam < MAX_DIAS && f[i] == la.num)
        {
            d.dias[d.tam] = i;
            d.tam++;
        }
    }
}

int main()
{
    TAlumnos listaAlumnos;
    TDias diasComunes;

    leerDiasAlumnos(listaAlumnos);
    mostrarDiasAlumnos(listaAlumnos);
    calcular(listaAlumnos, diasComunes);

    cout << "Dias comunes: ";
    if (diasComunes.tam > 0)
    {
        mostrarDias(diasComunes);
    }
    else
    {
        cout << "No hay ningun dia comun" << endl;
    }

    return 0;
}
