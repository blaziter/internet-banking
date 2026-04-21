#ifndef DB_HPP
#define DB_HPP

#include <SQLiteCpp/Database.h>
#include <SQLiteCpp/Statement.h>

class Database {
   private:
    SQLite::Database sqlcppDb;
    Database();

   public:
    Database(const Database&) = delete;
    Database& operator=(const Database&) = delete;

    static Database& getInstance();

    SQLite::Database& getDb();
};

#endif