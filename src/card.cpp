#include "card.hpp"

#include <iostream>
#include <string>

Card::Card(int card_number, tm expiry_date, unsigned char status,
           unsigned char security_number) {
    this->card_number = card_number;
    this->expiry_date = expiry_date;
    this->status = status;
    this->security_number = security_number;
}
void Card::cardDetails() {//*generate card number, security number*//}