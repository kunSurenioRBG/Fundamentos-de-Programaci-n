#include <iostream>
#include <array>

using namespace std;

const int TAM = 10;

typedef array<int, TAM> TArray;

void imprimirHistograma(const TArray &frecuencia) {
    for (int i = 0; i < TAM; i++) {
        cout << i << " ";
        for (int j = 0; j < frecuencia[i]; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

int main() {
    TArray frecuencia = {}; // Inicializamos el array de frecuencias a 0

    cout << "Introduzca una lista de numeros entre 0 y 9 (negativo termina): ";

    int numero;
    cin >> numero;

    while (numero >= 0 && numero < TAM) {
        frecuencia[numero]++; // Incrementamos la frecuencia del número leído
        cin >> numero; // Leemos el próximo número
    }

    cout << "Histograma:" << endl;
    imprimirHistograma(frecuencia);

    return 0;
}
