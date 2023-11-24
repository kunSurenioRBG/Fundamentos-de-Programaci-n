#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    int prov = 0;
    int op = 0;
    int cont = 0;
    cout << "Introduzca un numero de 4 digitos (el primero distinto de cero): ";
    cin >> n;
    if (n > 9999 || n < 1000)
    {
        cout << "ERROR: CODIGO INVALIDO (no tiene 4 digitos)";
    }
    else
    {
        prov = n / 1000;
        op = (n - prov * 1000) / 10;
        cont = (n - prov * 1000 - op * 10);
        if (cont != op % prov)
        {
            cout << "ERROR: CODIGO INVALIDO (digito de control erroneo)";
        }
        else
        {
            cout << "PROVINCIA " << prov << endl;
            cout << "NUMERO DE OPERACION " << op << endl;
            cout << " DIGITO DE CONTROL " << cont;
        }
    }
    return 0;
}