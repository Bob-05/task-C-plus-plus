/*
ArgMax в матрице


Ограничение времени: 1 с
Ограничение памяти: 64.0 Мб
Ввод: стандартный ввод или input.txt
Вывод: стандартный вывод или output.txt

Условие:
Вам требуется написать на C++ функцию со следующим заголовком:
-------> std::pair<size_t, size_t> MatrixArgMax(const std::vector<std::vector<int>>& matrix);
Функция должна вернуть пару из индексов максимального элемента в матрице. Если максимальных элементов несколько, то нужно вернуть наименьшую такую пару.

Формат ввода:
В первой строке двумя числами n и k задан размер матрицы. В последующих n строках вводится числовая матрица в k столбцов.

Формат вывода:
Индекс строки и столбца максимального элемента в матрице.
*/

#include <iostream>
#include <vector>
#include <utility>



std::pair<size_t, size_t> MatrixArgMax(const std::vector<std::vector<int>>& matrix)
{
    int max_num = matrix[0][0];
    std::pair<size_t, size_t> p;

    for(size_t line = 0; line != matrix.size(); ++line)
    {
         for(size_t column = 0; column != matrix[0].size(); ++column)
         {
             if(max_num < matrix[line][column])
             {
                 max_num = matrix[line][column];
                 p = {line, column};
             }
         }
    }

    return p;

}