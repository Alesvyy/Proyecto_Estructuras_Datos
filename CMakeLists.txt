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
        Models/ListaCategorias.cpp
        Models/ListaCategorias.h
        Models/NodoCategoria.cpp
        Models/NodoCategoria.h
        db/SQLiteManager.cpp
        db/SQLiteManager.h
)
