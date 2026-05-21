#ifndef AUTH_H
#define AUTH_H

#include <string>

#include "user.hpp"

bool registration(const std::string& email, const std::string& phone_number, User& newUser);
bool login();

#endif