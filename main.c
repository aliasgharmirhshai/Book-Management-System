#include <stdio.h>
#include <sqlite3.h>
#include "dataBase/database.h"

int main() {
    db_handler("mydatabase.db", "read");


    return 0;
}