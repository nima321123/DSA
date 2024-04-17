#include <iostream>
using namespace std;

class Date{
    int day;
    int month;
    int year;
    public:
        Date(int day, int month, int year){
            this->day = day;
            this->month = month;
            this->year = year;
        }
        void describe(){
            cout << day << "/" << month << "/" << year;
        }
        bool checkSameDate(Date other){
            return 
            (this->day == other.day &&
             this->month == other.month &&
             this->year == other.year);
        }
};

class Person{
    string name;
    Date birthDay;
    public:
        Person(string name, Date birthDay): name(name), birthDay(birthDay){}
        void describe(){
            cout << "Name: " << name;
            cout << "Birthday: ";
            birthDay.describe();
        }
        bool checkSameName(Person other){
            if (other.name == this->name) return 1;
            return 0;
        }
        bool checkSameBirthday(Person other){
            return this->birthDay.checkSameDate(other.birthDay);
        }
        // overload the "==" operator
        bool operator==(Person other){
            if (this->name == other.name && this->checkSameBirthday(other)) return 1;
            return 0;
        }

};

int main(){
    Date date(2, 8, 1970);
    Date date2(2, 8, 1970);
    Person person1("Jane", date);
    Person person2("John", date2);
    Person person3("Jane", date);
    int result = person1==person3;
    cout << "Same person checking result: ";
    cout << result;
    return 0;
}