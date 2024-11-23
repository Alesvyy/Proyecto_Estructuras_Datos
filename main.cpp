
#include "menu.h"
#include "db/SQLiteManager.h"
#include "Models/ListaCategorias.h"

int main() {



    // Menu menu;
    // //menu.mostrarMenu();
    // menu.mostrarMenuColas();

    SQLiteManager dbManager("../db/prod.db");

    dbManager.initDB();

    // dbManager.insert("categorias",{{"nombre", "Dunga"},{"descripcion","Perrito wapo"}});





    return 0;
}
