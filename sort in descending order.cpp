#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::vector <std::string> w_string;
    std::string string1;
    while (std::getline(std::cin, string1))
    {
        w_string.push_back(string1);
    }

    std::sort(w_string.rbegin(), w_string.rend());

    for (std::string elem : w_string)
    {
        std::cout << elem << std::endl;
    }
}