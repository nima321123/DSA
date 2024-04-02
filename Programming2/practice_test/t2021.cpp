#include <iostream>
using namespace std;

class Complex {
private:
    float real;
    float imag;

public:
    // Default constructor
    Complex() : real(0), imag(0) {}

    // Constructor with parameters
    Complex(float r, float i) : real(r), imag(i) {}

    // Copy constructor
    Complex(const Complex& c) : real(c.real), imag(c.imag) {}

    // Overloaded plus operator
    Complex operator+(const Complex& c) {
        return Complex(this->real + c.real, this->imag + c.imag);
    }

    // Overloaded comparison operator
    bool operator==(const Complex& c) {
        return this->real == c.real && this->imag == c.imag;
    }

    // Overloaded assignment operator
    Complex& operator=(const Complex& c) {
        if (this != &c) {
            this->real = c.real;
            this->imag = c.imag;
        }
        return *this;
    }

    // Method to display the complex number
    void display() {
        cout << this->real << " + " << this->imag << "i" << endl;
    }
};

int main() {
    Complex c1(3.0, 4.0);
    Complex c2 = c1; // Copy constructor
    Complex c3;
    c3 = c1 + c2; // Overloaded plus and assignment operators
    c3.display();

    if (c1 == c2) { // Overloaded comparison operator
        cout << "c1 and c2 are equal" << endl;
    } else {
        cout << "c1 and c2 are not equal" << endl;
    }

    return 0;
}