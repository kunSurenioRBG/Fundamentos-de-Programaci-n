#include <iostream>

using namespace std;

// Función para calcular el producto de dos números naturales recursivamente
int producto(int x, int y) {
    // Caso base: el producto de cualquier número por 0 es 0
    if (y == 0) {
        return 0;
    }
    // Caso recursivo: x * y = x + x * (y - 1)
    else {
        return x + producto(x, y - 1);
    }
}

int main() {
    // Variables para almacenar los valores de x e y
    int x, y;

    // Solicitar al usuario los valores de x e y
    cout << "Ingrese el valor de x (numero natural): ";
    cin >> x;

    // Verificar que x sea un número natural
    if (x < 0) {
        cout << "Error: x debe ser un numero natural." << endl;
        return 1;
    }

    cout << "Ingrese el valor de y (numero natural): ";
    cin >> y;

    // Verificar que y sea un número natural
    if (y < 0) {
        cout << "Error: y debe ser un numero natural." << endl;
        return 1;
    }

    // Calcular el producto llamando a la función
    int resultado = producto(x, y);

    // Mostrar el resultado por pantalla
    cout << "El resultado de " << x << " * " << y << " es: " << resultado << endl;

    return 0;
}
