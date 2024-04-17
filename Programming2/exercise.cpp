#include<iostream>
using namespace std;

class ID{
    int id;
    public:
    ID(int id): id(id){}
    void describe(){
        cout << id;
    }
};
class Student{
    string name;
    ID theirID;

    public:
    Student(string name, int id): name(name), theirID(id){}
    void describe(){
        cout << "Name: " << name << endl << "ID: ";
        theirID.describe();
    }
};

int main(){
    Student student1("Sam", 1567);
    student1.describe();
    return 0;
}


