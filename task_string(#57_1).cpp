/*
Write a program that asks the user to enter their first name, last name, and age. 
As a result, inform the user how many years they have lived for each letter in their first and last name (to make it easier, also consider spaces).
*/



#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter your full name -> ";
    std::string userName;
    std::getline(std::cin, userName);
    //std::cin.ignore(32767, '\n');
    std::cout << "Enter your age -> ";
    int userAge;
    std::cin >> userAge;

    std::cout << "For every letter of your last name and first name, you have lived \x1b[1;33m" <<
        userName.length() / double(userAge) << "\x1b[0;37m for years";

    return 0;
}