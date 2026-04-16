#include <SQLiteCpp/Statement.h>
#include <SQLiteCpp/Transaction.h>

#include <iostream>
#include <string>

#include "auth.hpp"
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
        std::string birthDate;

        SQLite::Statement insertUser(db,
                                     "INSERT INTO user (user_id, first_name, "
                                     "last_name, address, email, "
                                     "phone_number, account_detail, password, "
                                     "birth_date) VALUES (?, ?, ?, "
                                     "?, ?, ?, ?, ?, ?)");

        birthDate.append(std::to_string(newUser.getBirthDate()->tm_year));
        birthDate.append("-");
        birthDate.append(std::to_string(newUser.getBirthDate()->tm_mon));
        birthDate.append("-");
        birthDate.append(std::to_string(newUser.getBirthDate()->tm_mday));

        insertUser.bind(1, nullptr);
        insertUser.bind(2, newUser.getFirstName());
        insertUser.bind(3, newUser.getLastName());
        insertUser.bind(4, newUser.getAdress());
        insertUser.bind(5, newUser.getEmail());
        insertUser.bind(6, newUser.getPhoneNumber());
        insertUser.bind(7, newUser.getAccountDetail());
        insertUser.bind(8, newUser.getPassword());
        insertUser.bind(9, birthDate);

        insertUser.exec();

        transaction.commit();
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    return true;
}

bool login() {
    std::string password;
    std::cout << "Enter your password" << std::endl;
    std::cin >> password;
}