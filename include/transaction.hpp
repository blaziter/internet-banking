#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <string>
#include <ctime>
class Transaction
{
    private:
    int transaction_id;
    int sender_account;
    int receiver_account;
    double amount;
    tm date;

    public:
    Transaction(int transaction_id, int sender_account, int receiver_account, double amount, tm date)
    {
        this -> transaction_id = transaction_id;
        this -> sender_account = sender_account;
        this -> receiver_account = receiver_account;
        this -> amount = amount;
        this -> date = date;
    }
    void transactionDetails();
};
#endif