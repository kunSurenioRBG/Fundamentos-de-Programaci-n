/*
Escribe un programa que acepte fechas escritas en el formato numérico y
nos dé la misma
fecha, pero con el mes correspondiente indicado con letras. Utiliza la
estructura de selección
switch. Ejemplo de ejecución (las tres primeas líneas para entrada de
datos y las otras tres
para la salida):
Introduzca dia: 15
Introduzca mes: 2
Introduzca anyo: 1978
Dia: 15
Mes: Febrero
Anyo: 1978
*/
#include <iostream>
using namespace std;
int main()
{
    int dia, mes, anyo;
    cout << "Introduzca dia: " << endl;
    cin >> dia;
    while (dia < 0 || dia > 31)
    {
        cout << "El dia no es valido" << endl;
        cout << "Introduzca dia: " << endl;
        cin >> dia;
    }

    cout << "Introduzca mes: " << endl;
    cin >> mes;
    while (mes < 0 || mes > 12)
    {
        cout << "El mes no es valido" << endl;
        cout << "Introduzca mes: " << endl;
        cin >> mes;
    }

    cout << "Introduzca anyo: " << endl;
    cin >> anyo;
    while (anyo < 0)
    {
        cout << "El anyo no es valido" << endl;
        cout << "Introduzca anyo: " << endl;
        cin >> anyo;
    }

    cout << "Dia: " << dia << endl;
    cout << "Mes: ";
    switch (mes)
    {
    case 1:
        cout << "Enero";
        break;
    case 2:
        cout << "Febrero";
        break;
    case 3:
        cout << "Marzo";
        break;
    case 4:
        cout << "Abril";
        break;
    case 5:
        cout << "Mayo";
        break;
    case 6:
        cout << "Junio";
        break;
    case 7:
        cout << "Julio";
        break;
    case 8:
        cout << "Agosto";
        break;
    case 9:
        cout << "Septiembre";
        break;
    case 10:
        cout << "Octubre";
        break;
    case 11:
        cout << "Noviembre";
        break;
    case 12:
        cout << "Diciembre";
        break;
    }
    cout << "Anyo: " << anyo << endl;
    return 0;
}