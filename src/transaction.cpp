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

void Transaction::transferMoney(const std::string& sender_account,
                                const std::string& receiver_account, double amount) {
    if (sender_account == receiver_account) {
        std::cout << "Nelze prevest penize na stejny ucet" << std::endl;
        return;
    }

    if (amount <= 0) {
        std::cout << "Castka musi byt vetsi nez 0 Kc" << std::endl;
        return;
    }

    SQLite::Database& db = Database::getInstance().getDb();
    try {
        SQLite::Statement receiverBalance(db,
                                          "SELECT account_detail, balance FROM "
                                          "account WHERE account_id = ?;");
        receiverBalance.bind(1, receiver_account);

        double receiverBalanceValue = 0.0;

        if (receiverBalance.executeStep()) {
            if (receiverBalance.getColumn(0).getString().compare(
                    receiver_account) != 0) {
                std::cout << "Neplatne cislo uctu prijemce" << std::endl;
                return;
            }

            receiverBalanceValue = receiverBalance.getColumn(1).getDouble();
        }

        SQLite::Statement accountBalance(
            db, "SELECT balance FROM account WHERE account_id = ?;");
        double senderBalance = 0.0;

        accountBalance.bind(1, sender_account);

        if (accountBalance.executeStep()) {
            senderBalance = accountBalance.getColumn(0).getDouble();
        }

        if (senderBalance < amount) {
            std::cout << "Nedostatecny zustatek na uctu" << std::endl;
            return;
        }

        SQLite::Transaction transaction(db);

        SQLite::Statement updateSenderBalance(
            db,
            "UPDATE account SET balance = balance - ? WHERE account_id = ?;");
        updateSenderBalance.bind(1, amount);
        updateSenderBalance.bind(2, sender_account);
        updateSenderBalance.exec();

        SQLite::Statement updateReceiverBalance(
            db,
            "UPDATE account SET balance = balance + ? WHERE account_id = ?;");
        updateReceiverBalance.bind(1, amount);
        updateReceiverBalance.bind(2, receiver_account);
        updateReceiverBalance.exec();

        SQLite::Statement insertTransaction(
            db,
            "INSERT INTO transaction (transaction_id, sender_account, "
            "receiver_account, amount, date, transaction_type) VALUES (?, ?, "
            "?, ?, ?, ?);");

        tm date = {};
        time_t t = time(NULL);
        date = *localtime(&t);

        date.tm_year += 1900;

        insertTransaction.bind(1, nullptr);
        insertTransaction.bind(2, sender_account);
        insertTransaction.bind(3, receiver_account);
        insertTransaction.bind(4, amount);
        insertTransaction.bind(5, formatDate(date));
        insertTransaction.bind(6, Transaction::TRANSFER);
        insertTransaction.exec();

        transaction.commit();
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
};
