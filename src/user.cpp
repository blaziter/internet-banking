#include "user.hpp"
#include "utils.hpp"
#include "password.hpp"
#include <iostream>
#include <string>

/* User::User(std::string first_name, std::string last_name, std::string adress, std::string email, int phone_number, std::string password, tm birth_date)
: first_name(first_name), last_name(last_name), adress(adress), email(email), phone_number(phone_number), password(password), birth_date(birth_date) {}
 */User User::createAccount()
{
    std::string first_name;
    std::string last_name;
    std::string adress;
    std::string email;
    int phone_number;
    std::string password;
    tm birth_date;
    int running = 0;

    std::cout << "Zadej jmeno:" << std::endl;
    std::cin >> first_name;
    printVoidLine();
    std::cout << "Zadej prijmeni:" << std::endl;
    std::cin >> last_name;
    printVoidLine();
    std::cout << "Zadej adresu:" << std::endl;
    std::getline (std::cin >> std::ws, adress);
    printVoidLine();
    std::cout << "Zadej svuj email:" << std::endl;
    std::cin >> email;
    printVoidLine();
    std::cout << "Zadej svoje tel. cislo:" << std::endl;
    std::cin >> phone_number;
    printVoidLine();
    do 
    {
    std::cout << "Zadej svoje heslo do aplikace(Heslo musi byt 12 a vice znaku, musi obsahovat mala a velka pismena a cislice):" << std::endl;
    std::cin >> password;
    running = passwordChecker(password);
    } while(running = 1);
    
    printVoidLine();
    std::cout << "Zadej den sveho narozeni" << std::endl;
    std::cin >> birth_date.tm_mday;
    printVoidLine();
    std::cout << "Zadej mesic sveho narozeni" << std::endl;
    std::cin >> birth_date.tm_mon;
    printVoidLine();
    std::cout << "Zadej rok sveho narozeni" << std::endl;
    std::cin >> birth_date.tm_year;
    printVoidLine();


    return User(first_name, last_name, adress, email, phone_number, password, birth_date);
}