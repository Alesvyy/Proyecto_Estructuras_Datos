cmake_minimum_required(VERSION 3.29)
project(ProyectoEstructurasDeDatos)

set(CMAKE_CXX_STANDARD 20)

include_directories(libs/sqlite)

add_executable(ProyectoEstructurasDeDatos
        libs/sqlite/sqlite3.c
        main.cpp
        Models/Producto.cpp
        Models/Producto.h
        menu.cpp
        menu.h
        Models/Categoria.h
        Models/Categoria.cpp
        PracticaColas/Cola.cpp
        PracticaColas/Cola.h
        listas/categorias/ListaCategorias.cpp
        listas/categorias/ListaCategorias.h
        listas/categorias/NodoCategoria.cpp
        listas/categorias/NodoCategoria.h
        listas/productos/ListaProductos.cpp
        listas/productos/ListaProductos.h
        listas/productos/NodoProducto.cpp
        listas/productos/NodoProducto.h
        listas/Variantes/listaVariantes.h
        listas/Variantes/ListaVariantes.cpp
        listas/Variantes/nodoVariante.h
        listas/Variantes/nodoVariante.cpp
        Models/Variante.h
        Models/Variante.cpp
        db/SQLiteManager.cpp
        db/SQLiteManager.h
)
