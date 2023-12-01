#include <iostream>
#include <string>

const int MAX = 100; // Puedes ajustar este valor según sea necesario

// Definición de la estructura para la fecha
struct TFecha
{
    int dia;
    int mes;
    int anio;
};

// Definición de la estructura para el producto
struct TProducto
{
    int codigo;
    std::string nombre;
    double precio;
    TFecha caducidad;
};

// Definición de la estructura para la farmacia
struct TFarmacia
{
    TProducto productos[MAX];
    int cantidadProductos;
};

// Subalgoritmo para leer un producto desde la entrada estándar
void LeerProducto(TProducto &p)
{
    std::cout << "Código: ";
    std::cin >> p.codigo;

    std::cout << "Nombre: ";
    std::cin.ignore(); // Ignorar el salto de línea anterior
    std::getline(std::cin, p.nombre);

    std::cout << "Precio: ";
    std::cin >> p.precio;

    std::cout << "Fecha de caducidad (dd mm aaaa): ";
    std::cin >> p.caducidad.dia >> p.caducidad.mes >> p.caducidad.anio;
}

// Subalgoritmo para escribir un producto en la salida estándar
void EscribirProducto(const TProducto &p)
{
    std::cout << "Código: " << p.codigo << "\n";
    std::cout << "Nombre: " << p.nombre << "\n";
    std::cout << "Precio: " << p.precio << "\n";
    std::cout << "Fecha de caducidad: " << p.caducidad.dia << "/" << p.caducidad.mes << "/" << p.caducidad.anio << "\n";
}

// Subalgoritmo para inicializar la farmacia
void InicializarFarmacia(TFarmacia &f)
{
    f.cantidadProductos = 0;
}

// Subalgoritmo para insertar un producto en la farmacia
void InsertarProducto(TFarmacia &f, const TProducto &p)
{
    if (f.cantidadProductos < MAX)
    {
        f.productos[f.cantidadProductos] = p;
        f.cantidadProductos++;
        std::cout << "Producto insertado con éxito.\n";
    }
    else
    {
        std::cout << "Error: La farmacia está llena, no se puede insertar más productos.\n";
    }
}

// Subalgoritmo para borrar un producto de la farmacia por código
void BorrarProducto(TFarmacia &f, int codigo)
{
    for (int i = 0; i < f.cantidadProductos; ++i)
    {
        if (f.productos[i].codigo == codigo)
        {
            // Desplazar los productos restantes para llenar el espacio eliminado
            for (int j = i; j < f.cantidadProductos - 1; ++j)
            {
                f.productos[j] = f.productos[j + 1];
            }
            f.cantidadProductos--;
            std::cout << "Producto eliminado con éxito.\n";
            return;
        }
    }
    std::cout << "Error: No se encontró un producto con el código proporcionado.\n";
}

// Subalgoritmo para buscar un producto por código en la farmacia
void BuscarProductoCodigo(const TFarmacia &f, int codigo, bool &encontrado, TProducto &p)
{
    for (int i = 0; i < f.cantidadProductos; ++i)
    {
        if (f.productos[i].codigo == codigo)
        {
            encontrado = true;
            p = f.productos[i];
            return;
        }
    }
    encontrado = false;
}

// Subalgoritmo para buscar un producto por nombre en la farmacia
void BuscarProductoNombre(const TFarmacia &f, std::string nombre, bool &encontrado, TProducto &p)
{
    for (int i = 0; i < f.cantidadProductos; ++i)
    {
        if (f.productos[i].nombre == nombre)
        {
            encontrado = true;
            p = f.productos[i];
            return;
        }
    }
    encontrado = false;
}

// Subalgoritmo para listar todos los productos de la farmacia
void ListarFarmacia(const TFarmacia &f)
{
    std::cout << "Lista de productos en la farmacia:\n";
    for (int i = 0; i < f.cantidadProductos; ++i)
    {
        EscribirProducto(f.productos[i]);
        std::cout << "------------------------\n";
    }
}

int main()
{
    TFarmacia farmacia;
    InicializarFarmacia(farmacia);

    int opcion;
    do
    {
        std::cout << "\nMenú:\n";
        std::cout << "1. Insertar producto\n";
        std::cout << "2. Borrar producto por código\n";
        std::cout << "3. Buscar producto por código\n";
        std::cout << "4. Buscar producto por nombre\n";
        std::cout << "5. Listar farmacia\n";
        std::cout << "0. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion)
        {
        case 1:
        {
            TProducto nuevoProducto;
            LeerProducto(nuevoProducto);
            InsertarProducto(farmacia, nuevoProducto);
            break;
        }
        case 2:
        {
            int codigo;
            std::cout << "Introduzca el código del producto a borrar: ";
            std::cin >> codigo;
            BorrarProducto(farmacia, codigo);
            break;
        }
        case 3:
        {
            int codigo;
            std::cout << "Introduzca el código del producto a buscar: ";
            std::cin >> codigo;
            bool encontrado;
            TProducto productoEncontrado;
            BuscarProductoCodigo(farmacia, codigo, encontrado, productoEncontrado);
            if (encontrado)
            {
                std::cout << "Producto encontrado:\n";
                EscribirProducto(productoEncontrado);
            }
            else
            {
                std::cout << "Producto no encontrado.\n";
            }
            break;
        }
        case 4:
        {
            std::string nombre;
            std::cout << "Introduzca el nombre del producto a buscar: ";
            std::cin.ignore(); // Ignorar el salto de línea anterior
            std::getline(std::cin, nombre);
            bool encontrado;
            TProducto productoEncontrado;
            BuscarProductoNombre(farmacia, nombre, encontrado, productoEncontrado);
            if (encontrado)
            {
                std::cout << "Producto encontrado:\n";
                EscribirProducto(productoEncontrado);
            }
            else
            {
                std::cout << "Producto no encontrado.\n";
            }
            break;
        }
        case 5:
            ListarFarmacia(farmacia);
            break;
        case 0:
            std::cout << "Saliendo del programa.\n";
            break;
        default:
            std::cout << "Opción no válida. Inténtelo de nuevo.\n";
        }

    } while (opcion != 0);

    return 0;
}
