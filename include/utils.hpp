#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

void printVoidLine();
int printStart();
int printMenu();
std::string generateAccountDetail(std::vector<std::string> accountDetails);
int passwordChecker(std::string password);
std::string formatDate(tm* date);
std::string hashPassword(std::string password);
int birth_dateChecker(int userDay, int userMonth, int userYear, tm birth_date);
int phone_numberChecker(std::string phone_number);
int emailChecker(std::string email);
#endif