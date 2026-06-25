#ifndef USER_H
#define USER_H

#include <ctime>
#include <string>
class User {
   private:
    tm created_at = {};
    tm updated_at = {};
    int user_id;
    std::string first_name;
    std::string last_name;
    std::string adress;
    std::string email;
    std::string phone_number;
    std::string password;
    tm birth_date = {};
    std::string account_detail;

   public:
    User(const std::string& first_name, const std::string& last_name,
         const std::string& adress, const std::string& email,
         const std::string& phone_number, const std::string& password,
         tm birth_date);

    User(const std::string& first_name, const std::string& last_name,
         const std::string& adress, const std::string& email,
         const std::string& phone_number, const std::string& password,
         const std::string& account_detail, tm birth_date);

    User createAccount();

    std::string getFirstName();

    std::string getLastName();

    std::string getAdress();

    std::string getEmail();

    std::string getPhoneNumber();

    void setAccountDetail(const std::string& account_detail);

    std::string getAccountDetail();

    std::string getPassword();

    tm getBirthDate();
};
#endif