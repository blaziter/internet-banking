#include "transaction.hpp"

#include <SQLiteCpp/Statement.h>
#include <SQLiteCpp/Transaction.h>
#include <time.h>

#include <iostream>
#include <string>
#include <vector>

#include "db.hpp"
#include "utils.hpp"

Transaction::Transaction(int transaction_id, tm created_at,
                         const std::string& sender_account,
                         const std::string& receiver_account, double amount,
                         type transaction_type) {
    this->transaction_id = transaction_id;
    this->created_at = created_at;
    this->sender_account = sender_account;
    this->receiver_account = receiver_account;
    this->amount = amount;
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

tm Transaction::getCreated_at() { return created_at; }

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

/**
 * @author "Petr Tran(petr.tran@unob.cz)"
 * @brief Transfer money from one account to another. It checks if the sender
 * and receiver exists, and if the sender has enough balance and then records
 * the transaction in the database.
 * @param sender_account The account number of the sender.
 * @param receiver_account The account number of the receiver.
 * @param amount The amount of money to transfer.
 */
void Transaction::transferMoney(const std::string& sender_account,
                                const std::string& receiver_account,
                                double amount) {
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
            db, "UPDATE account SET balance = ? WHERE account_id = ?;");
        updateSenderBalance.bind(1, senderBalance - amount);
        updateSenderBalance.bind(2, sender_account);
        updateSenderBalance.exec();

        SQLite::Statement updateReceiverBalance(
            db, "UPDATE account SET balance = ? WHERE account_id = ?;");
        updateReceiverBalance.bind(1, receiverBalanceValue + amount);
        updateReceiverBalance.bind(2, receiver_account);
        updateReceiverBalance.exec();

        SQLite::Statement insertTransaction(
            db,
            "INSERT INTO transaction (transaction_id, sender_account, "
            "receiver_account, amount, transaction_type) VALUES (?, ?, "
            "?, ?, ?);");

        insertTransaction.bind(1, nullptr);
        insertTransaction.bind(2, sender_account);
        insertTransaction.bind(3, receiver_account);
        insertTransaction.bind(4, amount);
        insertTransaction.bind(5, Transaction::TRANSFER);
        insertTransaction.exec();

        transaction.commit();
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
};

/**
 * @author "Petr Tran(petr.tran@unob.cz)"
 * @brief Get transactions for a given account number and date range, and stores
 * them in the provided vector.
 * @param transactions A pointer to a vector where the retrieved transactions
 * will be stored.
 * @param account_number The account number for which to retrieve transactions.
 * @param start_date The start date of the date range for which to retrieve
 * transactions (in "YYYY-MM-DD" format).
 * @param end_date The end date of the date range for which to retrieve
 * transactions (in "YYYY-MM-DD" format).
 */
void Transaction::getTransactionsByDate(std::vector<Transaction>* transactions,
                                        const std::string& account_number,
                                        const std::string& start_date,
                                        const std::string& end_date) {
    SQLite::Database& db = Database::getInstance().getDb();
    try {
        SQLite::Statement selectTransactions(
            db,
            "SELECT * FROM transaction WHERE (sender_account = ? OR "
            "receiver_account = ?) AND created_at BETWEEN ? AND ?;");

        selectTransactions.bind(1, account_number);
        selectTransactions.bind(2, account_number);
        selectTransactions.bind(3, start_date);
        selectTransactions.bind(4, end_date);

        while (selectTransactions.executeStep()) {
            transactions->push_back(Transaction(
                selectTransactions.getColumn("transaction_id").getInt(),
                getTmFromDateString(
                    selectTransactions.getColumn("date").getString()),
                selectTransactions.getColumn("sender_account").getString(),
                selectTransactions.getColumn("receiver_account").getString(),
                selectTransactions.getColumn("amount").getDouble(),
                Transaction::type(
                    selectTransactions.getColumn("transaction_type")
                        .getInt())));
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}
