func(int n){
    if (n == 1) return;
    for (int i = 1; i < n; i ++){
        for (int j = 1; j <= n; j ++){
            printf("*");
            break;
        }
    }
}

void function (int n){
    int i, j, k, count = 0;
    for (i = n/2; i<=n; i++){
        for (j = 1; j < n; j = 2*j){
            for (k = 1; k <= n; k = k*2){
                count++;
            }
        }
    }
}

func2(int n){
    if (n==1) return;
    for(int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            printf("*");
        }
    }
    func2(n-3);
}

void new_sort(int arr[], int n){
    for (int step = 0; step < n - 1; ++step){
        for (int i = 0; i < n - step - 1; ++i){
            if (arr[i] > arr [i+1]){
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    }
}

// Base class
// Base class
class Animal {
public:
    virtual void sound() {
        cout << "The animal makes a sound" << endl;
    }
};

// Derived class
class Dog : public Animal {
public:
    void sound() override {
        cout << "The dog barks" << endl;  // Overriding the base class's method
    }
};

int main() {
    Dog dog;
    dog.sound();
    return 0;
}

#include <iostream>
#include <memory>
using namespace std;

class Bird {
public:
    virtual void eat()=0;  
};

class FlyingBird: public Bird{
public:
    virtual void fly()=0;
};

class SwimmingBird: public Bird{
public:
    virtual void swim()=0;
};

class Parrot: public FlyingBird {
public:
    void eat(){
        cout<<"Parrots eat corn."<<endl;
    }
    
    void fly(){
        cout<<"Parrots can fly in small range."<<endl;
    }
};

class Pigeon: public FlyingBird{
public:
    void eat(){
        cout<<"Pigeons eat cereal."<<endl;
    }
    
    void fly(){
        cout<<"Pigeons can fly in wide range."<<endl;
    }
};

class Duck: public SwimmingBird{
public:
    void eat(){
        cout<<"Ducks eat many things."<<endl;
    }
    
    void swim(){
        cout<<"Ducks can swim in small range."<<endl;
    }
};

int main() {
    unique_ptr<Duck> duck = make_unique<Duck>();
    duck->eat();
    duck->swim();
    
    unique_ptr<Parrot> parrot = make_unique<Parrot>();
    parrot->eat();
    parrot->fly();
    
    unique_ptr<Pigeon> pigeon = make_unique<Pigeon>();
    pigeon->eat();
    pigeon->fly();
    
    return 0;
}