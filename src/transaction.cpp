#include "transaction.hpp"
#include "utils.hpp"

#include <iostream>
#include <string>

Transaction::Transaction(int transaction_id, int sender_account,
                         int receiver_account, double amount, tm date) {
    this->transaction_id = transaction_id;
    this->sender_account = sender_account;
    this->receiver_account = receiver_account;
    this->amount = amount;
    this->date = date;
}

void Transaction:: transactionDetails()
{
    int receiver_account;
    double amount;
    std:: cout << "Zadej cislo uctu prijemce:" << std::endl;
    std:: cin >> receiver_account;
    printVoidLine();
    std:: cout << "Zadej castku:" << std::endl;
    std:: cin >> amount;
}