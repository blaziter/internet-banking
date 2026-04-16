#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <ctime>
#include <string>
class Transaction {
   private:
    int transaction_id;
    int sender_account;
    int receiver_account;
    double amount;
    tm date;

   public:
    Transaction(int transaction_id, int sender_account, int receiver_account,
                double amount, tm date) {}
    void transactionDetails();
};
#endif