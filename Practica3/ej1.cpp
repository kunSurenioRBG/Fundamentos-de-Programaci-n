#include <iostream>
using namespace std;

int main()
{
    double nota, sumaNotas, aprobados, suspensos;
    double mejor, peor;
    int cantidadNotas;
    double totalMedia;
    char repetir;

    do
    {
        aprobados = 0;
        suspensos = 0;
        cantidadNotas = 0;
        mejor = 0;
        peor = 10;

        cout << "Introduce una nota (negativa para terminar): ";
        cin >> nota;

        while (nota >= 0)
        {
            if (nota <= 10)
            {
                sumaNotas += nota;
                cantidadNotas++;

                if (nota >= 5.0)
                {
                    aprobados++;
                }
                else
                {
                    suspensos++;
                }

                if (nota > mejor)
                {
                    mejor = nota;
                }

                if (nota < peor)
                {
                    peor = nota;
                }
            }
            cin >> nota; // leemos siguiente nota
        }

        totalMedia = sumaNotas / cantidadNotas;

        if (cantidadNotas > 0)
        {
            cout << "\n APROBADOS=" << aprobados << "\n SUSPENSOS=" << suspensos;
            cout << "\n NOTA MEDIA=" << totalMedia;
            cout << "\n MEJOR NOTA=" << mejor << "\n PEOR NOTA=" << peor << endl;
        }
        else
        {
            cout << "NO HAS INTRODUCIDO NINGUNA NOTA CORRECTA " << endl;
            cout << "REPETIR (S/N): ";
            cin >> repetir;
        }
    } while (repetir == 'S');

    return 0;
}
