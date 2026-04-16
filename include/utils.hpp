#ifndef UTILS_H
#define UTILS_H

#include <string>

void printVoidLine();
int printStart();
int printMenu();
std::string generateAccountDetail();
int passwordChecker(std::string password);
std::string formatDate(tm* date);
std::string hashPassword(std::string password);

#endif