#include <iostream>
using namespace std;
int main()
{
    int op1, op2;
    char op;
    cout << "Operacion: ";
    cin >> op;
    while (op != '&')
    {
        if (op != '+' && op != '-' && op != '*' && op != '/')
        {
            // cout << "ERROR. Operacion no valida." << endl;
            throw "Error: Operacion no existente";
        }
        else
        {
            cout << "Operando 1: ";
            cin >> op1;
            cout << "Operando 2: ";
            cin >> op2;
            switch (op)
            {
            case '+':
                cout << "Resultado: " << op1 + op2 << endl;
                break;
            case '-':
                cout << "Resultado: " << op1 - op2 << endl;
                break;
            case '*':
                cout << "Resultado: " << op1 * op2 << endl;
                break;
            case '/':
                if (op2 == 0)
                {
                    // cout << "Error. Operando no valido." << endl;
                    throw "Error: Divisor 0";
                }
                else
                {
                    cout << "Resultado: " << op1 / op2 << endl;
                }
                break;
            }
        }
        cout << "Operacion: ";
        cin >> op;
    }
    cout << "FIN DEL PROGRAMA";
    return 0;
}
