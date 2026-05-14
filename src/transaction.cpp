#include "transaction.hpp"

#include <SQLiteCpp/Statement.h>
#include <SQLiteCpp/Transaction.h>
#include <time.h>

#include <iostream>
#include <string>

#include "db.hpp"
#include "utils.hpp"

Transaction::Transaction(int transaction_id, const std::string& sender_account,
                         const std::string& receiver_account, double amount, tm date,
                         type transaction_type) {
    this->transaction_id = transaction_id;
    this->sender_account = sender_account;
    this->receiver_account = receiver_account;
    this->amount = amount;
    this->date = date;
    this->transaction_type = transaction_type;
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

int Transaction::getTransactionId() { return transaction_id; }

std::string Transaction::getSenderAccount() { return sender_account; }

std::string Transaction::getReceiverAccount() { return receiver_account; }

double Transaction::getAmount() { return amount; }

tm Transaction::getDate() { return date; }

Transaction::type Transaction::getTransactionType() { return transaction_type; }

void Transaction::setTransactionId(int transaction_id) {
    this->transaction_id = transaction_id;
}

void Transaction::setSenderAccount(const std::string& sender_account) {
    this->sender_account = sender_account;
}

void Transaction::setReceiverAccount(const std::string& receiver_account) {
    this->receiver_account = receiver_account;
}

void Transaction::setAmount(double amount) { this->amount = amount; }

void Transaction::setTransactionType(type transaction_type) {
    this->transaction_type = transaction_type;
}

