#ifndef USER_H
#define USER_H
#include <ctime>
#include <string>
class User {
   private:
    tm* created_at;
    tm* updated_at;
    int user_id;
    std::string first_name;
    std::string last_name;
    std::string adress;
    std::string email;
    std::string phone_number;
    std::string password;
    tm* birth_date;
    std::string account_detail;

   public:
    User(std::string first_name, std::string last_name, std::string adress,
         std::string email, std::string phone_number, std::string password,
         tm* birth_date);

    User createAccount();
};
#endif