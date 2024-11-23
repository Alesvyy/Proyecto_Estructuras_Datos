//
// Created by kmq06 on 11/22/2024.
//

#include "SQLiteManager.h"
#include <iostream>

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

bool SQLiteManager::createTables() {
    const std::string createTableSQL =
        "CREATE TABLE IF NOT EXISTS categorias ("
        "id INTEGER PRIMARY KEY, "
        "nombre TEXT NOT NULL, "
        "descripcion TEXT NOT NULL);";

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
    cout << "SQL ejecutado exitosamente: " << sql << std::endl;
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






