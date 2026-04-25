#include "utils.hpp"

#include <openssl/evp.h>
#include <time.h>

#include <iostream>
#include <string>

void printVoidLine() { std::cout << std::endl; }

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

        if (password.at(i) >= 48 && password.at(i) <= 57) {
            numbers++;
        } else if (password.at(i) >= 65 && password.at(i) <= 90) {
            big_letters++;
        } else if (password.at(i) >= 97 && password.at(i) <= 122) {
            small_letters++;
        }
    }

    if (letters < 12) {
        std::cout << "Your password is too short" << std::endl;
        running = 1;
        return running;
    }

    if (numbers == 0 || big_letters == 0 || small_letters == 0) {
        std::cout << numbers << " " << big_letters << " " << small_letters
                  << std::endl;
        std::cout << "Your password does not have required specifications"
                  << std::endl;
        running = 1;
        return running;
    }

    return running;
}

std::string formatDate(tm* date) {
    std::string formattedDate = "";

    formattedDate.append(std::to_string(date->tm_year));
    formattedDate.append("-");

    int month = date->tm_mon + 1;
    if (month > 0 && month < 10) {
        formattedDate.append("0");
    }

    formattedDate.append(std::to_string(month));
    formattedDate.append("-");
    formattedDate.append(std::to_string(date->tm_mday));

    return formattedDate;
}

std::string hashPassword(std::string password) {
    unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int hashLength;

    EVP_MD_CTX* context = EVP_MD_CTX_new();
    EVP_DigestInit_ex(context, EVP_sha256(), nullptr);
    EVP_DigestUpdate(context, password.c_str(), password.length());
    EVP_DigestFinal_ex(context, hash, &hashLength);
    EVP_MD_CTX_free(context);

    std::string hashedPassword;
    for (unsigned int i = 0; i < hashLength; i++) {
        char buffer[3];
        sprintf(buffer, "%02x", hash[i]);
        hashedPassword += buffer;
    }

    return hashedPassword;
}
int birth_dateChecker(int userDay, int userMonth, int userYear, tm birth_date) {
    int running = 0;
    time_t t = time(NULL);
    tm* now = localtime(&t);
    time_t raw_time = mktime(&birth_date);
    int current_year = now->tm_year + 1900;
    if (userYear < 1900 || userYear > (current_year) || userDay < 1 ||
        userDay > 31 || userMonth < 1 || userMonth > 12 || raw_time == -1) {
        std::cout << "Nespravne datum" << std::endl;
        running = 1;
        return running;
    } else if (userYear > (current_year - 15)) {
        std::cout << "Nemas dostatecny vek pro otevreni uctu" << std::endl;
        running = 1;
        return running;
    }

    return running;
}
int phone_numberChecker(std::string phone_number) {
    int running = 0;
    int digitCount = 0;
    for (char c : phone_number) {
        if (std::isdigit(c)) {
            digitCount++;
        } else if (c != '+' && c != '-' && c != ' ' && c != '(' && c != ')') {
            std::cout << "Neplatne telefonni cislo" << std::endl;
            running = 1;
            return running;
        }
        if (digitCount >= 7 && digitCount <= 15) {
            std::cout << "Neplatne telefonni cislo" << std::endl;
            running = 1;
            return running;
        }
    }
    return running;
}
int emailChecker(std::string email) {
    int running = 0;
    size_t findAt = email.find('@');
    size_t findDot = email.find('.');
    if (findAt == email.npos || findDot == email.npos) {
        std::cout << "Spatne zadany email" << std::endl;
        running = 1;
        return running;
    }
    if (email.empty()) {
        std::cout << "Spatne zadany email" << std::endl;
        running = 1;
        return running;
    }
    if (email.back() == '.' || email.back() == '@') {
        std::cout << "Spatne zadany email" << std::endl;
        running = 1;
        return running;
    }
    if (email[0] == '.') {
        std::cout << "Spatne zadany email" << std::endl;
        running = 1;
        return running;
    }
    for (int i = 0; i < email.length() - 1; i++) {
        if (email[i] == '.' && email[i + 1] == '.' ||
            email[i] == '.' && email[i + 1] == '@' ||
            email[i] == '@' && email[i + 1] == '.') {
            std::cout << "Spatne zadany email" << std::endl;
            running = 1;
            return running;
        }
    }
    std::string username = email.substr(0, findAt);
    std::string domain = email.substr(findAt + 1);
    for (char c : username)
    {
        if(c == '?' || c == '!' || c == '"' || c == ':' || c == '(' || c == ')' || c == ',' || c == ';' || c == ']' | c == '[' || c == '@' || c == '<' || c == '>')
        {
            std::cout << "Spatne zadany email" << std::endl;
            running = 1;
            return running;
        }
    }
    
    return running;
}
