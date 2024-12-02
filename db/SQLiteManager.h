//
// Created by kmq06 on 11/22/2024.
//

#ifndef SQLITEMANAGER_H
#define SQLITEMANAGER_H
#include "../listas/categorias/ListaCategorias.h"
using namespace std;

#include <sqlite3.h>
#include <string>
#include <vector>
#include <unordered_map>

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

    bool execute(const string& sql);

    bool insert(const string& table, const unordered_map<string, string>& data);
    vector <unordered_map<string,string>> select(const string& sql);

    bool update(const string& table, const unordered_map<string, string>& data, const string& condition);
    bool remove(const string& table, const string& condition);

    void saveProducto(Producto* producto);
    void saveCategoria(Categoria* categoria);
    ListaCategorias* getCategoriasFromDB();
    ListaProductos* getProductosFromDB(long idCategoria);

};


#endif //SQLITEMANAGER_H
