#include <iostream>
#include <array>

using namespace std;

const int TAM = 10;

typedef array<int, TAM> TArray;

void menorEstricto(const TArray &a, bool &hayME, int &mE) // hayME y mE por referencia, VOY A MODIFICARLOS!!!!
{
    mE = a[0];
    hayME = true;

    for (int i = 0; i < int(a.size()); i++)
    {
        if (a[i] < mE)
        {
            hayME = true;
            mE = a[i];
        }
        else if (a[i] == mE)
        {
            hayME = false;
        }
    }
}

int main()
{
    TArray a1 = {{4, 7, 5, 3, 5, 7, 9, 32, 45, 8}};
    TArray a2 = {{4, 7, 5, 3, 5, 7, 3, 32, 45, 8}};
    TArray a3 = {{4, 7, 5, 3, 5, 7, 3, 32, 2, 8}};

    bool hayME;
    int mE;

    menorEstricto(a1, hayME, mE);

    if (hayME)
    {
        cout << "El menor estricto del primer array es: " << mE << endl;
    }
    else
    {
        cout << "El primer array no tiene menor estricto" << endl;
    }

    menorEstricto(a2, hayME, mE);

    if (hayME)
    {
        cout << "El menor estricto del segundo array es: " << mE << endl;
    }
    else
    {
        cout << "El segundo array no tiene menor estricto" << endl;
    }

    menorEstricto(a3, hayME, mE);

    if (hayME)
    {
        cout << "El menor estricto del tercer array es: " << mE << endl;
    }
    else
    {
        cout << "El tercer array no tiene menor estricto" << endl;
    }

    return 0;
}