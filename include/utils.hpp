#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

void printVoidLine();
int printStart();
int printMenu();
std::string generateAccountDetail(std::vector<std::string> accountDetails);
bool passwordChecker(std::string password);
std::string formatDate(tm date);
std::string hashPassword(std::string password);
bool birth_dateChecker(int userDay, int userMonth, int userYear, tm birth_date);
bool phone_numberChecker(std::string phone_number);
bool emailChecker(std::string email);
#endif