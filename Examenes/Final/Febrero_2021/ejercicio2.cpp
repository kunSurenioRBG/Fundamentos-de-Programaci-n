#include <iostream>

using namespace std;

bool todosDigitos(const string &codigo)
{
    int i = 0;

    while (i < int(codigo.size()) && '0' <= codigo[i] && codigo[i] <= '9')
    {
        i++;
    }

    return i >= int(codigo.size());
}

void leerCodigo(const string &nombre, string &codigo, int tam)
{
    bool correcto = false;
    do
    {
        cout << "\nIntroduzca el codigo del " << nombre << " (digitos: " << tam << "): ";
        cin >> codigo;
        if (tam == int(codigo.size()) && todosDigitos(codigo)) // tamaño correcto y digitos son valores de 0-9
        {
            correcto = true;
        }
        else
        {
            cout << "\nCodigo incorrecto (el numero de digitos debe ser: " << tam << ")\n";
        }

    } while (!correcto);
}

void calcularCodigoControl(string &isbn)
{
    int suma, resto = 0;

    for (int i = 0; i < int(isbn.size()); i++)
    {
        suma += (isbn[i] - '0') * (i + 1);
    }

    resto = suma % 11;

    if (resto == 10)
    {
        isbn += 'X';
    }
    else
    {
        isbn += char(resto + '0');
    }
}

int main()
{
    string cGrupo, cEditor, cLibro, isbn;

    leerCodigo("grupo", cGrupo, 1);
    leerCodigo("editor", cEditor, 4);
    leerCodigo("libro", cLibro, 4);

    isbn = cGrupo + cEditor + cLibro;

    calcularCodigoControl(isbn);

    cout << "\nEl codigo ISBN correspondiente es: " << isbn << endl;

    return 0;
}