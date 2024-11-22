cmake_minimum_required(VERSION 3.29)
project(ProyectoEstructurasDeDatos)

set(CMAKE_CXX_STANDARD 20)

# Agregar directorios de encabezados
include_directories(
        ${CMAKE_SOURCE_DIR}                  # Directorio raíz del proyecto
        ${CMAKE_SOURCE_DIR}/Models           # Directorio Models
        ${CMAKE_SOURCE_DIR}/PracticaColas   # Directorio PracticaColas
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
