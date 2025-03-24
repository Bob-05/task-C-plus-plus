/*
Сортировка по убыванию


Ограничение времени: 1 с
Ограничение памяти: 64.0 Мб
Ввод: стандартный ввод или input.txt
Вывод: стандартный вывод или output.txt

Условие:
Вам даны строки текстового файла. Отсортируйте набор этих строк по убыванию.

Формат ввода:
Количество строк не превосходит 1000. Каждая строка состоит из символов ASCII с кодами от 32 до 126, длина строки не превосходит 100.

Формат вывода:
Напечатайте строки в отсортированном по убыванию порядке. Для сравнения строк друг с другом достаточно использовать стандартные операторы сравнения, определённые для std::string.

*/



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