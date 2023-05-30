/*Определить перечислимый тип WeekDay. Определить для этого
типа операцию перехода к следующему дню как операцию инкремента
operator++ в префиксной и постфиксной формах, а также операцию перехода к
предыдущему дню как операцию operator- - в обеих формах. Реализовать

операцию вывода как перегруженную операцию operators, которая должна
выводить на экран английские названия дней недели.*/
#include <iostream>
#include<Windows.h>
using namespace std;

enum WeekDay { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };

WeekDay operator++(WeekDay& day) {
    return day = static_cast<WeekDay>((day + 1) % 7);
}

WeekDay operator++(WeekDay& day, int) {
    WeekDay temp = day;
    ++day;
    return temp;
}

WeekDay operator--(WeekDay& day) {
    return day = static_cast<WeekDay>((day + 6) % 7);
}

WeekDay operator--(WeekDay& day, int) {
    WeekDay temp = day;
    --day;
    return temp;
}

ostream& operator<<(ostream& os, const WeekDay& day) {
    switch (day) {
    case Monday: os << "Monday"; break;
    case Tuesday: os << "Tuesday"; break;
    case Wednesday: os << "Wednesday"; break;
    case Thursday: os << "Thursday"; break;
    case Friday: os << "Friday"; break;
    case Saturday: os << "Saturday"; break;
    case Sunday: os << "Sunday"; break;
    }
    return os;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    WeekDay today = Monday;
    cout << "Текущий день:  " << today << endl;
    cout << "Следующий день" << ++today << endl;
    cout << "Предыдущий день " << --today << endl;
    return 0;
}