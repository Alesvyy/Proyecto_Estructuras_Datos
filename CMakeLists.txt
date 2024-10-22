cmake_minimum_required(VERSION 3.29)
project(ProyectoEstructurasDeDatos)

set(CMAKE_CXX_STANDARD 20)

add_executable(ProyectoEstructurasDeDatos
        main.cpp
        Models/Producto.cpp
        Models/Producto.h
        menu.cpp
        menu.h
        Models/Categoria.h
        Models/Categoria.cpp
        PracticaColas/Cola.cpp
        PracticaColas/Cola.h
        Models/Categoría.cpp)
