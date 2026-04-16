#include <iostream>
#include <string>

#include "user.hpp"
#include "utils.hpp"

User::User(std::string first_name, std::string last_name, std::string adress,
           std::string email, std::string phone_number, std::string password,
           tm* birth_date) {
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
    tm* birth_date = new tm();
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

    std::cout << "Zadej svuj email:" << std::endl;
    std::cin >> email;
    printVoidLine();

    std::cout << "Zadej svoje tel. cislo:" << std::endl;
    std::cin >> phone_number;
    printVoidLine();

    do {
        std::cout << "Zadej svoje heslo do aplikace(Heslo musi byt 12 a vice "
                     "znaku, musi obsahovat mala a velka pismena a cislice):"
                  << std::endl;
        std::cin >> password;
        running = passwordChecker(password);
        std::cout << "Zadej heslo znovu pro potvrzeni:" << std::endl;
        std::cin >> confirmPassword;

        if (confirmPassword.compare(password) != 0) {
            std::cout << "Hesla se neshoduji, zadej heslo znovu" << std::endl;
            running = 1;
        }

        running = 0;
    } while (running == 1);

    printVoidLine();
    std::cout << "Zadej den sveho narozeni" << std::endl;
    std::cin >> birth_date->tm_mday;
    printVoidLine();

    std::cout << "Zadej mesic sveho narozeni" << std::endl;
    std::cin >> birth_date->tm_mon;
    printVoidLine();

    std::cout << "Zadej rok sveho narozeni" << std::endl;
    std::cin >> birth_date->tm_year;
    printVoidLine();

    return User(first_name, last_name, adress, email, phone_number, password,
                birth_date);
}