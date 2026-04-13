#include "account.hpp"

#include <iostream>
#include <string>

/*Account::Account(int user_id, std::string account_detail, int balance)
    : user_id(user_id), account_detail(account_detail), balance(balance) {}
*/
void Account::setBalance(int balance) 
{ 
    this->balance = balance; 
    
}
