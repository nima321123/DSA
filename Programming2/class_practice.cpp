#include <iostream>
#include <string>
using namespace std;

class Cat{
    private:
        string Name;
        string color;
        int age;
    public:
        void setName(string name){
            Name = name;
        }
        void setColor(string c){
            color = c;
        }
        void setAge(int a){
            age = a;
        }
        string getName(){
            return Name;
        }
        string getColor(){
            return color;
        }
        int getAge(){
            return age;
        }
};

int main(){
    Cat cat1;
    cat1.setName("Fluffy");
    cat1.setColor("White");
    cat1.setAge(3);
    cout << "Name: " << cat1.getName();
    cout << "\nColor: " << cat1.getColor();
    cout << "\nAge: " << cat1.getAge();
    return 0;
}
