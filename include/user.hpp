#ifndef USER_H
#define USER_H
#include <string>
#include <ctime>
class User
{
    private:
    std::string first_name;
    std::string last_name;
    std::string adress;
    std::string email;
    int phone_number;
    std::string password;
    tm birth_date;
    std::string account_detail;

    public:

    User() {}

    User(std::string first_name, std::string last_name, std::string adress, std::string email, int phone_number, std::string password, tm birth_date)
    {
        this -> first_name = first_name;
        this -> last_name = last_name;
        this -> adress = adress;
        this -> email = email;
        this -> phone_number = phone_number;
        this -> password = password;
        this -> birth_date = birth_date;
    }
    
    User createAccount();
};
#endif