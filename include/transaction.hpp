#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <ctime>
#include <string>
class Transaction {
   public:
    enum type {
        TRANSFER = 1,
        DEPOSIT = 2,
        WITHDRAWAL = 3,
        PAYMENT = 4,
        OTHER = 5
    };

   private:
    int transaction_id;
    std::string sender_account;
    std::string receiver_account;
    double amount;
    tm date;
    type transaction_type;

   public:
    Transaction(int transaction_id, std::string sender_account,
                std::string receiver_account, double amount, tm date,
                type transaction_type);
    void transactionDetails();
    int getTransactionId();
    std::string getSenderAccount();
    std::string getReceiverAccount();
    double getAmount();
    tm getDate();
    type getTransactionType();
    void setTransactionId(int transaction_id);
    void setSenderAccount(std::string sender_account);
    void setReceiverAccount(std::string receiver_account);
    void setAmount(double amount);
    void setTransactionType(type transaction_type);
    void transferMoney(std::string sender_account, std::string receiver_account,
                       double amount);
};
#endif