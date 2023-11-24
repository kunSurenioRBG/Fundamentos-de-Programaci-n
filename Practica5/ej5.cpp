#include <iostream>

using namespace std;

// Función recursiva para verificar si un número es primo
bool esPrimoRec(int num, int divisor) {
    // Caso base: si el divisor alcanza el valor de num, entonces num es primo
    if (divisor == num) {
        return true;
    }

    // Si num es divisible por el divisor actual, no es primo
    if (num % divisor == 0) {
        return false;
    }

    // Llamar recursivamente con el siguiente divisor
    return esPrimoRec(num, divisor + 1);
}

int main() {
    // Variable para almacenar el número natural
    int num;

    // Solicitar al usuario el número natural
    cout << "Ingrese un numero natural mayor que 1: ";
    cin >> num;

    // Verificar que num sea un número natural mayor que 1
    if (num <= 1) {
        cout << "Error: El numero debe ser un numero natural mayor que 1." << endl;
        return 1;
    }

    // Llamar a la función para verificar si el número es primo
    bool resultado = esPrimoRec(num, 2);

    // Mostrar el resultado por pantalla
    if (resultado) {
        cout << num << " es un numero primo." << endl;
    } else {
        cout << num << " no es un numero primo." << endl;
    }

    return 0;
}
