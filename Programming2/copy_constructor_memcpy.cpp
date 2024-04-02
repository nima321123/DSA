#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;

class Vector3D{
    private:
        int* coord;
        int size = 3;
    public:
        Vector3D(int x, int y, int z){
            coord = new int[size];
            coord[0] = x;
            coord[1] = y;
            coord[2] = z;
        }
        ~Vector3D(){
            delete[] this->coord;
        }
        Vector3D(const Vector3D &other, int size){
            this->coord = new int[size];
            memcpy(this->coord, other.coord, size * sizeof(int));
        }
        void describe(){
            cout << "X: " << this->coord[0]
                 << " Y: " << this->coord[1]
                 << " Z: " << this->coord[2] << endl;
        
        }
    
};
int main(){
    Vector3D v1(1, 2, 3);
    v1.describe();

    Vector3D v2 = v1;
    v2.describe();
    return 0;

}
