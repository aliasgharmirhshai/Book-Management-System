#include <stdio.h>
#include <sqlite3.h>

int read_data(void* data, int argc, char** argv, char** column_names) {
    for (int i=0; i < argc; i++){
        printf("%s = %s\n", column_names[i], argv[i]);   
    }
    printf("\n");
    return 0;
}

int main() {
    sqlite3* db;
    int rc = sqlite3_open("mydatabase.db", &db);
    if (rc != SQLITE_OK) {
        printf("ERROR opening SQLite DB in memory: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    const char* sql = "SELECT * FROM user";
    char* err_msg = 0;

    rc = sqlite3_exec(db, sql, read_data, NULL, &err_msg);
    if (rc != SQLITE_OK) {
        printf("ERROR: %s\n", err_msg);
        sqlite3_free(err_msg); 
        return 1;
    }

    sqlite3_close(db);
    return 0;
}