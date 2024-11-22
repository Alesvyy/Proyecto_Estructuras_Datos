cmake_minimum_required(VERSION 3.29)
project(ProyectoEstructurasDeDatos)

set(CMAKE_CXX_STANDARD 20)

include_directories(
        ${CMAKE_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/Models
        ${CMAKE_SOURCE_DIR}/PracticaColas
)

add_executable(ProyectoEstructurasDeDatos
        main.cpp
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
)