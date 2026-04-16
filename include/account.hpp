#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <ctime>
#include <string>

class Account {
   private:
    int account_id;
    int user_id;
    tm created_at;

    tm updated_at;
    std::string account_number;
    int balance;

   public:
    Account(int user_id, std::string account_number, int balance) {}
    void setBalance(int balance);
};

#endif
