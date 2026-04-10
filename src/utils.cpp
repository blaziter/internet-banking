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
