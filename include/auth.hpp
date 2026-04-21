#ifndef AUTH_H
#define AUTH_H

#include <string>

#include "user.hpp"

bool registration(std::string email, std::string phone_number, User newUser);
bool login();
bool authenticate();

#endif