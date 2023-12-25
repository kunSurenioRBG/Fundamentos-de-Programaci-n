/*

La NASA desea almacenar la información de los  satélites  (máximo 20) que están desarrollando para enviar a planetas del Sistema Solar (cada satélite estará diseñado para ir a un planeta concreto, y sólo a ese).

De cada satélite se necesita almacenar el código  (string, sin espacios en blanco) que lo identifica, los años de  vida previstos (años que podrá funcionar correctamente), y el número del planeta que será su destino (será valor entre 1 y 9, ambos incluidos, ya que 1:Mercurio, 2:Venus, 3:Tierra,..., 9:Plutón).  Para este problema, consideraremos que Plutón es un planeta, el último del Sistema Solar.

La

                función principal de su programa deberá declarar el correspondiente array de registros, inicializándolo con los siguientes 4 satélites:

    ... = {{  { "SATE1",90,9}, {"SATE2",30,3 },  { "SATE3",20,2},  { "SATE4",30,3 } }};

Después, haga llamadas a las siguientes funciones que se piden, de manera que las pueda probar.

1) Hacer una función, llamada vida_media_satelites()  que, a partir de la información de los satélites, devuelva la media de los años de vida estimada de todos los satelites.

2)  Procedimiento, llamado mostrar_un_satelite(),   para mostrar en pantalla    único satelite  (que reciba como parámetro; o sea, no recibirá todos los satélites, sino sólo uno, el que se quiera mostrar)

2.b)  Modifique el subprograma anterior  para que muestre también el nombre del planeta destino (además del número de planeta).
        Pista: cree un array (de strings) con los nombres de los 9 planetas.


3)  Procedimiento , llamado mostrar_todos_los_satelites() , para mostrar  en pantalla todos los satélites  existentes (haga uso de la función anterior)

4) Hacer un subprograma, llamado  satelites_al_planeta_X(),  que, recibiendo como parámetro todos los satélites, muestre en pantalla el nombre de cada satélite que se pueda enviar al planeta  númeroX (X será otro parámetro de entrada).
Si X valiese 3 (Tierra) , deberán mostrarse los nombres:    SATE2  y  SATE4

5) Definir una función,  llamada  satelite_a_planeta_mas_cercano_sol(),  que,  a partir de todos los satélites, devuelva, como valor de retorno, una estructura con los datos del primer satélite almacenado que se pueda enviar al pl aneta más cercano al sol (o sea,  devolveremos el registro del satélite que tenga el menor  número de planeta como destino; si hay varios con ese menor número, devolver el 1º de ellos que haya en el array).
Para los datos de nuestro array, el satélite devuelto sería el de código: SATE3  cuyo destino es el planeta nº 2  (Venus)

6)  Definir una función, llamada  agregar_satelite () , la cual se encargará de añadir en la siguiente casilla libre del array de satélites (si cabe) , la  información leída por teclado correspondiente a  un nuevo satélite . También deberá devolver un booleano (true o false) que indique si se ha podido insertar o no.
Ayúdese de otra función,  leer_satelite()  que devuelva un registro con los 3 datos, leídos por teclado, de un satélite.
Para probar estas funciones, escriba en  main()  un bucle donde, tras insertar un satélite, se pregunte si se desea o no insertar otro.

7) Hacer otro subprograma, llamado  cuantos_sat_por_planeta() que, a partir de la información de los satélites, devuelva un array que contenga cuántos satélites se  enviarán a cada planeta (es decir, cuántos al planeta 1 (a Mercurio), cuántos al planeta 2, cuántos al 3, ..., y cuántos al 9 (a Plutón)).
PISTA: usar un array de 9 enteros donde almacenar la  frecuencia de aparición de cada posible planeta destino (del 1 al 9)

8)  Función buscar_satelite () que a partir de la lista de satélites y de un código de satélite, devuelva un booleano indicando si dicho satélite se encuentra o no en la lista. En caso afirmativo, devuelva también la posición en que se encuentra.

9)  Subprograma eliminar_satelite () que elimine de la lista de satélites el satélite (si existe ) cuyo código reciba como parámetro.
Haciendo uso de la función anterior , implemente 2 versiones:
- una en la que  no importe el orden resultante de los satélites (por ejemplo, puede colocar el último en el lugar del que hay que borrar, y decrementar la cantidad de satélites existentes)
- y otra versión en la que se respete el orden  en que ya estaban los satélites (por ejemplo, desplazando todos los registros una posición a la izquierda, a partir del que hay que borrar).

Inicializacion Satelite
TRsatelites sats = {{{  { "SATE1",90,9}, {"SATE2",30,3 },  { "SATE3",20,2},  { "SATE4",30,3 } }},
                         4
                        };

*/

#include <iostream>
#include <array>
using namespace std;

typedef struct
{
    string codigo;
    int anios;
    int planeta;

} TRsatelite;

const int MAX_SATELITES = 20;
typedef array<TRsatelite, MAX_SATELITES> TAsatelites;

const int NUM_PLANETAS = 9;
typedef array<int, NUM_PLANETAS> TAfrec;

typedef array<string, 9> TAn_planetas;
TAn_planetas nombres = {{"MERCURIO", "VENUS", "TIERRA", "MARTE", "JUPITER", "SATURNO", "URANO", "NEPTUNO", "PLUTON"}};

typedef struct
{
    TAsatelites arr;
    int tam;
} TRsatelites;

double vida_media_satelites(const TRsatelites &s)
{
    double media = 0;
    double suma = 0;

    for (int i = 0; i < s.tam; i++)
    {
        suma = suma + s.arr[i].anios;
    }

    if (s.tam > 0)
    {
        media = suma / (double)s.tam;
    }

    return media;
}

void mostrar_un_satelite(TRsatelite sat)
{

    cout << "C�digo: " << sat.codigo << endl;
    cout << "Vida: " << sat.anios << endl;
    cout << "Planeta: " << sat.planeta << ": " << nombres[sat.planeta - 1] << endl;
}

void mostrar_todos_los_satelites(const TRsatelites &s)
{
    for (int i = 0; i < s.tam; i++)
    {
        mostrar_un_satelite(s.arr[i]);
    }
}

void satelites_al_planeta_X(const TRsatelites &s, int x)
{
    cout << "Listado de planetas que iran al plante n� " << x << ": " << endl;

    for (int i = 0; i < s.tam; i++)
    {
        if (s.arr[i].planeta == x)
        {
            cout << " " << s.arr[i].codigo << " ";
        }
    }

    cout << endl;
}

void satelite_a_planeta_mas_cercano_sol(const TRsatelites &s, TRsatelite &cercano)
{
    cercano = s.arr[0];

    for (int i = 0; i < s.tam; i++)
    {
        if (s.arr[i].planeta < cercano.planeta)
        {
            cercano = s.arr[i];
        }
    }
}

TRsatelite leer_satelite()
{
    TRsatelite sat;

    cout << "Introduzca el codigo del satelite: ";
    cin >> sat.codigo;
    cout << "Duracion en anios: ";
    cin >> sat.anios;
    cout << "El n� del planeta destino (1 al 9): ";
    cin >> sat.planeta;

    return sat;
}

void leer_satelite_2(TRsatelite &sat)
{
    cout << "Introduzca el codigo del satelite: ";
    cin >> sat.codigo;
    cout << "Duracion en anios: ";
    cin >> sat.anios;

    do
    {
        cout << "El n� del planeta destino (1 al 9): ";
        cin >> sat.planeta;
    } while (sat.planeta < 1 || sat.planeta > NUM_PLANETAS);
}

bool agregar_satelite(TRsatelites &s)
{
    bool insertado = false;

    if (s.tam < MAX_SATELITES)
    {
        TRsatelite sat_nuevo;
        leer_satelite_2(sat_nuevo);

        s.arr[s.tam] = sat_nuevo;
        s.tam++;

        insertado = true;
    }

    return insertado;
}

TAfrec cuantos_sat_por_planeta(const TRsatelites &s)
{
    TAfrec frec;

    for (int i = 0; i < NUM_PLANETAS; i++)
    {
        frec[i] = 0;
    }

    for (int i = 0; i < s.tam; i++)
    {
        frec[s.arr[i].planeta - 1]++;
    }

    return frec;
}

bool buscar_satelite(const TRsatelites &s, string cod, int &pos)
{
    bool encontrado = false;
    pos = -1;

    int i = 0;

    while (i < s.tam && s.arr[i].codigo != cod)
    {
        i++;
    }

    if (i < s.tam)
    {
        pos = i;
        encontrado = true;
    }

    return encontrado;
}

void eliminar_satelite(TRsatelites &s, string cod)
{
    int pos = -1;

    if (buscar_satelite(s, cod, pos))
    {
        s.arr[pos] = s.arr[s.tam - 1];
        s.tam--;
    }
}

int main()
{
    TRsatelites sats = {{{{"SATE1", 90, 9}, {"SATE2", 30, 3}, {"SATE3", 20, 2}, {"SATE4", 30, 3}}},
                        4};
    // int tam_sats=4;

    cout << "Vidas media de los satelites:";
    cout << vida_media_satelites(sats) << endl;

    // mostrar_un_satelite(arr[0]);

    mostrar_todos_los_satelites(sats);

    satelites_al_planeta_X(sats, 3);

    if (sats.tam > 0)
    {
        TRsatelite menor;
        satelite_a_planeta_mas_cercano_sol(sats, menor);
        cout << "\nEl satelite que ira mas cerca del sol es: " << endl;
        mostrar_un_satelite(menor);
    }

    char op;
    do
    {
        // TRsatelite sat;

        // leer_satelite_2(sat);
        // mostrar_un_satelite(sat);
        cout << "Nuevo planeta: ";
        if (agregar_satelite(sats))
        {
            cout << "Se a�adido correctamente.";
        }
        else
        {
            cout << "El array esta lleno.";
        }

        cout << "Desea introduir otro planeta (s/n)";
        cin >> op;
    } while (op == 's' || op == 'S');

    mostrar_todos_los_satelites(sats);

    TAfrec frecuencias = cuantos_sat_por_planeta(sats);

    for (int i = 0; i < NUM_PLANETAS; i++)
    {
        cout << "Al planeta " << nombres[i] << " van " << frecuencias[i] << " satelites." << endl;
    }

    int posicion;
    string codigo;

    cout << "Codigo del planeta a buscar: ";
    cin >> codigo;

    if (buscar_satelite(sats, codigo, posicion))
    {
        cout << "El satelite ESTA";
        mostrar_un_satelite(sats.arr[posicion]);
    }
    else
    {
        cout << "El satelite NO ESTA";
    }

    cout << "Codigo del planeta a eliminar: ";
    cin >> codigo;

    eliminar_satelite(sats, codigo);
    mostrar_todos_los_satelites(sats);

    return 0;
}