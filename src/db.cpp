#include "db.hpp"

#include <SQLiteCPP/Database.h>
#include <SQLiteCPP/Statement.h>
#include <SQLiteCpp/Transaction.h>

#include <iostream>

Database::Database() try
    : sqlcppDb("db.sqlite", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE) {
    if (!sqlcppDb.tableExists("account") && !sqlcppDb.tableExists("card") &&
        !sqlcppDb.tableExists("transaction") && !sqlcppDb.tableExists("user")) {
        SQLite::Transaction transaction(sqlcppDb);

        sqlcppDb.exec(
            "CREATE TABLE `account` ("
            "`account_id` integer not null primary key autoincrement,"
            "`user_id` integer not null,"
            "`created_at` datetime not null default CURRENT_TIMESTAMP,"
            "`updated_at` datetime not null default CURRENT_TIMESTAMP,"
            "`account_detail` varchar(255) not null,"
            "`balance` double not null,"
            "FOREIGN KEY(user_id) REFERENCES user(user_id))");

        sqlcppDb.exec(
            "CREATE TRIGGER IF NOT EXISTS update_account_updated_at AFTER "
            "UPDATE OF updated_at ON account FOR EACH ROW BEGIN UPDATE account "
            "SET updated_at = CURRENT_TIMESTAMP WHERE account_id = "
            "OLD.account_id; END;");

        sqlcppDb.exec(
            "CREATE TABLE `card` ("
            "`card_id` integer not null primary key autoincrement,"
            "`created_at` datetime not null default CURRENT_TIMESTAMP,"
            "`updated_at` datetime not null default CURRENT_TIMESTAMP,"
            "`account_id` INTEGER not null,"
            "`card_number` VARCHAR(255) not null,"
            "`expiry_date` DATE not null,"
            "`status` TINYINT null,"
            "`security_number` tinyint,"
            "FOREIGN KEY (account_id) REFERENCES account (account_id))");

        sqlcppDb.exec(
            "CREATE TRIGGER IF NOT EXISTS update_card_updated_at AFTER UPDATE "
            "OF updated_at ON card FOR EACH ROW BEGIN UPDATE card SET "
            "updated_at = CURRENT_TIMESTAMP WHERE card_id = OLD.card_id; END;");

        sqlcppDb.exec(
            "CREATE TABLE `transaction` ("
            "`transaction_id` integer not null primary key autoincrement,"
            "`created_at` datetime not null default CURRENT_TIMESTAMP,"
            "`updated_at` datetime not null default CURRENT_TIMESTAMP,"
            "`from_account_id` INTEGER not null,"
            "`to_account_id` INTEGER not null,"
            "`type` TINYINT not null,"
            "`amount` double not null,"
            "FOREIGN KEY (from_account_id) REFERENCES account (account_id) "
            "FOREIGN "
            "KEY (to_account_id) REFERENCES account (account_id))");

        sqlcppDb.exec(
            "CREATE TRIGGER IF NOT EXISTS update_transaction_updated_at AFTER "
            "UPDATE OF updated_at ON transaction FOR EACH ROW BEGIN UPDATE "
            "transaction SET updated_at = CURRENT_TIMESTAMP WHERE "
            "transaction_id = OLD.transaction_id; END;");

        sqlcppDb.exec(
            "CREATE TABLE `user` ("
            "`user_id` integer not null primary key autoincrement,"
            "`created_at` datetime not null default CURRENT_TIMESTAMP,"
            "`updated_at` datetime not null default CURRENT_TIMESTAMP,"
            "`first_name` varchar(255) not null,"
            "`last_name` varchar(255) not null,"
            "`address` varchar(255) not null,"
            "`email` varchar(255) not null,"
            "`phone_number` varchar(255) not null,"
            "`account_detail` varchar(255) not null,"
            "`password` varchar(255) not null,"
            "birth_date integer not null)");

        sqlcppDb.exec(
            "CREATE TRIGGER IF NOT EXISTS update_user_updated_at AFTER UPDATE "
            "OF updated_at ON user FOR EACH ROW BEGIN UPDATE user SET "
            "updated_at = CURRENT_TIMESTAMP WHERE user_id = OLD.user_id; END;");

        transaction.commit();
    }
} catch (const std::exception& e) {
    std::cerr << "Failed to open database: " << e.what() << std::endl;
    std::cout << "Exiting..." << std::endl;
    std::exit(EXIT_FAILURE);
}

Database& Database::getInstance() {
    static Database instance;
    return instance;
}

SQLite::Database& Database::getDb() { return sqlcppDb; }
