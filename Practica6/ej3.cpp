#include <iostream>
#include <array>

using namespace std;

const int TAM = 10;

typedef array<int, TAM> TArray;

int main() {
    TArray frecuencia = {}; // Inicializamos el array de frecuencias a 0

    cout << "Introduzca una secuencia de digitos (negativo termina): ";

    int numero;
    cin >> numero;

    while (numero >= 0) {
        if (numero >= 0 && numero < TAM) {
            frecuencia[numero]++; // Incrementamos la frecuencia del dígito leído
        }

        cin >> numero; // Leemos el próximo número
    }

    cout << "La frecuencia de cada digito es:" << endl;

    // Iteramos sobre el array e imprimimos la frecuencia de cada dígito
    for (int i = 0; i < TAM; i++) {
        cout << i << ": " << frecuencia[i] << endl;
    }

    return 0;
}
