#include <iostream>
#include "user.hpp"
#include "utils.hpp"
#include "account.hpp"

#define PROJECT_NAME "internet-banking"

/**
 * @authors Petr Tran <petr.tran@unob.cz>, Pavel Tomšík <pavel.tomsik2@unob.cz>
 * @brief The main function of the internet banking application.
 */
int main() {

    User myUser;

    myUser = myUser.createAccount();

    return 0;
}
