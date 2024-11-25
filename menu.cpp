#include "menu.h"
#include <iostream>
#include <vector>


Menu::Menu() {}

void Menu::mostrarMenu() {
    int opcion;

    do {
        std::cout << "\n";
        std::cout << "1. Agregar Producto\n";
        std::cout << "2. Ver Productos\n";
        std::cout << "3. Modificar Producto\n";
        std::cout << "4. Eliminar Producto\n";
        std::cout << "5. Agregar Categoria\n";
        std::cout << "6. ver Categorias\n";
        std::cout << "7. Modificar Categoria\n";
        std::cout << "8. Eliminar Categoria\n";

        std::cout << "0. Salir\n";
        std::cout << "\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                 agregarProducto();
            break;
            case 2:
                 verProductos();
            break;
            /*case 3:
                modificarProducto();
            break;
            */
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
            case 0:
                std::cout << "Saliendo...\n";
            break;
            default:
                std::cout << "Opcion no válida. Intente de nuevo.\n";
        }
    } while (opcion != 0);
}

void Menu::mostrarMenuColas() {
    int opcion;
    string atendido;
    std::string turno;

    do {
        std::cout << "\n";
        std::cout << "1. Insertar Turno\n";
        std::cout << "2. Atender Clientes\n";
        std::cout << "3. Mostrar ultimo turno ingresado\n";
        std::cout << "4. Eliminar turno especifico\n";
        std::cout << "5. Verificar cola\n";
        std::cout << "0. Salir\n";
        std::cout << "\n";
        std::cout << "Seleccione una opcion:";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                cola.insertarElem();
                    break;
            case 2:
                cola.atenderCliente(atendido);
                    break;
            case 3:
                std::cout << "Ultimo turno ingresado: " << cola.ultimoElem() << "\n";
                break;
            case 4:
                std::cout << "Ingrese el numero del turno a eliminar: ";
                std::cin >> turno;
                int posicion;
                posicion = cola.buscarTurno(turno);
                if (posicion != -1) {
                    cola.eliminarElem(posicion);
                    std::cout << "Turno " << turno << " eliminado.\n";
                } else {
                    std::cout << "Turno no encontrado.\n";
                }
                break;
            case 5:
                if(cola.esVaciaCola()) {
                    cout <<"La cola esta vacia";
                }else {
                    cola.listarCola();
                }
                break;

            case 0:
                std::cout << "Saliendo...\n";
            break;
            default:
                std::cout << "Opcion no válida. Intente de nuevo.\n";
        }
    } while (opcion != 0);
}

void Menu::agregarProducto() {
    std::string nombre;
    std::string descripcion;
    double precio;

    std::cout << "Ingrese el nombre del producto: ";
    std::cin >> nombre;

    std::cout << "Ingrese el precio del producto: ";
    std::cin >> precio;

    std::cout << "Ingrese la descripcion del producto: ";
    std::cin.ignore();
    std::getline(std::cin, descripcion);

    Producto* producto = new Producto(nombre, descripcion, precio);
    listaProductos.agregarProducto(producto);
}

void Menu::verProductos() {
    listaProductos.display();
}
void Menu::agregarCategoria() {
    std::string nombre;
    std::string descripcion;

    std::cout << "Ingrese el nombre de la categoria: ";
    std::cin >> nombre;

    std::cout << "Ingrese la descripcion de la categoria: ";
    std::cin.ignore();
    std::getline(std::cin, descripcion);

    Categoria* categoria = new Categoria(nombre, descripcion);
    listaCategorias.agregarCategoria(categoria);

};

void Menu::eliminarCategoria() {
    string nombre;

    cout << "Ingrese el nombre de la categoria a eliminar: ";
    cin >> nombre;

    listaCategorias.eliminarCategoria(nombre);
}

void Menu::verCategoria() {
    listaCategorias.display();
}

void Menu::eliminarProducto() {
    string nombre;

    cout << "Ingrese el nombre del Producto a eliminar: ";
    cin >> nombre;

    listaProductos.eliminarProducto(nombre);
}


void Menu::modificarCategoria() {
    std::string nombre,nuevoNombre;

    std::cout << "Ingrese el nombre de la categoria a modificar: ";
    std::cin >> nombre;

    std::cout << "Ingrese el nuevo nombre de la categoria: ";
    std::cin >> nuevoNombre;

    listaCategorias.modificarCategoria(nombre,nuevoNombre);

}
/*
void Menu::modificarProducto() {
    std::string nombre,nuevoNombre;

    std::cout << "Ingrese el nombre del producto a modificar: ";
    std::cin >> nombre;

    std::cout << "Ingrese el nuevo nombre del producto: ";
    std::cin >> nuevoNombre;

    listaProductos.modificarProducto(nombre, nuevoNombre);
}
*/