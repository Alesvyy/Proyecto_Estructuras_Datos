//
// Created by kmq06 on 11/22/2024.
//

#include "SQLiteManager.h"
#include <iostream>
#include <map>
#include "../listas/categorias/ListaCategorias.h"
#include "../Models/Categoria.h"

SQLiteManager::SQLiteManager(const string &dbName) : db(nullprt), dbName(dbName){}

SQLiteManager::~SQLiteManager() {
    if (db != nullprt) {
        sqlite3_close(db);
        cout << "Base de datos cerrada." << endl;
    }
}

bool SQLiteManager::initDB() {
    int exit = sqlite3_open(dbName.c_str(), &db);
    if (exit != SQLITE_OK) {
        cerr << "Error al abir la base de datos: " <<sqlite3_errmsg(db) << endl;
        return false;
    }
    cout << "Base de datos '" << dbName << "' abierta exitosamente." << endl;

    if (!createTables()) {
        cerr << "Error al crear las tablas necesarias." << endl;
        return false;
    }
    return true;
}

int callback(void *data, int argc, char **argv, char **azColName){
    int i;
    fprintf(stderr, "%s: ", (const char*)data);

    for(i = 0; i<argc; i++){
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }

    printf("\n");
    return 0;
}

void SQLiteManager::saveProducto(Producto* producto) {
    unordered_map<string, string> data;
    data["nombre"] = producto->getNombre();
    data["descripcion"] = producto->getDescripcion();
    data["sku"] = producto->getSku();
    data["idCategoria"] = std::to_string(producto->getIdCategoria());
    data["precio"] = std::to_string(producto->getPrecio());
    insert("productos", data);
}

void SQLiteManager::saveCategoria(Categoria* categoria) {
    unordered_map<string, string> data;
    data["id"] = std::to_string(categoria->getId());
    data["nombre"] = categoria->getNombre();
    data["descripcion"] = categoria->getDescripcion();
    insert("categorias", data);
}

ListaCategorias* SQLiteManager::getCategoriasFromDB() {
    string sql = "SELECT * FROM Categorias";

    ListaCategorias* listaCategorias = new ListaCategorias();

    sqlite3_stmt* statement;
    sqlite3_prepare_v2(db, sql.c_str(), -1, &statement, NULL);
    while (sqlite3_step(statement) == SQLITE_ROW) {
        Categoria* categoria = new Categoria(reinterpret_cast<const char*>(sqlite3_column_text(statement,1)),reinterpret_cast<const char*>(sqlite3_column_text(statement,2)), sqlite3_column_int64(statement, 0));
        listaCategorias->agregarCategoria(categoria);
        categoria->setListaProductos(getProductosFromDB(categoria->getId()));
        Categoria::globalId = sqlite3_column_int64(statement, 0);
    }

    Categoria::globalId += 1;

    return listaCategorias;
}

ListaProductos* SQLiteManager::getProductosFromDB(long idCategoria) {
    string sql = "SELECT * FROM productos where idCategoria =" + std::to_string(idCategoria);

    ListaProductos* listaProductos = new ListaProductos();

    sqlite3_stmt* statement;
    sqlite3_prepare_v2(db, sql.c_str(), -1, &statement, NULL);
    while (sqlite3_step(statement) == SQLITE_ROW) {
        Producto* producto = new Producto(reinterpret_cast<const char*>(sqlite3_column_text(statement,3)),reinterpret_cast<const char*>(sqlite3_column_text(statement,4)), sqlite3_column_int64(statement, 5), reinterpret_cast<const char*>(sqlite3_column_text(statement,1)), sqlite3_column_int64(statement, 2));
        producto->setId(sqlite3_column_int64(statement, 0));
        listaProductos->agregarProducto(producto);
    }

    return listaProductos;
}

bool SQLiteManager::createTables() {
    const std::string createTableSQL =
        "CREATE TABLE IF NOT EXISTS categorias ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "nombre TEXT, "
        "descripcion TEXT);"
        ""
        "CREATE TABLE IF NOT EXISTS productos ("
        "idProducto INTEGER PRIMARY KEY AUTOINCREMENT,"
        "sku TEXT,"
        "idCategoria INTEGER, "
        "nombre TEXT, "
        "descripcion TEXT, "
        "precio REAL);";

    return execute(createTableSQL);
}

bool SQLiteManager::execute(const string& sql) {
    char* errMessage = nullptr;
    int exit = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMessage);
    if (exit != SQLITE_OK) {
        cerr << "Error al ejecutar SQL: " << errMessage << endl;
        sqlite3_free(errMessage);
        return false;
    }
    // cout << "SQL ejecutado exitosamente: " << sql << std::endl;
    return true;
}

bool SQLiteManager::insert(const string& table, const unordered_map<string, string>& data) {
    string columns, values;
    for (const auto& [column, value] : data) {
        columns += column + ",";
        values += "'" + value + "',";
    }
    columns.pop_back(); // Eliminar la última coma
    values.pop_back();  // Eliminar la última coma

    string sql = "INSERT INTO " + table + " (" + columns + ") VALUES (" + values + ");";
    return execute(sql);
}

    vector<unordered_map<string, string>> SQLiteManager::select(const string& sql) {
    vector<unordered_map<string, string>> results;
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        cerr << "Error al preparar SELECT: " << sqlite3_errmsg(db) << endl;
        return results;
    }

    int columnCount = sqlite3_column_count(stmt);
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        unordered_map<string, string> row;
        for (int i = 0; i < columnCount; ++i) {
            const char* columnName = sqlite3_column_name(stmt, i);
            const char* columnValue = reinterpret_cast<const char*>(sqlite3_column_text(stmt, i));
            row[columnName] = columnValue ? columnValue : "NULL";
        }
        results.push_back(row);
    }

    sqlite3_finalize(stmt);
    return results;
}

bool SQLiteManager::update(const string& table, const unordered_map<string, string>& data, const string& condition) {
    string updates;
    for (const auto& [column, value] : data) {
        updates += column + "='" + value + "',";
    }
    updates.pop_back(); // Eliminar la última coma

    string sql = "UPDATE " + table + " SET " + updates + " WHERE " + condition + ";";
    return execute(sql);
}

