#include <iostream>

using namespace std;

// Procedimiento recursivo para imprimir los dígitos en orden inverso
void inverso(int n) {
    // Caso base: si n es 0, no hay más dígitos para imprimir
    if (n == 0) {
        return;
    }

    // Imprimir el dígito más bajo de n
    cout << n % 10;

    // Llamar recursivamente con el resto de los dígitos
    inverso(n / 10);
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

    // Imprimir los dígitos en orden inverso llamando al procedimiento
    cout << "Los digitos de " << n << " en orden inverso son: ";
    inverso(n);
    cout << endl;

    return 0;
}
