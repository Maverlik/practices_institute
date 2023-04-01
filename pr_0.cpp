#include <windows.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string name[3];
	char type[3];
	float price[3];
	int amount[3];
	string date[3];

	for (int i = 0; i < 3; i++) {
		cout << "Введите название товара>>";
		getline(cin, name[i]);
	}

	for (int j = 0; j < 3; j++) {
		cout << "Введите тип товара>>";
		cin >> type[j];
	}

	for (int i = 0; i < 3; i++) {
		cout << "Введите цену товара>>";
		cin >> price[i];
	}

	for (int i = 0; i < 3; i++) {
		cout << "Введите минимальное количество товара>>";
		cin >> amount[i];
	}

	for (int i = 0; i < 3; i++) {
		cout << "Введите дату>>";
		cin >> date[i];
	}

	cout << "|--------------------------------------------------------------------------------------------------------|" << endl;
	
	cout << "|Прайс-лист                                                                                              |" << endl;
	cout << "|--------------------------------------------------------------------------------------------------------|" << endl;
	cout << "|Наименование товара |  Тип товара  | Цена за 1 шт (грн) |  Минимальное количество в партии |    Дата    |" << endl;
	cout << "|--------------------------------------------------------------------------------------------------------|" << endl;

	for (int i = 0; i < 3; i++) {
		cout << "|";
		cout.width(20);
		cout << left << name[i];

		cout << "|";
		cout.width(14);
		cout << left << type[i];

		cout << "|";
		cout.width(20);
		cout << left << price[i];

		cout << "|";
		cout.width(34);
		cout << left << amount[i];

		cout << "|";
		cout.width(12);
		cout << left << date[i];

		cout << "|" << endl;
		cout << "|--------------------------------------------------------------------------------------------------------|" << endl;
	}

	cout << "|Примечание: К – канцтовары, О - оргтехника                                                              |" << endl;
	cout << "|--------------------------------------------------------------------------------------------------------|" << endl;
}
