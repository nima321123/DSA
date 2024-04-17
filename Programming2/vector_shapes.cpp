#include <iostream>
#include <vector>
#include<typeinfo>
using namespace std;

class Shape {
    public:
    virtual void describe() = 0;
};
class Square: public Shape {
private:
    int side;
public:
    Square(int side): side(side) {}
    void describe () {
        cout<< side << endl;
    }
    
};
class Circle: public Shape {
private:
    double radius;
public:
    Circle (double radius): radius(radius) {}
    void describe () {
        cout<< radius << endl;
    }
};

class RightTriangle: public Shape{
private:
    int base, height;
public:
    RightTriangle(int base, int height): base(base), height(height){}
    void describe() {
        cout<<"Base: "<<base<<endl;
        cout<<"Height: "<<height<<endl;
    }

};

class Canvas {
private:
    vector<Shape*> listOfShape;
public:
    void addShape(Shape* shape) {
        listOfShape.push_back(shape);
    }
    
    int countShapeType(const type_info& shapetype){
        int count = 0;
        for(Shape* shape: listOfShape){
            if(typeid(*shape)==shapetype){
                count++;
            }
        }
        return count;
    }
};
int main() {
    Canvas canvas;
    Square square(5);
    Square square2(4);
    Square square3(8);
    Circle circle(3);
    RightTriangle rightTriangle1(3,4);
    RightTriangle rightTriangle2(3,4);
    RightTriangle rightTriangle3(3,4);
    canvas.addShape(&square);
    canvas.addShape(&square2);
    canvas.addShape(&square3);
    canvas.addShape(&circle);
    canvas.addShape(&rightTriangle1);
    canvas.addShape(&rightTriangle2);
    canvas.addShape(&rightTriangle3);
    cout<<"Number of Square: "<<canvas.countShapeType(typeid(Square))<<endl;
    cout<<"Number of RightTriangle: "<<canvas.countShapeType(typeid(RightTriangle))<<endl;
    return 0;
}
