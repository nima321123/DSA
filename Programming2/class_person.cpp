/*A person comprises a name in string and a date 
of birth. A date consists of day, month, and year.
 Write a function to print his/her information 
Draw a class diagram and implement in C++
*/
#include<iostream>
using namespace std;

class Date{
    private:
        int day;
        int month;
        int year;
    public:
        // constructor to update date
        Date(int day, int month, int year){
            this->day = day;
            this->month = month;
            this->year = year;
        }
        //function to print date
        void describe(){
            cout << day << "/" << month << "/" << year << endl;
        }
};
class Person{
    private:
        string name;
        Date& birth;
    public:
        Person(string name, Date& birth): name(name), birth(birth) {}
        //Date& birth means that the function takes a reference to a Date object as an argument.
        //When you pass a variable by reference, the function works directly on the original variable
        //not a copy of its value
        //=> Any changes made to the parameter will affect the original variable.
           
        void describe(){
            cout << "Name: " << name << endl << "Date of birth: ";
            birth.describe();
            cout << endl;
        }
};

int main(){
    Date date(1, 5, 2000);
    //date.describe();
    Person person("Anna", date);
    person.describe();
    return 0;
}