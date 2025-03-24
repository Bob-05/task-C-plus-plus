/*
ln 2



Ограничение времени: 1 с
Ограничение памяти: 64.0 Мб
Ввод: стандартный ввод или input.txt
Вывод: стандартный вывод или output.txt


Условие:
Значение натурального логарифма ln 2 представляется в виде суммы 1-(1/2)+(1/3)-(1/4)+...+((-1)^(n+1)/n) с точностью до O(n).
Напишите программу, выводящую сумму первых n членов этого ряда. Попробуйте также обойтись без использования инструкции if.

Формат ввода:
Вводится целое положительное число n, помещающееся в тип int.

Формат вывода:
Программа выводит ответ на задачу.
*/

#include <iostream>

double exponentiation(double number, double degree)
{
    double cop_number = number;
	for(double a = 1; a < degree; a++)
	{
		number = cop_number * number;
		//std::cout << "\t1-я итерация - " << number << std::endl;
	}
	return number;
}

int main()
{
	double sum = 0;
	double nr = 0;

	std::cin >> nr;

	for(double limits = 1; limits <= nr; ++limits) {

		sum += (exponentiation( (-1), 1+limits)) / limits;
		/*std::cout <<
		          "sum: " <<
		          sum <<
		          "\nexponentiation: " <<
		          exponentiation( (-1), 1+limits) <<
		          std::endl;*/
	}
	std::cout << sum;
}