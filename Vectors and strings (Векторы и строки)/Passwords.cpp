/*
Пароли


Ограничение времени: 1 с
Ограничение памяти: 64.0 Мб
Ввод: стандартный ввод или input.txt
Вывод: стандартный вывод или output.txt

Условие:
Пароль от некоторого сервиса должен удовлетворять таким ограничениям:
	1) состоять из символов таблицы ASCII с кодами от 33 до 126;
	2) быть не короче 8 символов и не длиннее 14;
	3) из 4 классов символов — большие буквы, маленькие буквы, цифры, прочие символы — в пароле должны присутствовать не менее трёх любых.
Напишите программу, которая проверит, что введённый пароль подходит под эти ограничения.

Формат ввода:
На входе дана одна строка с паролем.

Формат вывода:
Выведите YES, если пароль удовлетворяет требованиям, и NO в противном случае.
*/


#include <iostream>
#include <string>

//Символы пароля должны быть в диапозоне значений по ASCII [33;126]
bool ASCII (std::string password)
{
    //счётчик 
    int sum(0);
    for(char elem: password)
    {
        if (static_cast<int>(elem) >=33 && static_cast<int>(elem) <= 126){
            sum ++;
        }
    }
    return (sum == (int)password.size());
}

bool limits(std::string password)
{
    int large_latter = 0;
    int small_latter = 0;
    int number = 0;
    int symbol = 0;
    
    // Считаем классы символов
    for (char elem : password)
    {
        // Если данный элемент является символом
        if ((elem >= '!' && elem <= '/') || (elem >= ':' && elem <= '@') ||
            (elem >= '[' && elem <= '`') || (elem >= '{' && elem <= '~'))
        {
            symbol++; 
           // std::cout << "\n\t\tsymbol\n";
        }
        
        // Если данный элемент является Большой буквой 
        if (elem >= 'A' && elem <= 'Z')
        {
            large_latter++; 
            //std::cout << "\n\t\tlarge_latter\n";
        }
        
        // Если данный элемент является маленькой буквой 
        if (elem >= 'a' && elem <= 'z')
        {
            small_latter++; 
            //std::cout << "\n\t\tsmall_latter\n";
        }
        
        // Если данный элемент является цифрой
        if (elem >= '0' && elem <= '9')
        {
            number++; 
           // std::cout << "\n\t\tnumber\n";
        }
    }
    
    // Пароль должен содержать как минимум 3-разнообразных класса из выше перечисленных
      return ((symbol > 0) + (large_latter > 0) + (small_latter > 0) + (number > 0) >= 3);
}


int main()
{
    std::string password;
    std::cin >> password;

  
    if (((password.size() >= 8) && (password.size() <= 14)) && ASCII(password) && limits(password)){
        std::cout << "YES" << std::endl;
    }
    else 
    {
        std::cout << "NO" << std::endl;
    }
}