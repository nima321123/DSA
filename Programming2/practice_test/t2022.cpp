#include <iostream>
using namespace std;

class Beverage {
private:
    float price;
    float toppingPrice;
    float condimentPrice;

public:
    // Default constructor
    Beverage() : price(0), toppingPrice(0), condimentPrice(0) {}

    // Constructor with parameters
    Beverage(float p, float t, float c) : price(p), toppingPrice(t), condimentPrice(c) {}

    // Copy constructor
    Beverage(const Beverage& b) : price(b.price), toppingPrice(b.toppingPrice), condimentPrice(b.condimentPrice) {}

    // Overloaded plus operator
    Beverage operator+(const Beverage& b) {
        return Beverage(this->price + b.price, this->toppingPrice + b.toppingPrice, this->condimentPrice + b.condimentPrice);
    }

    // Overloaded comparison operator
    bool operator==(const Beverage& b) {
        return this->price == b.price && this->toppingPrice == b.toppingPrice && this->condimentPrice == b.condimentPrice;
    }

    // Method to display the beverage prices
    void describe() {
        cout << "Price: " << this->price << ", Topping Price: " << this->toppingPrice << ", Condiment Price: " << this->condimentPrice << endl;
    }
};

int main() {
    Beverage b1(4.0, 0.5, 0.7);
    Beverage b2 = b1; // Copy constructor
    Beverage b3;
    b3 = b1 + b2; // Overloaded plus operator
    b3.describe();

    if (b1 == b2) { // Overloaded comparison operator
        cout << "b1 and b2 are equal" << endl;
    } else {
        cout << "b1 and b2 are not equal" << endl;
    }

    return 0;
}