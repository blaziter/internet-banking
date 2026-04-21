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

#endif