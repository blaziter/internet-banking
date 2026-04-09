#include <iostream>

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