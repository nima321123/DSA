#include <iostream>
#include <string>
using namespace std;

/*class Cat{
    private:
        string name;
    public:
        // define method inside the class
        void setName(string input_name){
            name = input_name;
        }
        string getName(){
            return name;
        }
};*/

class Cat{
    private:
        string name;
    public:
        string getname(){
            return name;
        }
        void setName(string input_name);
};
void Cat::setName(string input_name){
    name = input_name;
}

int main(){
    Cat cat1;
    cat1.setName("Fluffy");
    cout << cat1.getname();
    return 0;
}
