//
// Created by kmq06 on 11/22/2024.
//

#ifndef SQLITEMANAGER_H
#define SQLITEMANAGER_H
using namespace std;

#include <sqlite3.h>
#include <string>
#include <vector>
#include <unordered_map>
#include "../listas/categorias/ListaCategorias.h"

class SQLiteManager {
private:
    sqlite3* db;
    string dbName;
    sqlite3 * nullprt;

    bool createTables();

public:
    SQLiteManager(const string& dbName);
    ~SQLiteManager();

    bool initDB();
    bool loadIds();

    bool execute(const string& sql);

    bool insert(const string& table, const unordered_map<string, string>& data);
    vector <unordered_map<string,string>> select(const string& sql);

    bool update(const string& table, const unordered_map<string, string>& data, const string& condition);
    bool remove(const string& table, const string& condition);

    void saveVariante(Variante* variante);
    void saveProducto(Producto* producto);
    void saveCategoria(Categoria* categoria);
    ListaCategorias* getCategoriasFromDB();
    ListaProductos* getProductosFromDB(long idCategoria);
    void eliminarCategoria(Categoria* categoria);
    void eliminarProducto(Producto* categoria);
};

#endif //SQLITEMANAGER_H
