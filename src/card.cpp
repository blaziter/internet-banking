#include "card.hpp"

#include <iostream>
#include <string>

Card::Card(int account_id, int card_number, tm expiry_date,
           status card_status, unsigned short security_number,
           unsigned short pin, double day_limit, double month_limit) {
    this->account_id = account_id;
    this->card_number = card_number;
    this->expiry_date = expiry_date;
    this->card_status = card_status;
    this->security_number = security_number;
    this->pin = pin;
    this->day_limit = day_limit;
    this->month_limit = month_limit;
}

int Card::getCardId() { return this->card_id; }

void Card::setCardId(int card_id) { this->card_id = card_id; }

int Card::getAccountId() { return this->account_id; }

void Card::setAccountId(int account_id) { this->account_id = account_id; }

int Card::getCardNumber() { return this->card_number; }

void Card::setCardNumber(int card_number) { this->card_number = card_number; }

tm Card::getExpiryDate() { return this->expiry_date; }

void Card::setExpiryDate(tm expiry_date) { this->expiry_date = expiry_date; }

Card::status Card::getCardStatus() { return this->card_status; }

void Card::setCardStatus(status card_status) {
    this->card_status = card_status;
}

unsigned short Card::getSecurityNumber() { return this->security_number; }

void Card::setSecurityNumber(unsigned short security_number) {
    this->security_number = security_number;
}

unsigned short Card::getPin() { return this->pin; }

void Card::setPin(unsigned short pin) { this->pin = pin; }

double Card::getDayLimit() { return this->day_limit; }

void Card::setDayLimit(double day_limit) { this->day_limit = day_limit; }

double Card::getMonthLimit() { return this->month_limit; }

void Card::setMonthLimit(double month_limit) {
    this->month_limit = month_limit;
}
