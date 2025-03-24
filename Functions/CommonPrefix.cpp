/*
Общий префикс


Ограничение времени: 1 с
Ограничение памяти: 64.0 Мб
Ввод: стандартный ввод или input.txt
Вывод: стандартный вывод или output.txt

Условие:
Напишите функцию для вычисления наибольшего общего префикса строк, переданных в векторе words:
-----> std::string CommonPrefix(const std::vector<std::string>& words);
Например, для пустого вектора функция должна вернуть пустую строку, а для вектора из строк "apple", "apricot" и "application" — строку "ap".

Примечание:
В решении не должно быть функции main: она будет в нашей тестирующей программе. Подключите необходимые библиотеки и напишите код функции CommonPrefix.
*/


#include <iostream>
#include <vector>




std::string CommonPrefix(const std::vector<std::string>& words)
{
    std::string prefiks = "";


    if (words.empty())
    {
        return prefiks;
    }

    for (size_t letter = 0; letter != words[0].size(); ++letter)
    {
        size_t couter = 0;
        for (size_t word = 0; word != words.size(); ++word)
        {
            if (word + 1 < words.size())
            {
                if (words[word + 1][letter] == words[word][letter])
                {
                    couter += 1;
                }
                else
                {
                    break;
                }
            }

            if (couter == words.size() - 1)
            {
                prefiks += words[word][letter];
                break;
            }
        }
        couter = 0;
    }
    return prefiks;
}
