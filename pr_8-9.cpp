#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class clDate {
private:
    int day, month, year;

public:
    clDate(int d = 1, int m = 1, int y = 1900) : day(d), month(m), year(y) {}

    bool operator<(const clDate& other) const {
        if (year != other.year) {
            return year < other.year;
        }
        else if (month != other.month) {
            return month < other.month;
        }
        else {
            return day < other.day;
        }
    }

    friend ostream& operator<<(ostream& os, const clDate& date) {
        os << date.day << "." << date.month << "." << date.year;
        return os;
    }

    friend istream& operator>>(istream& is, clDate& date) {
        cout << "Введите дату в формате \"дд.мм.гггг\": ";
        char sep;
        is >> date.day >> sep >> date.month >> sep >> date.year;
        return is;
    }
};

class clStudent {
protected:
    string lastName;
    string firstName;
    string patronymic;
    clDate birthDate;
    char gender;
    clDate enrollmentDate;
    double scholarship;

public:
    clStudent(string last = "", string first = "", string patr = "", clDate bdate = clDate(),
        char g = 'M', clDate edate = clDate(), double s = 0.0)
        : lastName(last), firstName(first), patronymic(patr), birthDate(bdate),
        gender(g), enrollmentDate(edate), scholarship(s) {}

    bool operator<(const clStudent& other) const {
        if (lastName != other.lastName) {
            return lastName < other.lastName;
        }
        else {
            return firstName < other.firstName;
        }
    }

    friend ostream& operator<<(ostream& os, const clStudent& student) {
        os << student.lastName << " " << student.firstName << " " << student.patronymic << endl;
        os << "Дата рождения: " << student.birthDate << endl;
        os << "Пол: " << student.gender << endl;
        os << "Дата зачисления: " << student.enrollmentDate << endl;
        os << "Стипендия: " << student.scholarship << endl;
        return os;
    }

    friend istream& operator>>(istream& is, clStudent& student) {
        cout << "Введите фамилию: ";
        is >> student.lastName;
        cout << "Введите имя: ";
        is >> student.firstName;
        cout << "Введите отчество: ";
        is >> student.patronymic;
        cout << "Введите дату рождения: " << endl;
        is >> student.birthDate;
        cout << "Введите пол (M/F): ";
        is >> student.gender;
        cout << "Введите дату зачисления: " << endl;
        is >> student.enrollmentDate;
        cout << "Введите размер стипендии: ";
        is >> student.scholarship;
        return is;
    }
};

class clGroup {
private:
    string groupCode;
    string institute;
    string department;
    string curator;
    int groupSize;
    clStudent* students;


public:
    clGroup(string code = "", string inst = "", string dept = "", string cur = "", int size = 0)
        : groupCode(code), institute(inst), department(dept), curator(cur), groupSize(size), students(nullptr) {
        if (size > 0) {
            students = new clStudent[size];
        }
    }

    clGroup(const clGroup& other)
        : groupCode(other.groupCode), institute(other.institute), department(other.department),
        curator(other.curator), groupSize(other.groupSize), students(nullptr) {
        if (groupSize > 0) {
            students = new clStudent[groupSize];
            for (int i = 0; i < groupSize; i++) {
                students[i] = other.students[i];
            }
        }
    }

    clGroup(clGroup&& other) noexcept
        : groupCode(std::move(other.groupCode)), institute(std::move(other.institute)),
        department(std::move(other.department)), curator(std::move(other.curator)),
        groupSize(other.groupSize), students(other.students) {
        other.groupSize = 0;
        other.students = nullptr;
    }

    clGroup& operator=(const clGroup& other) {
        if (this != &other) {
            clGroup tmp(other);
            std::swap(groupCode, tmp.groupCode);
            std::swap(institute, tmp.institute);
            std::swap(department, tmp.department);
            std::swap(curator, tmp.curator);
            std::swap(groupSize, tmp.groupSize);
            std::swap(students, tmp.students);
        }
        return *this;
    }

    clGroup& operator=(clGroup&& other) noexcept {
        if (this != &other) {
            std::swap(groupCode, other.groupCode);
            std::swap(institute, other.institute);
            std::swap(department, other.department);
            std::swap(curator, other.curator);
            std::swap(groupSize, other.groupSize);
            std::swap(students, other.students);
            other.groupSize = 0;
            other.students = nullptr;
        }
        return *this;
    }

    ~clGroup() {
        delete[] students;
    }

    void addStudent(const clStudent& student) {
        clStudent* tmp = new clStudent[groupSize + 1];
        for (int i = 0; i < groupSize; i++) {
            tmp[i] = students[i];
        }
        tmp[groupSize] = student;
        delete[] students;
        students = tmp;
        groupSize++;
    }

    void removeStudent(int index) {
        if (index >= 0 && index < groupSize) {
            clStudent* tmp = new clStudent[groupSize - 1];
            for (int i = 0; i < index; i++) {
                tmp[i] = students[i];
            }
            for (int i = index + 1; i < groupSize; i++) {
                tmp[i - 1] = students[i];
            }
            delete[] students;
            students = tmp;
            groupSize--;
        }
    }
};