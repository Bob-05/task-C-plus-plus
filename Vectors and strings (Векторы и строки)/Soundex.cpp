/*
Soundex


Ограничение времени: 1 с
Ограничение памяти: 64.0 Мб
Ввод: стандартный ввод или input.txt
Вывод: стандартный вывод или output.txt

Условие:
Известный алгоритм Soundex определяет, похожи ли два английских слова по звучанию. На вход он принимает слово и заменяет его на некоторый четырёх символьный код. Если коды двух слов совпадают, то слова, как правило, звучат похоже.

Вам требуется реализовать этот алгоритм. Он работает так:
	1) Первая буква слова сохраняется.
	2) В остальной части слова буквы a, e, h, i, o, u, w и y удаляются;
	3) Оставшиеся буквы заменяются на цифры от 1 до 6, причём похожим по звучанию буквам соответствуют одинаковые цифры:
		b, f, p, v: 1
		c, g, j, k, q, s, x, z: 2
		d, t: 3
		l: 4
		m, n: 5
		r: 6
	4) Любая последовательность идущих подряд одинаковых цифр сокращается до одной такой цифры.
	5) Итоговая строка обрезается до первых четырёх символов.
	6) Если длина строки получилась меньше четырёх символов, в конце добавляются нули.

Примеры:
ammonium → ammnm → a5555 → a5 → a500.
implementation → implmnttn → i51455335 → i514535 → i514.

Формат ввода:
На вход подаётся одно непустое слово из строчных латинских букв. Длина слова не превосходит 20 символов.

Формат вывода:
Напечатайте четырёхбуквенный код, соответствующий слову.
*/

#include <iostream>
#include <vector>
#include <string>

//
std::vector<char> delete_symbol =
{
	'a', 'e', 'h', 'i', 'o', 'u', 'w', 'y'
};



//
std::string d_symbol (const std::string word) {
	//
	std::string new_word;

	for(size_t index = 0; index < word.size(); index++)
	{
		bool b_delete = true;

		if(index == 0)
		{
			new_word+= word[index];
		}
		else
		{
			for (size_t index_in = 0; index_in < delete_symbol.size(); index_in++)
			{

				if(word[index] == delete_symbol[index_in])
				{
					b_delete = false;
				}
			}

			if(b_delete)
			{
				//std::cout << "\x1b[0;32mYES\x1b[0;37m" << std::endl;
				new_word += word[index];
			}


		}

	}

	return new_word;
}


//
std::string sound_in_number (const std::string new_word)
{
	std::string new_word_in_numder;

	for(size_t index = 0; index < new_word.size(); index++)
	{
		if(index==0)
		{
			new_word_in_numder += new_word[0];
		}
		else
		{
			if((new_word[index] == 'b') || (new_word[index] == 'f')
			        || (new_word[index] == 'p') || (new_word[index] == 'v'))
			{
				new_word_in_numder += '1';
			}
			if((new_word[index] == 'c') || (new_word[index] == 'g')
			        || (new_word[index] == 'j') || (new_word[index] == 'k')
			        || (new_word[index] == 'q') || (new_word[index] == 's')
			        || (new_word[index] == 'x') || (new_word[index] == 'z'))
			{
				new_word_in_numder += '2';
			}
			if((new_word[index] == 'd') || (new_word[index] == 't'))
			{
				new_word_in_numder += '3';
			}
			if(new_word[index] == 'l')
			{
				new_word_in_numder += '4';
			}
			if((new_word[index] == 'm') || (new_word[index] == 'n'))
			{
				new_word_in_numder += '5';
			}
			if(new_word[index] == 'r')
			{
				new_word_in_numder += '6';
			}
		}
	}
	return new_word_in_numder;
}

std::string end_step (std::string new_word_in_numder)
{

	for(unsigned int index = 0; index < new_word_in_numder.size(); index++)
	{
		for(int index_in = new_word_in_numder.size(); index_in > -1; index_in--)
		{
			if(new_word_in_numder[index_in] == new_word_in_numder[index_in - 1])
			{
				new_word_in_numder.pop_back();
			}
		}
	}
	return new_word_in_numder;
}

std::string limits_size(std::string new_word_in_numder) { 
    if (new_word_in_numder.size() == 4) { 
        return new_word_in_numder;  
    } 
    else if (new_word_in_numder.size() < 4) {   
        new_word_in_numder.append(4 - new_word_in_numder.size(), '0'); 
    } 
    else if (new_word_in_numder.size() > 4) { 
        new_word_in_numder.resize(4); 
    }  
    return new_word_in_numder; 
}


int main()
{
	std::string word_1;
	std::getline(std::cin, word_1);

	word_1 = d_symbol(word_1);
	word_1 = sound_in_number(word_1);
	word_1 = end_step(word_1);
	word_1 = limits_size(word_1);

	//end_step(sound_in_number(d_symbol(word_1)));
	std::cout << word_1;
}
