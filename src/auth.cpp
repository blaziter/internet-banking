#include "auth.hpp"

#include <SQLiteCpp/Statement.h>
#include <SQLiteCpp/Transaction.h>

#include <iostream>
#include <string>

#include "db.hpp"
#include "user.hpp"
#include "utils.hpp"

/**
 * @author "Petr Tran(petr.tran@unob.cz)"
 * @brief Function to register a new user in the database. It checks if the
 * email or phone number already exists in the database before inserting the
 * new user.
 * @param email The email of the new user.
 * @param phone_number The phone number of the new user.
 * @param newUser The User object containing the details of the new user.
 */
bool registration(const std::string& email, const std::string& phone_number,
                  User& newUser) {
    SQLite::Database& db = Database::getInstance().getDb();

    try {
        SQLite::Statement user(
            db, "SELECT * FROM user WHERE email = ? OR phone_number = ?");

        user.bind(1, email);
        user.bind(2, phone_number);

        while (user.executeStep()) {
            std::cout << "Uzivatel uz existuje" << std::endl;
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

/**
 * @author "Petr Tran(petr.tran@unob.cz)"
 * @brief Function to login a user by checking the provided email and password
 * with values in database. If the credentials match, then save parameters to a
 * User object.
 *  @param user Pointer to a User object that will contain user parameters.
 */
bool login(User* user) {
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

        SQLite::Statement stmt(
            db,
            "SELECT * FROM user WHERE email = ? INNER JOIN account ON "
            "user.id = account.user_id");

        stmt.bind(1, email);

        if (stmt.executeStep()) {
            if (stmt.getColumn("password")
                    .getString()
                    .compare(hashPassword(password)) == 0) {
                std::cout << "Uspesne prihlaseni" << std::endl;

                *user = User(stmt.getColumn("first_name").getString(),
                             stmt.getColumn("last_name").getString(),
                             stmt.getColumn("address").getString(),
                             stmt.getColumn("email").getString(),
                             stmt.getColumn("phone_number").getString(),
                             stmt.getColumn("password").getString(),
                             stmt.getColumn("account_detail").getString(),
                             getTmFromDateString(
                                 stmt.getColumn("birth_date").getString()));

                return true;
            } else {
                std::cout << "Nespravne heslo" << std::endl;
                return false;
            }
        } else {
            std::cout << "Uzivatel nenalezen" << std::endl;
            return false;
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    return true;
}
