#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <ctime>
#include <string>

class Account {
   private:
    tm created_at;
    tm updated_at;
    int account_id;
    int user_id;
    std::string account_detail;
    double balance;

   public:
    Account(int user_id, const std::string& account_detail, double balance);

    int getUserId();
    void setUserId(int user_id);

    std::string getAccountDetail();
    void setAccountDetail(const std::string& account_detail);

    double getBalance();
    void setBalance(double balance);
};

#endif
