#include <iostream>
#include <cmath>
using namespace std;
int *mas(int &size);
double *mas2(int &size);
int main() {
	setlocale(LC_ALL, "RUS");
	int size = 100;
	int a;
	int num,b,z;
	double perc,dollar=0.;
	int* arr = mas(size);
	double* arr2 = mas2(size);
	for (z = 0; z < 9999; z++) {
		cout << "Введите цифру для продолжения работы со счётом" << endl << "1  если вы хотите открыть аккаунт;" << endl << "2 если вы хотите внести деньги на счёт;" << endl;
		cout << "3 если вы хотите полностью обнулить счёт" << endl << "4 если вы хотите удалить счёт" << endl << "5 если вы хотите вывести деньги со счёта" << endl;
		cout << "6 если вы хотите запросить баланс счёта" << endl << "7 если вы хотите вывести все доступные счета и их баланс" << endl;
		cin >> a;
		switch (a) {
		case 1: // создать аккаунт
			size += 1;
			arr = mas(size);
			arr2 = mas2(size);
			break;
		case 2: //внести деньги на счёт
			cout << "Введите номер счёта" << endl;
			cin >> num;
			cout << "Введите количество долларов, которые вы хотите внести на счёт" << endl;
			cin >> dollar;
			arr2[num - 1001] += round(dollar*100)/100;
			dollar = 0;
			num = 0;
			break;
		case 3: // Обнулить счёт
			cout << "Введите номер счёта, который вы хотите обнулить" << endl;
			cin >> num;
			arr2[num - 1001] = 0;
			cout << "Счёт обнулён" << endl;
			break;
		case 4: //Удалить аккаунт
			cout << "Введите номер аккаунта который вы хотите удалить" << endl;
			cin >> num;
			arr[num - 1001] = 0;
			arr2[num - 1001] = 0;
			break;
		case 5: //Вывести деньги со счёта
			cout << "Введите номер счёта, с которого вы хотите списать деньги" << endl;
			cin >> num;
			if (1000 <= num <= 1100) {
				cout << "Введите количество долларов, которые вы хотите снять со счёта" << endl;
				cin >> dollar;
				arr2[num - 1001] -= round(dollar * 100) / 100;
				dollar = 0.;
				num = 0;
				cout << "Со счёта списаны деньги" << endl;
			}
			else {
				cout << " Вы ввели несуществующий счёт" << endl;
			}
			break;
		case 6: //запрос баланса
			cout << "Введите номер счёта,с которого вы хотите запросить баланс" << endl;
			cin >> num;
			cout << "Счёт номер " <<  arr[num - 1001] << "; Баланс:" << arr2[num - 1001] << endl;
			break;
		case 7: //Все доступные счета
			for (int n = 0; n < size; n++) {
				cout << "Счёт номер " << arr[n] << ";  Баланс: " << arr2[n]  << endl;
			}
		case 8: //Рассчитать процент по ставке
			cout << "Введите количество процентов по ставке" << endl;
			cin >> perc;
			perc /= 100;
			for (int i = 0; i < size; ++i) {

			}
		}
		cout << "Хотите снова? введите 1, иначе введите 0" << endl;
		cin >> b;
		if (b == 1) continue;
		if (b == 0) break;
	}






	return 0;
	}
int *mas(int &size) {
	int i, k;
	int* array = new int[size];
	for (i = 0; i < size; i++) {
		array[i] = i + 1001;
	}
	return array;
}
double *mas2(int &size) {
	int i, k;
	double* array2 = new double[size];
	for (i = 0; i < size; i++) {
		array2[i] = 0;
	}
	return array2;
}