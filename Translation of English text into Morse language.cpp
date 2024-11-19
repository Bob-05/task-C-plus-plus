//подкрючить поток ввода и вывода
#include<iostream>
 //подключить словарь map
#include<map>
// библиотека для работы со строками 
#include<string>
//файловый поток для доп. функции
#include <fstream>
// пространство имен std
using namespace std;



map <char, string> Morze = {
 {'A', ".-"},
	{'B', "-..."},{'C', "-.-."},{'D', "-.."},
	{'E', "."},{'F', "..-."},{'G', "--."},
	{'H', "...."},{'I', ".."},{'J', ".---"},
	{'K', "-.-"},{'L', ".-.."},{'M', "--"},
	{'N', "-."},{'O', "---"},{'P', ".--."},
	{'Q', "--.-"},{'R', ".-."},{'S', "..."},
	{'T', "-"},{'U', "..-"},{'V', "...-"},
	{'W', ".--"},{'X', "-..-"},{'Y', "-.--"},
	{'Z', "--.."},{'a', ".-"},{'b', "-..."},
	{'c', "-.-."},{'d', "-.."},{'e', "."},
	{'f', "..-."},{'g', "--."},{'h', "...."},
	{'i', ".."},{'j', ".---"},{'k', "-.-"},
	{'l', ".-.."},{'m', "--"},{'n', "-."},
	{'o', "---"},{'p', ".--."},{'q', "--.-"},
	{'r', ".-."},{'s', "..."},{'t', "-"},
	{'u', "..-"},{'v', "...-"},{'w', ".--"},
	{'x', "-..-"},{'y', "-.--"},{'z', "--.."},
};

//функция текст -/ слова
string MorzeLetter(char ch) {
	auto it = Morze.find(ch);
	if (it != Morze.end()) {
		return it->second;
	}
	return string(1, ch);
}

//функция слова -/ буквы
string MorzeWord(string& word) {
	string morzeWord;

	for (char ch : word) {

		morzeWord += MorzeLetter(ch) + " ";
	}
	return morzeWord;
}



//функция буквы -/ морзе += в общую переменную
string MorzeString(string& inputText) {
	string morze_text;
	string word;
	for (char ch : inputText) {
		if (ch == ' ') {
			word += ch;
			morze_text += MorzeWord(word) + "/";
			word = "";

		}
		else {
			word += ch;
		}
	}

	if (!word.empty()) {
		morze_text += MorzeWord(word);
	}
	return  morze_text;
}




int main() {
	//перевод консоли на русский язык 
	setlocale(LC_ALL, "rus");
	cout << "\x1b[1;32mПереводчик с Английского языка на язык Морзе.\x1b[0;37m\n";
	//перевод 
	string translation;

	//циклическое повторение программы
	while (true) {

		//ввод выражения и его сохранение 
		string inputText;
		cout << "\x1b[0;33mВведите текст или введите 'exit':\x1b[0;37m";

		//принимаем значение
		getline(cin, inputText);

		// Выйти/продолжить
		if (inputText == "exit" || inputText == "EXIT") {
			return 0;

		}

		//переводим полученный текст + выводим его
		translation = MorzeString(inputText);
		cout << "Перевод на Морзе:" << translation << endl;
	}
	return 0;
}
