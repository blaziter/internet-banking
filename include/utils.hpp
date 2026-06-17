#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

void printVoidLine();
int printStart();
int printMenu();
std::string generateAccountDetail(std::vector<std::string> accountDetails);
bool passwordChecker(const std::string& password);
std::string formatDate(tm date);
tm getTmFromDateString(const std::string& dateString);
std::string hashPassword(const std::string& password);
bool birth_dateChecker(int userDay, int userMonth, int userYear, tm birth_date);
bool phone_numberChecker(const std::string& phone_number);
bool emailChecker(const std::string& email);
std::string changePassword(const std::string& password);
std::string changeEmail(const std::string& email);
std::string changePhoneNumber(const std::string& phone_number);
std::string changeAdress(const std::string& adress);
std::string changeFirstName(const std::string& first_name);
std::string changeLastName(const std::string& last_name);
#endif