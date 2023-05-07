#include <iostream>
using namespace std;

struct Record {
    string name;
    char type;
    float price;
    int amount;
};

struct Node {
    Record data;
    Node* next;
    Node* prev;
};

class LinkedList {
public:
    LinkedList() : head(nullptr) {}
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void addNode(Record data) {
        Node* node = new Node{ data, nullptr, nullptr };
        if (head == nullptr) {
            head = node;
            tail = node;
        }
        else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    void printList() {
        if (head == nullptr) {
            cout << "Лист пуст." << endl;
            return;
        }
        cout << "Лист: " << endl;
        Node* current = head;
        while (current != nullptr) {
            cout << "Имя: " << current->data.name << ", Тип: " << current->data.type << ", Цена: " << current->data.price << ", Количество: " << current->data.amount << endl;
            cout << "Адрес памяти: " << current << ", Следующий: " << current->next << ", Предыдущий: " << current->prev << endl;
            current = current->next;
        }
    }

private:
    Node* head;
    Node* tail;
};

int main() {
    setlocale(LC_ALL, "Russian");
    Record Table[10] = {
        {"Продукт 1", 'К', 1.5, 10},
        {"Продукт 2", 'Л', 2.0, 20},
        {"Продукт 3", 'К', 3.5, 30},
        {"Продукт 4", 'Л', 4.0, 40},
        {"Продукт 5", 'Л', 5.5, 50},
        {"Продукт 6", 'К', 6.0, 60},
        {"Продукт 7", 'Л', 7.5, 70},
        {"Продукт 8", 'Л', 8.0, 80},
        {"Продукт 9", 'К', 9.5, 90},
        {"Продукт 10", 'Л', 10.0, 100},
    };

    LinkedList list;
    for (int i = 0; i < 10; i++) {
        list.addNode(Table[i]);
        list.addNode(Table[i]);
    }

    list.printList();

    return 0;
}