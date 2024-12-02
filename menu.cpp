#include "menu.h"
#include <iostream>
#include <limits>

#include "db/SQLiteManager.h"



Menu::Menu() {
    dbManager = new SQLiteManager("../db/prod.db");
    cargarDatosDB();
}

void Menu::cargarDatosDB() {
    cout << "Cargando datos previamente guardados" << endl;
    dbManager->initDB();
    listaCategorias = dbManager->getCategoriasFromDB();

}


void Menu::mostrarMenu() {
    int opcion;

    do {
        std::cout << "\n";
        std::cout << "1. Agregar Producto\n";
        std::cout << "2. Ver Productos\n";
        std::cout << "3. Modificar Producto\n";
        std::cout << "4. Eliminar Producto\n";
        std::cout << "5. Agregar Categoria\n";
        std::cout << "6. Ver Categorias\n";
        std::cout << "7. Modificar Categoria\n";
        std::cout << "8. Eliminar Categoria\n";
        std::cout << "9. Filtrar Categorias por Letra\n";
        std::cout << "10. Buscar Producto\n";
        std::cout << "0. Salir\n";
        std::cout << "\n";
        std::cout << "Seleccione una opcion: ";

        if (!(std::cin >> opcion)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada invalida. Por favor, intentelo mas tarde.\n";
            continue;
        }

        switch (opcion) {
            case 1:
                agregarProducto();
            break;
            case 2:
                verProductos();
            break;
            case 3:
                modificarProducto();
            break;
            case 4:
                eliminarProducto();
            break;
            case 5:
                agregarCategoria();
            break;
            case 6:
                verCategoria();
            break;
            case 7:
                modificarCategoria();
            break;
            case 8:
                eliminarCategoria();
            break;
            case 9:
                filtrarCategoriasPorLetra();  // Llamamos a la función de filtro
            break;
            case 10:
                buscarProducto();
            break;
            case 0:
                std::cout << "Saliendo...\n";
            break;
            default:
                std::cout << "Opcion no valida. Intente de nuevo.\n";
        }
    } while (opcion != 0);
}


void Menu::agregarProducto() {
    if (listaCategorias->getHead() == nullptr) {
        std::cout << "No hay categorias disponibles. Agregue una categoria primero.\n";
        return;
    }

    std::cout << "Seleccione una categoria para agregar el producto:\n";
    listaCategorias->display();

    int numeroCategoria;
    std::cout << "Ingrese el numero de la categoria: ";
    while (true) {
        std::cin >> numeroCategoria;

        if (std::cin.fail() || numeroCategoria < 1 || numeroCategoria > listaCategorias->contarCategorias()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada invalida. Por favor, ingrese un numero valido entre 1 y "
                      << listaCategorias->contarCategorias() << ".\n";
        } else {
            break;
        }
    }

    NodoCategoria* categoriaSeleccionada = listaCategorias->obtenerNodoPorNumero(numeroCategoria);
    if (!categoriaSeleccionada) {
        std::cout << "Numero de categoria invalido. Operacion cancelada.\n";
        return;
    }

    std::string nombre, descripcion, sku;
    double precio;

    std::cin.ignore();
    std::cout << "Ingrese el nombre del producto: ";
    std::getline(std::cin, nombre);

    std::cout << "Ingrese la descripcion del producto: ";
    std::getline(std::cin, descripcion);

    std::cout << "Ingrese el precio del producto: ";
    while (true) {
        std::cin >> precio;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada invalida. Por favor, ingrese un numero valido para el precio.\n";
        } else {
            break;
        }
    }

    std::cin.ignore();
    std::cout << "Ingrese el SKU del producto: ";
    std::cin >> sku;

    Producto* nuevoProducto = new Producto(nombre, descripcion, precio, sku, categoriaSeleccionada->getCategoria()->getId());
    dbManager->saveProducto(nuevoProducto);

    categoriaSeleccionada->getCategoria()->getListaProductos()->agregarProducto(nuevoProducto);

    std::cout << "\nProducto agregado exitosamente a la categoria \""
              << categoriaSeleccionada->getCategoria()->getNombre() << "\":\n";
    std::cout << "Nombre: " << nombre << "\n";
    std::cout << "Descripcion: " << descripcion << "\n";
    std::cout << "Precio: " << precio << " Colones\n";
    std::cout << "SKU: " << sku << "\n";
}



void Menu::verProductos() {
    if (listaCategorias->getHead() == nullptr) {
        std::cout << "No hay categorias disponibles.\n";
        return;
    }

    NodoCategoria* tempCategoria = listaCategorias->getHead();
    int contadorCategoria = 1;

    while (tempCategoria != nullptr) {
        std::cout << "\nCategoria " << contadorCategoria << ": " << tempCategoria->getCategoria()->getNombre() << "\n";
        tempCategoria->getCategoria()->getListaProductos()->display();
        tempCategoria = tempCategoria->getSiguiente();
        contadorCategoria++;
    }
}


void Menu::modificarProducto() {
    if (listaCategorias->getHead() == nullptr) {
        std::cout << "No hay categorias disponibles.\n";
        return;
    }

    std::cout << "Seleccione una categoria que contenga el producto a modificar:\n";
    listaCategorias->display();

    int numeroCategoriaOriginal;
    std::cout << "Ingrese el numero de la categoria: ";
    while (true) {
        std::cin >> numeroCategoriaOriginal;

        if (std::cin.fail() || numeroCategoriaOriginal < 1 || numeroCategoriaOriginal > listaCategorias->contarCategorias()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada invalida. Por favor, ingrese un numero valido entre 1 y "
                      << listaCategorias->contarCategorias() << ".\n";
        } else {
            break;
        }
    }

    NodoCategoria* categoriaOriginal = listaCategorias->obtenerNodoPorNumero(numeroCategoriaOriginal);
    if (!categoriaOriginal) {
        std::cout << "Numero de categoria invalido. Operacion cancelada.\n";
        return;
    }

    std::cout << "Productos en la categoria \"" << categoriaOriginal->getCategoria()->getNombre() << "\":\n";
    categoriaOriginal->getCategoria()->getListaProductos()->display();

    std::string nombreActual;
    std::cout << "Ingrese el nombre del producto que desea modificar: ";
    std::cin.ignore();
    std::getline(std::cin, nombreActual);

    NodoProducto* nodoProducto = categoriaOriginal->getCategoria()->getListaProductos()->buscarProducto(nombreActual);
    if (!nodoProducto) {
        std::cout << "El producto con el nombre \"" << nombreActual << "\" no existe en esta categoria.\n";
        return;
    }

    std::string nuevoNombre, nuevaDescripcion;
    double nuevoPrecio;

    std::cout << "Ingrese el nuevo nombre del producto: ";
    std::getline(std::cin, nuevoNombre);

    std::cout << "Ingrese el nuevo precio del producto: ";
    while (true) {
        std::cin >> nuevoPrecio;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada invalida. Por favor, ingrese un numero valido para el precio.\n";
        } else {
            break;
        }
    }

    std::cin.ignore();
    std::cout << "Ingrese la nueva descripcion del producto: ";
    std::getline(std::cin, nuevaDescripcion);

    std::cout << "Seleccione una nueva categoria para mover el producto (o elija la misma categoria):\n";
    listaCategorias->display();

    int numeroCategoriaNueva;
    std::cout << "Ingrese el numero de la nueva categoria: ";
    while (true) {
        std::cin >> numeroCategoriaNueva;

        if (std::cin.fail() || numeroCategoriaNueva < 1 || numeroCategoriaNueva > listaCategorias->contarCategorias()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada invalida. Por favor, ingrese un numero valido entre 1 y "
                      << listaCategorias->contarCategorias() << ".\n";
        } else {
            break;
        }
    }

    NodoCategoria* categoriaNueva = listaCategorias->obtenerNodoPorNumero(numeroCategoriaNueva);
    if (!categoriaNueva) {
        std::cout << "Numero de categoria invalido. Operacion cancelada.\n";
        return;
    }

    Producto* productoActualizado = new Producto(nuevoNombre, nuevaDescripcion, nuevoPrecio);
    categoriaNueva->getCategoria()->getListaProductos()->agregarProducto(productoActualizado);

    if (categoriaOriginal != categoriaNueva) {
        categoriaOriginal->getCategoria()->getListaProductos()->eliminarProducto(nombreActual);
    }

    std::cout << "El producto ha sido modificado exitosamente y movido a la categoraa \""
              << categoriaNueva->getCategoria()->getNombre() << "\".\n";
}




void Menu::eliminarProducto() {
    if (listaCategorias->getHead() == nullptr) {
        std::cout << "No hay categorias disponibles.\n";
        return;
    }

    // Selección de categoría
    std::cout << "Seleccione una categoria para eliminar productos:\n";
    listaCategorias->display();

    int numeroCategoria;
    std::cout << "Ingrese el numero de la categoria: ";
    while (true) {
        std::cin >> numeroCategoria;

        if (std::cin.fail() || numeroCategoria < 1 || numeroCategoria > listaCategorias->contarCategorias()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada invalida. Por favor, ingrese un numero valido entre 1 y "
                      << listaCategorias->contarCategorias() << ".\n";
        } else {
            break;
        }
    }

    NodoCategoria* categoriaSeleccionada = listaCategorias->obtenerNodoPorNumero(numeroCategoria);
    if (!categoriaSeleccionada) {
        std::cout << "Numero de categoria invalido. Operacion cancelada.\n";
        return;
    }

    std::cout << "Productos en la categoria \"" << categoriaSeleccionada->getCategoria()->getNombre() << "\":\n";
    categoriaSeleccionada->getCategoria()->getListaProductos()->display();

    std::string nombreProducto;
    std::cout << "Ingrese el nombre del producto que desea eliminar: ";
    std::cin.ignore();
    std::getline(std::cin, nombreProducto);

    categoriaSeleccionada->getCategoria()->getListaProductos()->eliminarProducto(nombreProducto);
}



////Categorias

void Menu::agregarCategoria() {
    std::string nombre, descripcion;

    std::cout << "Ingrese el nombre de la categoria: ";
    std::cin.ignore();
    std::getline(std::cin, nombre);

    std::cout << "Ingrese la descripcion de la categoria: ";
    std::getline(std::cin, descripcion);

    Categoria* nuevaCategoria = new Categoria(nombre, descripcion);
    listaCategorias->agregarCategoria(nuevaCategoria);

    std::cout << "\nCategoria agregada exitosamente:\n";
    std::cout << "Nombre: " << nombre << "\n";
    std::cout << "Descripcion: " << descripcion << "\n";
}


void Menu::verCategoria() {
    if (listaCategorias->getHead() == nullptr) {
        std::cout << "No hay categorias disponibles.\n";
        return;
    }

    NodoCategoria* tempCategoria = listaCategorias->getHead();
    int contadorCategoria = 1;

    while (tempCategoria != nullptr) {

        std::cout << contadorCategoria << ". Categoria: " << tempCategoria->getCategoria()->getNombre() << "\n";
        std::cout << "   Descripcion: " << tempCategoria->getCategoria()->getDescripcion() << "\n";

        std::cout << "   Productos:\n";
        tempCategoria->getCategoria()->getListaProductos()->display();

        tempCategoria = tempCategoria->getSiguiente();
        contadorCategoria++;
    }
}


void Menu::modificarCategoria() {
    if (listaCategorias->getHead() == nullptr) {
        std::cout << "No hay categorias disponibles.\n";
        return;
    }

    std::cout << "Categorias existentes:\n";
    listaCategorias->display();

    std::string nombreActual, nuevoNombre, nuevaDescripcion;

    std::cout << "Ingrese el nombre de la categoria a modificar: ";
    std::cin.ignore();
    std::getline(std::cin, nombreActual);

    std::cout << "Ingrese el nuevo nombre de la categoria: ";
    std::getline(std::cin, nuevoNombre);

    std::cout << "Ingrese la nueva descripcion de la categoria: ";
    std::getline(std::cin, nuevaDescripcion);

    listaCategorias->modificarCategoria(nombreActual, nuevoNombre, nuevaDescripcion);
}


void Menu::eliminarCategoria() {
    if (listaCategorias->getHead() == nullptr) {
        std::cout << "No hay categorias disponibles.\n";
        return;
    }

    std::cout << "Categorias existentes:\n";
    listaCategorias->display();

    std::string nombre;

    std::cout << "Ingrese el nombre de la categoria a eliminar: ";
    std::cin.ignore();
    std::getline(std::cin, nombre);

    listaCategorias->eliminarCategoria(nombre);
}

void Menu::filtrarPorLetra() {
    NodoCategoria* actual = listaCategorias->getHead();

    char letra = 'A';

    while (actual != nullptr) {

        if (actual->getCategoria()->getNombre()[0] == letra) {
            std::cout << actual->getCategoria()->getNombre() << std::endl;
        }

        actual = actual->getSiguiente();
    }
}

void Menu::filtrarCategoriasPorLetra() {
    char letra;
    std::cout << "Ingrese la letra para filtrar las categorias: ";
    std::cin >> letra;

    letra = toupper(letra);

    NodoCategoria* actual = listaCategorias->getHead();

    bool encontrado = false;
    while (actual != nullptr) {

        if (toupper(actual->getCategoria()->getNombre()[0]) == letra) {
            std::cout << "Categoria: " << actual->getCategoria()->getNombre() << std::endl;
            encontrado = true;
        }
        actual = actual->getSiguiente();
    }

    if (!encontrado) {
        std::cout << "No se encontraron categorias que comiencen con la letra '" << letra << "'.\n";
    }
}

void Menu::buscarProducto() {
    if (listaCategorias->getHead() == nullptr) {
        std::cout << "No hay categorias disponibles.\n";
        return;
    }

    std::cout << "Ingrese el nombre o SKU del producto que desea buscar: ";
    std::string termino;
    std::cin.ignore();
    std::getline(std::cin, termino);

    NodoCategoria* categoria = listaCategorias->getHead();
    bool encontrado = false;

    while (categoria != nullptr) {
        ListaProductos* listaProductos = categoria->getCategoria()->getListaProductos();
        NodoProducto* producto = listaProductos->getHead();

        while (producto != nullptr) {
            if (producto->getProducto()->getNombre() == termino || producto->getProducto()->getSku() == termino) {
                std::cout << "Producto encontrado en la categoria \"" << categoria->getCategoria()->getNombre() << "\":\n";
                std::cout << "Nombre: " << producto->getProducto()->getNombre() << "\n";
                std::cout << "Descripcion: " << producto->getProducto()->getDescripcion() << "\n";
                std::cout << "Precio: " << producto->getProducto()->getPrecio() << "\n";
                std::cout << "SKU: " << producto->getProducto()->getSku() << "\n";
                encontrado = true;
                break;
            }
            producto = producto->getSiguiente();
        }

        if (encontrado) break;
        categoria = categoria->getSiguiente();
    }

    if (!encontrado) {
        std::cout << "No se encontro un producto con el termino proporcionado.\n";
    }
}
