#include "password.hpp"
#include <iostream>
#include <string>

int passwordChecker (std::string password)
{
    int running = 0;
    int letters = 0;
    int small_letters = 0;
    int big_letters = 0;
    int numbers = 0;
    for(int i = 0; i < password.length(); i++)
    {
        letters++;
        if (letters < 12)
        {
            std::cout << "Tvoje heslo je prilis kratke" << std::endl;
            running = 1;
            return running;
        }
        if (password[i] >= 48 && password[i] <= 57)
        {
            numbers++;
        }
        else if (password[i] >= 65 && password[i] <= 90)
        {
            big_letters++;
        }
        else if (password[i] >= 97 && password[i] <= 122)
        {
            small_letters++;
        }
        if (numbers == 0 || big_letters == 0 || small_letters == 0)
        {
            std::cout << "Tvoje heslo nesplnuje zadane pozadavky" << std::endl;
            running = 1;
            return running;
        }
        return running;
        
    }
}