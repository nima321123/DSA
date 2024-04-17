#include <iostream>
using namespace std;

// !Learn design patterns
// Polymorphism
// Abstract data type
// Super class shape
class Shape{
    public:
    virtual float area() = 0; // Pure virtual function  
};
class Square : public Shape {
    private:
        int side;
    public:
        Square(int side):side(side){}
        float area() override{
            return side*side;
        }
};

class Rectangle : public Shape {
    private:
        int height;
        int width;
    public:
        Rectangle(int h, int w): height(h), width(w){}
        float area() override{
            return height*width;
        }
};

class Circle: public Shape {
    private:
        int radius;
    public:
        Circle(int r): radius(r) {}
        float area() override{
            return 3.14*radius*radius;
        }
};

class RightTriangle: public Shape {
    private:
        int base;
        int height;
    public:
        RightTriangle(int b, int h): base(b), height(h){}
        float area() override{
            return 0.5*base*height;
        }
};

class Canvas{
    public:
        void showCanvas(Shape* obj){
            cout << "Area = " << obj->area() << endl;
        }
};

int main(){
    Square square(4);
    Rectangle rectangle(8, 3);
    Circle circle(10);
    RightTriangle rightTriangle(6, 5);

    Canvas canvas;
    canvas.showCanvas(&square);
    canvas.showCanvas(&rectangle);
    canvas.showCanvas(&circle);
    canvas.showCanvas(&rightTriangle);
    
    return 0;

}

