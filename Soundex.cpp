#include <iostream>
#include <vector>
#include <string>

std::vector<char> delete_symbol =
{
	'a', 'e', 'h', 'i', 'o', 'u', 'w', 'y'
};



//
std::string d_symbol(const std::string word) {
	//
	std::string new_word;

	for (int index = 0; index < word.size(); index++)
	{
		bool b_delete = true;

		if (index == 0)
		{
			new_word += word[index];
		}
		else
		{
			for (int index_in = 0; index_in < delete_symbol.size(); index_in++)
			{

				if (word[index] == delete_symbol[index_in])
				{
					b_delete = false;
				}
			}

			if (b_delete)
			{
				std::cout << "\x1b[0;32mYES\x1b[0;37m" << std::endl;
				new_word += word[index];
			}


		}

	}

	return new_word;
}


//
std::string sound_in_number(const std::string new_word)
{
	std::string new_word_in_numder;

	for (int index = 0; index < new_word.size(); index++)
	{
		if (index == 0)
		{
			new_word_in_numder += new_word[0];
		}
		else
		{
			if ((new_word[index] == 'b') || (new_word[index] == 'f')
				|| (new_word[index] == 'p') || (new_word[index] == 'v'))
			{
				new_word_in_numder += '1';
			}
			if ((new_word[index] == 'c') || (new_word[index] == 'g')
				|| (new_word[index] == 'j') || (new_word[index] == 'k')
				|| (new_word[index] == 'q') || (new_word[index] == 's')
				|| (new_word[index] == 'x') || (new_word[index] == 'z'))
			{
				new_word_in_numder += '2';
			}
			if ((new_word[index] == 'd') || (new_word[index] == 't'))
			{
				new_word_in_numder += '3';
			}
			if (new_word[index] == 'l')
			{
				new_word_in_numder += '4';
			}
			if ((new_word[index] == 'm') || (new_word[index] == 'n'))
			{
				new_word_in_numder += '5';
			}
			if (new_word[index] == 'r')
			{
				new_word_in_numder += '6';
			}
		}
	}
	return new_word_in_numder;
}

std::string end_step(std::string new_word_in_numder)
{
	std::string end_word;

	for (int index = 0; index < new_word_in_numder.size(); index++)
	{
		for (int index_in = new_word_in_numder.size(); index_in > -1; index_in--)
		{
			if (new_word_in_numder[index_in] == new_word_in_numder[index_in - 1])
			{
				new_word_in_numder.pop_back();
			}
		}
	}
	return new_word_in_numder;
}

std::string limits_size(std::string new_word_in_numder)
{
	if (new_word_in_numder.size() == 4)
	{
		return new_word_in_numder;
	}
	if (new_word_in_numder.size() < 4)
	{
		for (int limits = 0; limits < 5; limits++)
		{
			new_word_in_numder += '0';
		}
	}
	if (new_word_in_numder.size() > 4)
	{
		for (int limits = new_word_in_numder.size(); limits > 3; limits--)
		{
			new_word_in_numder.pop_back();
		}
	}
	return new_word_in_numder;
}


int main()
{
	std::string word_1;
	std::cin >> word_1;
	std::cout << limits_size(end_step(sound_in_number(d_symbol(word_1))));
}