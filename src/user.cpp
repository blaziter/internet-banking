#include "user.hpp"

#include <iostream>
#include <string>

#include "utils.hpp"

User::User(std::string first_name, std::string last_name, std::string adress,
           std::string email, std::string phone_number, std::string password,
           tm birth_date) {
    this->first_name = first_name;
    this->last_name = last_name;
    this->adress = adress;
    this->email = email;
    this->phone_number = phone_number;
    this->password = password;
    this->birth_date = birth_date;
}

User User::createAccount() {
    std::string first_name;
    std::string last_name;
    std::string adress;
    std::string email;
    std::string phone_number;
    std::string password;
    tm birth_date = {};
    int running = 0;

    std::string confirmPassword;

    std::cout << "Zadej jmeno:" << std::endl;
    std::cin >> first_name;
    printVoidLine();

    std::cout << "Zadej prijmeni:" << std::endl;
    std::cin >> last_name;
    printVoidLine();

    std::cout << "Zadej adresu:" << std::endl;
    std::getline(std::cin >> std::ws, adress);
    printVoidLine();
    do {
        std::cout << "Zadej svuj email:" << std::endl;
        std::cin >> email;
    } while (emailChecker(email) != true);

    printVoidLine();
    do {
        std::cout << "Zadej svoje tel. cislo (i s predcislim napr +420, +80):"
                  << std::endl;

        std::cin >> phone_number;
    } while (phone_numberChecker(phone_number) != true);

    printVoidLine();

    do {
        std::cout << "Zadej svoje heslo do aplikace(Heslo musi byt 12 a vice "
                     "znaku, musi obsahovat mala a velka pismena a cislice):"
                  << std::endl;
        std::cin >> password;
        std::cout << "Zadej heslo znovu pro potvrzeni:" << std::endl;
        std::cin >> confirmPassword;

        if (confirmPassword.compare(password) != 0) {
            std::cout << "Hesla se neshoduji, zadej heslo znovu" << std::endl; 
        }
    } while (passwordChecker(password) != true || confirmPassword.compare(password) != 0);

    int userDay;
    int userMonth;
    int userYear;
    printVoidLine();
    do {
        std::cout << "Zadej den sveho narozeni" << std::endl;
        std::cin >> userDay;
        printVoidLine();

        std::cout << "Zadej mesic sveho narozeni" << std::endl;
        std::cin >> userMonth;
        printVoidLine();

        std::cout << "Zadej rok sveho narozeni" << std::endl;
        std::cin >> userYear;
        printVoidLine();
        birth_date.tm_mday = userDay;
        birth_date.tm_mon = userMonth - 1;
        birth_date.tm_year = userYear - 1900;
    } while (birth_dateChecker(userDay, userMonth, userYear, birth_date) != true);

    return User(first_name, last_name, adress, email, phone_number, password,
                birth_date);
}

std::string User::getFirstName() { return this->first_name; }

std::string User::getLastName() { return this->last_name; }

std::string User::getAdress() { return this->adress; }

std::string User::getEmail() { return this->email; }

std::string User::getPhoneNumber() { return this->phone_number; }

void User::setAccountDetail(std::string account_detail) {
    this->account_detail = account_detail;
}
std::string User::getAccountDetail() { return this->account_detail; }

std::string User::getPassword() { return this->password; }

tm User::getBirthDate() { return this->birth_date; }
