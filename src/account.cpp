#include "account.hpp"

#include <iostream>
#include <string>

Account::Account(int user_id, const std::string& account_detail,
                 double balance) {
    this->user_id = user_id;
    this->account_detail = account_detail;
    this->balance = balance;
}

int Account::getUserId() { return this->user_id; }

void Account::setUserId(int user_id) { this->user_id = user_id; }

std::string Account::getAccountDetail() { return this->account_detail; }

void Account::setAccountDetail(const std::string& account_detail) {
    this->account_detail = account_detail;
}

double Account::getBalance() { return this->balance; }

void Account::setBalance(double balance) { this->balance = balance; }
