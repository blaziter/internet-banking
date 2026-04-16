#include <iostream>
#include <string>
#include <time.h>

#include "utils.hpp"

void printVoidLine() {
    std::cout << std::endl;
}

int printStart() {
    std::cout << "1. Create account" << std::endl;
    std::cout << "2. Login" << std::endl;
    std::cout << "3. Exit" << std::endl;
    std::cout << "Enter your choice: ";

    int choice;
    std::cin >> choice;
    printVoidLine();

    return choice;
};

int printMenu() {
    std::cout << "1. View account details" << std::endl;
    std::cout << "2. Transfer money" << std::endl;
    std::cout << "3. Deposit money" << std::endl;
    std::cout << "4. Withdraw money" << std::endl;
    std::cout << "5. Logout" << std::endl;
    std::cout << "Enter your choice: ";

    int choice;
    std::cin >> choice;
    printVoidLine();

    return choice;
}

std::string generateAccountDetail() {
    srand(time(0));
    std::string accountNumber = "";

    for (int i = 0; i < 10; i++) {
        accountNumber += std::to_string(rand() % 10);
    }

    accountNumber.insert(10, "/6710");

    /**
     * ! add check for unique account number
     */

    return accountNumber;
}
int passwordChecker(std::string password) {
    int running = 0;
    int letters = 0;
    int small_letters = 0;
    int big_letters = 0;
    int numbers = 0;

    for (int i = 0; i < password.length(); i++) {
        letters++;

        if (letters < 12) {
            std::cout << "Your password is too short" << std::endl;
            running = 1;
            return running;
        }

        if (password[i] >= 48 && password[i] <= 57) {
            numbers++;
        } else if (password[i] >= 65 && password[i] <= 90) {
            big_letters++;
        } else if (password[i] >= 97 && password[i] <= 122) {
            small_letters++;
        }

        if (numbers == 0 || big_letters == 0 || small_letters == 0) {
            std::cout << "Your password does not have required specifications" << std::endl;
            running = 1;
            return running;
        }

        return running;
    }
}
