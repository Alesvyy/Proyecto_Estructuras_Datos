
#include "menu.h"
#include "db/SQLiteManager.h"
#include "listas/ListaCategorias.h"

int main() {

    Menu menu;
    menu.mostrarMenu();
    SQLiteManager dbManager("../db/prod.db");

    dbManager.initDB();
    return 0;
}