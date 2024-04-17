#include <iostream>
using namespace std;

//DEVICE AND MANUFACTURER
//AGGREGATION

class Manufacturer{
    int id;
    string location;
    public:
        Manufacturer(int id, string location): id(id), location(location) {}
        void describe(){
            cout << "Manufacturer ID: " << id << endl;
            cout << "Manufacturer Location: " << location << endl;
        }
};
class Device{
    string name;
    double price;
    Manufacturer* manufacturer;
    public:
        Device(string name, double price, int id, string location){
            this->name = name;
            this->price = price;
            manufacturer = new Manufacturer(id, location);
        }
        ~Device(){
            delete manufacturer;
            cout << "Device removed";
        }
        void describe(){
            cout << "Device name: " << name << endl;
            cout << "Device price: " << price << endl;
            manufacturer->describe();
        }
};

int main(){
    Device phone("MyPhone X", 115.5, 4697, "Indonesia");
    phone.describe();
    return 0;
}