#include "database.h"
#include <stdio.h>
#include <sqlite3.h>
#include <string.h> 

int read_data(void* data, int argc, char** argv, char** column_names) {
    for (int i = 0; i < argc; i++) {
        printf("%s = %s\n", column_names[i], argv[i]);
    }
    return 0;
}

void read_from_database(sqlite3* db, const char* sql) {
    char* err_msg;

    int rc = sqlite3_exec(db, sql, read_data, NULL, &err_msg);
    if (rc != SQLITE_OK) {
        printf("ERROR executing command: %s\n", err_msg);
        sqlite3_free(err_msg);
    }
}

void db_handler(const char* dbName, char* dbCommand) {
    sqlite3* db;

    int rc = sqlite3_open(dbName, &db);
    if (rc != SQLITE_OK) {
        printf("ERROR opening SQLite DB in memory: %s\n", sqlite3_errmsg(db));
    }

    // Read Data
    if (strcmp(dbCommand, "read") == 0) {
        char* sql = "SELECT * FROM user";
        read_from_database(db, sql);
    } 
    
    else if(strcmp(dbCommand, "readBook") == 0) {
        char* sql = "SELECT book FROM user";
        read_from_database(db, sql);
    }

    else if(strcmp(dbCommand, "readName") == 0) {
        char* sql = "SELECT name FROM user";
        read_from_database(db, sql);
    }

    else if(strcmp(dbCommand, "readAge") == 0) {
        char* sql = "SELECT age FROM user";
        read_from_database(db, sql);
    }

    else if(strcmp(dbCommand, "readEmail") == 0) {
        char* sql = "SELECT email FROM user";
        read_from_database(db, sql);
    }

    // Delete Data

    // Add Data
    
    else {
        printf("%s\n", "DataBase Command Error");
    }

    sqlite3_close(db);
}