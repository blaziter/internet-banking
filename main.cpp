#include <SQLiteCpp/Column.h>
#include <SQLiteCpp/Database.h>
#include <SQLiteCpp/Statement.h>
#include <sqlite3.h>

#include <iostream>
#include <string>

#include "account.hpp"
#include "user.hpp"
#include "utils.hpp"
#include "auth.hpp"

#define PROJECT_NAME "internet-banking"

/**
 * @authors Petr Tran <petr.tran@unob.cz>, Pavel Tomšík <pavel.tomsik2@unob.cz>
 * @brief The main function of the internet banking application.
 */
int main() {
    int running = 1;
    while (running == 1) {
        int choice = printStart();
        switch (choice) {
            {
                case 1:
                    User newUser = newUser.createAccount();
                    std::string accountNumber = generateAccountDetail();
                    break;
            }
            case 2:
                login();
                break;
            case 3:
                running = 0;
                break;

            default:
                std::cout << "Invalid input" << std::endl;
                break;
        }
        if (choice == 2)
        {
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
                case 4:
                    // Function for withdraw money
                    break;
                case 5:
                    // Logout function
                    break;
                default:
                    std::cout << "Invalid input" << std::endl;
                    break;
            }
        }
        return 0;
    }
