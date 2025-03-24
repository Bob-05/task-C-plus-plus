/*
Количество дней в месяце


Ограничение времени: 1 с
Ограничение памяти: 64.0 Мб
Ввод: стандартный ввод или input.txt
Вывод: стандартный вывод или output.txt

Условие:
Напишите программу, выводящую количество дней в месяце по заданному номеру месяца и году.

Формат ввода:
На вход программе подается два целых положительных числа: номер месяца (от 1 до 12) и четырёхзначный год.

Формат вывода:
Необходимо вывести одно число — количество дней в заданном месяце.
*/

#include <iostream> 

int main() {
    const  short int month_of_the_year= 13;
    
   int year_m[month_of_the_year] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    short int month;
    int year = 0;
    std::cin >> month >> year;
if (year % 100 == 0 && year % 400 == 0){
if (month == 2){
    std::cout << 1 + year_m[month] << std::endl;
} else {
    std::cout << year_m[month] << std::endl;
}
    // std::cout << "YES\n";
}else if(year%4 == 0 && year % 100 != 0){
    if (month == 2){
    std::cout << 1 + year_m[month] << std::endl;
} else {
    std::cout << year_m[month] << std::endl;
}
      //  std::cout << "YES\n";
    } else {
        std::cout << year_m[month] << std::endl;
       // std::cout << "NO\n";
    }
}