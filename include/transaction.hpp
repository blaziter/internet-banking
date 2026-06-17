#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <ctime>
#include <string>
#include <vector>

class Transaction {
   public:
    enum type : int {
        TRANSFER = 1,
        DEPOSIT = 2,
        WITHDRAWAL = 3,
        PAYMENT = 4,
        OTHER = 5
    };

   private:
    int transaction_id;
    tm created_at;
    std::string sender_account;
    std::string receiver_account;
    double amount;
    tm date;
    type transaction_type;

   public:
    Transaction(int transaction_id, tm date, const std::string& sender_account,
                const std::string& receiver_account, double amount,
                type transaction_type);

    void transactionDetails();
    int getTransactionId();
    std::string getSenderAccount();
    std::string getReceiverAccount();
    double getAmount();
    tm getCreated_at();
    type getTransactionType();

    void setTransactionId(int transaction_id);
    void setSenderAccount(const std::string& sender_account);
    void setReceiverAccount(const std::string& receiver_account);
    void setAmount(double amount);
    void setTransactionType(type transaction_type);

    void transferMoney(const std::string& sender_account,
                       const std::string& receiver_account, double amount);
    static void getTransactionsByDate(std::vector<Transaction>* transactions,
                                      const std::string& account_number,
                                      const std::string& start_date,
                                      const std::string& end_date);
};

#endif