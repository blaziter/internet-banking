#include "account.hpp"

#include <iostream>
#include <string>

Account::Account(int user_id, std::string account_number, int balance) {
    this->user_id = user_id;
    this->account_number = account_number;
    this->balance = balance;
}
void Account::setBalance(int balance) { this->balance = balance; }
