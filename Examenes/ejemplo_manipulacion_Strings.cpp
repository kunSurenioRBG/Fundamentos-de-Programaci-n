// 1. BUCLE PARA LEER PALABRAS HASTA LEER "fin"
// 2. CONTAR PALABRAS INTRODUCIDAS E INDICARLO AL FINAL
// 3. 1ª Y ULTIMA LETRA DE CADA PALABRA
// 4. CANTIDAD VOCALES Y NUM CONSONANTES DE UNA PALABRA
// 6. INVERTIR CADA PALABRA LEIDA
// 5. OCULTAR CONSONANTES (CON *)

#include <iostream>
#include <string> // también se incluye desde iostream, no haría falta incluirlo aquí expresamente
// (lo ponemos para dejar claro que se usan strings)
#include <cctype> // para poder usar tolower(), toupper(), ...
using namespace std;

//-----------4
// FUNC QUE RECIBA UN string Y ME DEVUELVA (EN 2 PARAM. DE SALIDA) SU NUMERO DE vocales Y DE consonantes:
void contar_voc_y_cons(string s, int &nv, int &nc)
{
    char c;
    nv = nc = 0;
    for (int i = 0; i < s.size(); i++)
    {
        c = tolower(s[i]); // tolower() devuelve (con return) el carácter que recibe, pero en minúsculas.
        // toupper() en mayúsculas.
        if (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u')
        {
            nv++;
        }
        else if (c >= 'a' and c <= 'z')
        {
            nc++;
        }
    }
}

//-----------5
// MODIFICAR UN string CAMBIANDO SUS VOCALES POR ASTERISCOS
void ocultar_vocales(string &s)
{
    char c;
    for (int i = 0; i < s.size(); i++)
    {
        c = tolower(s[i]);
        if (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u')
        {
            s[i] = '*';
        }
    }
}

//-----------6.a
// INVERTIR UN string (A DEVOLVER COMO VALOR DE RETORNO, PERO SIN MODIF EL ORIGINAL)
// FORMA 1: Comenzando con la cadena vacía (""), y concatenándole (con el +) caracteres por el final

// INVERTIR UN string (A DEVOLVER COMO VALOR DE RETORNO, PERO SIN MODIF EL ORIGINAL)
// FORMA 1: Comenzando con la cadena vacía (""), y concatenándole (con el +) caracteres por el final
string invertir(string original)
{
    string invertida = "";
    for (int d = original.size() - 1; d >= 0; d--)
    {
        invertida = invertida + original[d];
    }
    return invertida;
}

//-----------6.b
// FORMA 2: Creamos otro 2º string con las mismas casillas que el 1º (el original),
// y vamos guardando cada carácter del 1º string (comenzando por su final)
// en la casilla adecuada del 2º (comenzando por su 1ª casilla)
// IMPORTANTE: Podemos hacerlo porque el array donde queremos ir escribiendo
// ya tiene reservado inicialmente el espacio al que queremos acceder con un índice
string invertir2(string original)
{
    string invertida = original;
    int i = 0;
    for (int d = original.size() - 1; d >= 0; d--)
    {
        invertida[i] = original[d];
        i++;
    }
    return invertida;
}

//-------
int main()
{
    string palabra;
    int npalabras, nvocales, nconsonantes;

    npalabras = 0;
    cout << "INTRO PALABRA (fin PARA TERMINAR): ";
    cin >> palabra;
    while (palabra != "fin")
    {
        //--- 2+3
        npalabras++;
        cout << " INICIAL DE LA PALABRA ORIGINAL= " << palabra[0] << endl;
        cout << " ULTIMO CARÁCTER DE LA PALABRA ORIGINAL= " << palabra[palabra.size() - 1] << endl;

        //---4
        contar_voc_y_cons(palabra, nvocales, nconsonantes);
        cout << "NUM. VOCALES = " << nvocales << endl;
        cout << "NUM. CONSONANTES = " << nconsonantes << endl;
        //---5
        ocultar_vocales(palabra); // LA palabra QUEDA MODIFICADA POR LA FUNCIÓN
        cout << "PALABRA CON SUS VOCALES CAMBIADAS POR '*' = " << palabra << endl;
        //---6
        cout << "PALABRA INVERTIDA = " << invertir2(palabra) << endl;

        // LEER OTRA palabra
        cout << "INTRO PALABRA (fin PARA TERMINAR): ";
        cin >> palabra;
    }

    cout << "NUM PALABRAS = " << npalabras;
    return 0;
}
