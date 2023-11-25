#include <iostream>
#include <cmath>
#include <array>

using namespace std;

const int MAX = 100;

typedef array<bool, MAX + 1> BoolArray;

void eratostenes(int N) {
    if (N <= 0 || N > MAX) {
        cout << "Ingrese un valor válido para N (mayor que 0 y menor o igual que " << MAX << ")." << endl;
        return;
    }

    BoolArray esPrimo;
    esPrimo.fill(true); // Inicializar todos los números como primos

    esPrimo[0] = esPrimo[1] = false; // 0 y 1 no son primos

    int limite = static_cast<int>(sqrt(N));

    for (int i = 2; i <= limite; i++) {
        if (esPrimo[i]) {
            for (int j = i * i; j <= N; j += i) {
                esPrimo[j] = false; // Tachar los múltiplos de i
            }
        }
    }

    cout << "Los numeros primos menores o iguales que " << N << " son:" << endl;
    for (int i = 2; i <= N; i++) {
        if (esPrimo[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int limite;

    cout << "Introduzca el limite para calcular los primos (> 0 y <= " << MAX << "): ";
    cin >> limite;

    eratostenes(limite);

    return 0;
}
