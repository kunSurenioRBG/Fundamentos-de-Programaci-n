#include <iostream>

using namespace std;

// Procedimiento recursivo para imprimir el valor en binario de un número decimal
void decimalAbinario(int n) {
    // Caso base: si n es 0, no hay más dígitos binarios para imprimir
    if (n == 0) {
        return;
    }

    // Llamar recursivamente con el cociente de n dividido por 2
    decimalAbinario(n / 2);

    // Imprimir el residuo de n dividido por 2 (el dígito binario)
    cout << n % 2;
}

int main() {
    // Variable para almacenar el valor de n
    int n;

    // Solicitar al usuario el valor de n
    cout << "Ingrese un numero natural: ";
    cin >> n;

    // Verificar que n sea un número natural
    if (n < 0) {
        cout << "Error: n debe ser un numero natural." << endl;
        return 1;
    }

    // Imprimir el valor en binario llamando al procedimiento
    cout << "El valor binario de " << n << " es: ";
    decimalAbinario(n);
    cout << endl;

    return 0;
}
