#include <iostream>
using namespace std;

int main()
{
    char l;
    int cont = 0;

    cout << "Dame secuencia de caracteres (. para terminar): ";
    cin >> l;

    while (l != '.')
    {
        if (l != ',')
        {
            cont++;
        }
        else
        {
            cout << cont << " ";
            cont = 0;
        }

        cin >> l;
    }

    cout << cont << endl;
}