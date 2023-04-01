#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

struct Record {
    string name;
    char type;
    float price;
    int amount;
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Record Table[10];

    for (int i = 0; i < 3; i++) {
        cout << "Введите название товара>>";
        cin >> Table[i].name;
        cout << "Введите тип товара>>";
        cin >> Table[i].type;
        cout << "Введите цену товара>>";
        cin >> Table[i].price;
        cout << "Введите минимальное количество товара>>";
        cin >> Table[i].amount;
    }

    cout << "|------------------------------------------------------------------------------------------|" << endl;
    cout.width(60);
    cout << "|Прайс-лист                                                                                |" << endl;
    cout << "|------------------------------------------------------------------------------------------|" << endl;
    cout << "|Наименование товара |  Тип товара  | Цена за 1 шт (грн) |  Минимальное количество в партии|" << endl;
    cout << "|------------------------------------------------------------------------------------------|" << endl;

    for (int i = 0; i < 3; i++) {
        cout << "|";
        cout.width(20);
        cout << left << Table[i].name;
        cout << "|";
        cout.width(14);
        cout << left << Table[i].type;
        cout << "|";
        cout.width(20);
        cout << left << Table[i].price;
        cout << "|";
        cout.width(33);
        cout << left << Table[i].amount;
        cout << "|" << endl;
        cout << "|------------------------------------------------------------------------------------------|" << endl;
    }

    cout << "|Примечание: К – канцтовары, О - оргтехника                                                |" << endl;
    cout << "|------------------------------------------------------------------------------------------|" << endl;

    return 0;
}