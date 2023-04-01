#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>

using namespace std;

struct Record {
    string name;
    char type;
    float price;
    int amount = 0;
};

int main()
{
    setlocale(LC_ALL, "Russian");
    Record records[10];

    for (int i = 0; i < 3; i++) {
        cout << "Введите название товара: ";
        cin >> records[i].name;
        cout << "Введите тип товара (О/К): ";
        cin >> records[i].type;
        cout << "Введите цену товара: ";
        cin >> records[i].price;
        cout << "Введите минимальное количество товара: ";
        cin >> records[i].amount;
    }

    Record* A = (Record*)malloc(3 * sizeof(Record));
    if (A == NULL) {
        cout << "Ошибка при выделении памяти" << endl;
        return 1;
    }

    for (int i = 0; i < 3; i++) {
        *(A + i) = records[i];
    }

    Record* tmp = (Record*)realloc(A, 10 * sizeof(Record));
    if (tmp == NULL) {
        cout << "Ошибка при изменении размера памяти" << endl;
        free(A);
        return 1;
    }
    else {
        A = tmp;
    }

    for (int i = 3; i < 10; i++) {
        A[i].name = "Unknown";
        A[i].type = '-';
        A[i].price = 0.0f;
        A[i].amount = 0;
    }

    Record* B = new Record[10];
    for (int i = 0; i < 10; i++) {
        *(B + i) = *(A + i);
    }

    cout << "Адрес первого элемента массива Table: " << &records[0] << endl;
    cout << "Адрес первого элемента массива A: " << A << endl;
    cout << "Адрес первого элемента массива B: " << B << endl;


    cout << "|---------------|--------|--------------|-----------|" << endl;
    cout << "|";
    cout.width(20); cout << left << "Адрес";
    cout.width(14); cout << left << "|Название";
    cout.width(20); cout << left << "|Адрес";
    cout.width(20); cout << left << "|Название";
    cout.width(33); cout << left << "|" << endl;
    cout << "|---------------|--------|--------------|-----------|" << endl;

    for (int i = 0; i < 3; i++) {
        cout << "|";
        cout.width(15); cout << left << (A + i);
        cout.width(9); cout << left << "|" + (A + i)->name;
        cout << "|";
        cout.width(14); cout << left << (B + i);
        cout.width(12); cout << left << "|" + (B + i)->name;
        cout << "|" << endl;
        cout << "|---------------|--------|--------------|-----------|" << endl;
    }

    free(A);
    delete[] B;

    return 0;
}
