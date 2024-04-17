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
    ID& theirID;

    public:
    Student(string name, ID id): theirID(id) {
        this->name = name;
    }
    
    void describe(){
        cout << "Name: " << name << endl << "ID: ";
        theirID.describe();
    }
};

int main(){
    ID hisID(4982);
    Student student1("Sam", hisID);
    student1.describe();
    
    return 0;
}

//*******************************************
int x = 10;
int* ptr = &x; // ptr is a pointer to x