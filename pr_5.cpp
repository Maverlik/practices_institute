#include <iostream>

using namespace std;

class clDate {
private:
    int day;
    int month;
    int year;

public:
    clDate() {
        day = 1;
        month = 1;
        year = 1900;
    }

    clDate(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }

    clDate(const char* dateStr) {
        sscanf_s(dateStr, "%d.%d.%d", &day, &month, &year);
    }

    ~clDate() {
        cout << "Destructor called" << endl;
    }

    void setDate(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }

    void getDate(int& d, int& m, int& y) const {
        d = day;
        m = month;
        y = year;
    }

    void addDays(int days) {
        day += days;
        while (day > daysInMonth()) {
            day -= daysInMonth();
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
    }

    void subDays(int days) {
        day -= days;
        while (day < 1) {
            month--;
            if (month < 1) {
                month = 12;
                year--;
            }
            day += daysInMonth();
        }
    }

    bool isValid() const {
        if (year < 1900) return false;
        if (month < 1 || month > 12) return false;
        if (day < 1 || day > daysInMonth()) return false;
        return true;
    }

    int daysInMonth() const {
        if (month == 2) {
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
                return 29;
            }
            else {
                return 28;
            }
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11) {
            return 30;
        }
        else {
            return 31;
        }
    }
};

int main() {
    clDate date1;
    clDate date2(7, 5, 2023);
    clDate date3("1.12.2022");

    int day, month, year;
    date1.getDate(day, month, year);
    cout << "date1: " << day << "." << month << "." << year << endl;

    date2.getDate(day, month, year);
    cout << "date2: " << day << "." << month << "." << year << endl;

    date3.getDate(day, month, year);
    cout << "date3: " << day << "." << month << "." << year << endl;
}