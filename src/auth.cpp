#include "auth.hpp"

#include <SQLiteCpp/Statement.h>
#include <SQLiteCpp/Transaction.h>

#include <iostream>
#include <string>

#include "db.hpp"
#include "user.hpp"
#include "utils.hpp"

bool registration(std::string email, std::string phone_number, User newUser) {
    SQLite::Database& db = Database::getInstance().getDb();

    try {
        SQLite::Statement user(
            db, "SELECT * FROM user WHERE email = ? OR phone_number = ?");

        user.bind(1, email);
        user.bind(2, phone_number);

        while (user.executeStep()) {
            std::cout << "User already exists!" << std::endl;
            return false;
        }

        SQLite::Transaction transaction(db);

        SQLite::Statement insertUser(db,
                                     "INSERT INTO user (user_id, first_name, "
                                     "last_name, address, email, "
                                     "phone_number, account_detail, password, "
                                     "birth_date) VALUES (?, ?, ?, "
                                     "?, ?, ?, ?, ?, ?)");

        insertUser.bind(1, nullptr);
        insertUser.bind(2, newUser.getFirstName());
        insertUser.bind(3, newUser.getLastName());
        insertUser.bind(4, newUser.getAdress());
        insertUser.bind(5, newUser.getEmail());
        insertUser.bind(6, newUser.getPhoneNumber());
        insertUser.bind(7, newUser.getAccountDetail());
        insertUser.bind(8, hashPassword(newUser.getPassword()));
        insertUser.bind(9, formatDate(newUser.getBirthDate()));

        insertUser.exec();

        transaction.commit();
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    return true;
}

bool login() {
    SQLite::Database& db = Database::getInstance().getDb();
    try {
        std::string email;
        std::string password;

        std::cout << "Zadej email:" << std::endl;
        std::cin >> email;
        printVoidLine();

        std::cout << "Zadej heslo:" << std::endl;
        std::cin >> password;
        printVoidLine();

        SQLite::Statement user(db, "SELECT * FROM user WHERE email = ?");

        user.bind(1, email);

        if (user.executeStep()) {
            if (user.getColumn("password")
                    .getString()
                    .compare(hashPassword(password)) == 0) {
                std::cout << "Login successful!" << std::endl;
                return true;
            } else {
                std::cout << "Invalid password!" << std::endl;
                return false;
            }
        } else {
            std::cout << "User not found!" << std::endl;
            return false;
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    return true;
}
