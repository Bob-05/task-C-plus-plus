#include <iostream>
#include <string>

std::string reverse_order_string (std::string reverse_order_string)
{
    std::string usual_order;
    for(size_t index = reverse_order_string.size() - 1; index + 1 != 0; --index)
    {
        if(reverse_order_string[index] != ' ')
        {
            usual_order += reverse_order_string[index];
        }
    }
    return usual_order;
}


std::string no_whitespace(std::string user_string)
{
    std::string user_string_no_whitespace;
    for(size_t index = 0; index != user_string.size(); ++index)
    {
        if(user_string[index] != ' ')
        {
            user_string_no_whitespace+=user_string[index];
        }
    }
    return user_string_no_whitespace;
}


int main() 
{
    std::string reverse_order_string1;
    std::getline(std::cin, reverse_order_string1);

    //std::cout << " -- " << reverse_order_string(reverse_order_string1) << std::endl;
    //std::cout << " -- " << no_whitespace(reverse_order_string1) << std::endl;
    if(reverse_order_string(reverse_order_string1) == no_whitespace(reverse_order_string1))
    {
        std::cout << "YES";
    }
    else
    {
        std::cout << "NO";
    }
}