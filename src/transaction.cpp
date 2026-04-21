#include "transaction.hpp"

#include <iostream>
#include <string>

#include "utils.hpp"

Transaction::Transaction(int transaction_id, std::string sender_account,
                         std::string receiver_account, double amount, tm date) {
    this->transaction_id = transaction_id;
    this->sender_account = sender_account;
    this->receiver_account = receiver_account;
    this->amount = amount;
    this->date = date;
}

void Transaction::transactionDetails() {
    std::string receiver_account;
    double amount;
    std::cout << "Zadej cislo uctu prijemce:" << std::endl;
    std::cin >> receiver_account;
    printVoidLine();
    std::cout << "Zadej castku:" << std::endl;
    std::cin >> amount;
}