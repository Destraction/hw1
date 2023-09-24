#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
/*
1) strlen - в языке C считает, сколько символов в строке. Аналог в C++ - length()
2) strcpy - Функция strcpy копирует strSource, включая завершающий символ нуля, в указанное расположение.  В C++ то же самое
3) strcmp - сравнивает поочередно каждую пару символов, и продолжается это до тех пор, пока не будут найдены различные символы или не будет достигнут конец строки. В C++ то же самое
4) strcat - Объединяет две строки в языке C. В C++ то же самое.
5) someString[index] - … (getting the character at index) Получить доступ к строке и её символу по индексу. В c++
6) Добавить элемент в конец списка в C++ - push_back. В C реализуется, но нет специального обозначения.
7) Удалить элемент из конца списка в C++ - pop_back. В C реализуется, но нет специального обозначения.
Вывод: В C++ было добавлено множество синтаксических конструкций, которые делают нашу работу со строками гораздо проще и удобнее.
*/
int main()
{
	setlocale(LC_ALL, "RUS");
	string ReplaceAll(string str, const string&  from, const string & to);
	string str, str2=" 0123456789";
	int i, size;
	char help;
	cout << "Введите строку" << endl;
	getline(cin, str);
	str = ReplaceAll(str, string(","), string(""));
	str = ReplaceAll(str, string(" "), string(""));
	str = ReplaceAll(str, string("."), string(""));
	str = ReplaceAll(str, string("!"), string(""));
	str = ReplaceAll(str, string("?"), string(""));
	str = ReplaceAll(str, string("-"), string(""));
	size = str.length();
	for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size - 1; ++j) {
				if (str[j] > str[j + 1]) {
					help = str[j];
						str[j] = str[j + 1];
						str[j + 1] = help;
				}
			}
		}
	cout << str << endl;
	return 0;
}
string ReplaceAll(string str, const string& from, const string& to) {
	size_t start_pos = 0;
	while ((start_pos = str.find(from, start_pos)) != string::npos) {
		str.replace(start_pos, from.length(), to);
		start_pos += to.length();
	}
	return str;
}