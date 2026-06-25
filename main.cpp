#include <SQLiteCpp/Column.h>
#include <SQLiteCpp/Database.h>
#include <SQLiteCpp/Statement.h>
#include <sqlite3.h>

#include <iostream>
#include <string>
#include <vector>

#include "account.hpp"
#include "auth.hpp"
#include "db.hpp"
#include "user.hpp"
#include "utils.hpp"

#define PROJECT_NAME "internet-banking"

/**
 * @authors Petr Tran <petr.tran@unob.cz>, Pavel Tomšík <pavel.tomsik2@unob.cz>
 * @brief The main function of the internet banking application.
 */
int main() {
    /**
     * * Initialize the database connection and create tables if they do not
     * * exist
     */
    Database::getInstance().getDb();
    bool isLoggedIn = false;

    /**
     * * Redis "alike" vector for caching account details for faster access and
     * to generate unique account numbers
     */
    std::vector<std::string> accountDetails;
    User *currentUser;

    bool isRunning = true;
    while (isRunning) {
        if (!isLoggedIn) {
            int choice = printStart();
            switch (choice) {
                /**
                 * * Registration case
                 */
                case 1: {
                    User newUser = newUser.createAccount();

                    std::string accountNumber =
                        generateAccountDetail(accountDetails);
                    newUser.setAccountDetail(accountNumber);

                    registration(newUser.getEmail(), newUser.getPhoneNumber(),
                                 newUser);
                    break;
                }
                /**
                 * * Login case
                 */
                case 2:
                    login(currentUser) ? isLoggedIn = true
                                        : isLoggedIn = false;
                    break;
                /**
                 * * Exit case
                 */
                case 3:
                    isRunning = false;
                    break;
                default:
                    std::cout << "Nespravny input" << std::endl;
                    break;
            }
        }

        if (isLoggedIn) {
            int choice2 = printMenu();
            switch (choice2) {
                case 1:
                    // Function for account details
                    break;
                case 2:
                    // Function for transfer money
                    break;
                case 3:
                    // Function for deposit money
                    break;
                case 4:
                    // Function for withdraw money
                    break;
                case 5:
                    // Logout function
                    isLoggedIn = false;
                    currentUser = nullptr;
                    break;
                default:
                    std::cout << "Nespravny input" << std::endl;
                    break;
            }
        }
    }

    return 0;
}
