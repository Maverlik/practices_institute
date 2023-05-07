#include <iostream>
#include <fstream>

using namespace std;

struct Record {
    string name;
    char type;
    float price;
    int amount;
};

int main() {
    ofstream txt_file("мушкарев.txt");

    Record records[3] = {
        {"Record 1", 'A', 10.5, 20},
        {"Record 2", 'B', 20.5, 30},
        {"Record 3", 'C', 30.5, 40},
    };

    for (int i = 0; i < 3; i++) {
        txt_file << records[i].name << " "
            << records[i].type << " "
            << records[i].price << " "
            << records[i].amount << endl;
    }

    txt_file.close();

    ifstream txt_file_in("мушкарев.txt");
    Record read_records[3];

    for (int i = 0; i < 3; i++) {
        txt_file_in >> read_records[i].name
            >> read_records[i].type
            >> read_records[i].price
            >> read_records[i].amount;
    }

    for (int i = 0; i < 3; i++) {
        cout << read_records[i].name << " "
            << read_records[i].type << " "
            << read_records[i].price << " "
            << read_records[i].amount << endl;
    }

    txt_file_in.close();

    ofstream bin_file("мушкарев.bin", ios::binary);

    for (int i = 0; i < 3; i++) {
        bin_file.write(reinterpret_cast<const char*>(&records[i]), sizeof(Record));
    }

    bin_file.close();

    ifstream bin_file_in("мушкарев.bin", ios::binary);
    Record read_bin_records[3];

    for (int i = 0; i < 3; i++) {
        bin_file_in.read(reinterpret_cast<char*>(&read_bin_records[i]), sizeof(Record));
    }

    for (int i = 0; i < 3; i++) {
        cout << read_bin_records[i].name << " "
            << read_bin_records[i].type << " "
            << read_bin_records[i].price << " "
            << read_bin_records[i].amount << endl;
    }

    bin_file_in.close();

    return 0;
}

int main() {
    ofstream txt_file("мушкарев.txt", ios::app);

    Record new_record;

    cout << "Введите имя: ";
    cin >> new_record.name;
    cout << "Введите тип: ";
    cin >> new_record.type;
    cout << "Введите цену: ";
    cin >> new_record.price;
    cout << "Введите количество:";
    cin >> new_record.amount;
}