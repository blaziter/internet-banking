#ifndef CARD_H
#define CARD_H

#include <ctime>

class Card {
   private:
    int card_number;
    tm expiry_date;
    unsigned char status;
    unsigned char security_number;

   public:
    Card(int card_number, tm expiry_date, unsigned char status,
         unsigned char security_number);
    void cardDetails();
};

#endif