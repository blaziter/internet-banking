#ifndef CARD_H
#define CARD_H

#include <ctime>

class Card {
   public:
    enum status : unsigned char {
        ACTIVE = 1,
        BLOCKED = 2,
        EXPIRED = 3,
        LOST = 4,
        STOLEN = 5
    };

   private:
    int card_id;
    int account_id;
    int card_number;
    tm expiry_date;
    status card_status;
    unsigned short security_number;
    unsigned short pin;
    double day_limit;
    double month_limit;

   public:
    Card(int account_id, int card_number, tm expiry_date,
         status card_status, unsigned short security_number, unsigned short pin,
         double day_limit, double month_limit);

    int getCardId();
    void setCardId(int card_id);

    int getAccountId();
    void setAccountId(int account_id);

    int getCardNumber();
    void setCardNumber(int card_number);

    tm getExpiryDate();
    void setExpiryDate(tm expiry_date);

    status getCardStatus();
    void setCardStatus(status card_status);

    unsigned short getSecurityNumber();
    void setSecurityNumber(unsigned short security_number);

    unsigned short getPin();
    void setPin(unsigned short pin);

    double getDayLimit();
    void setDayLimit(double day_limit);

    double getMonthLimit();
    void setMonthLimit(double month_limit);
};

#endif