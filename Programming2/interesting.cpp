
#include <iostream>
using namespace std;
class character{
    private:
        int power;
        int level = 0;
    public:
        character(int power){
            this->power = power;
        }
        void lvup(int lvup){
            this->level = lvup;
        }
        // copy constructor
        character(const character &obj){
            this->power = obj.power;
        }
        void describe(){
            cout << "Power: " << this->power
                 << " and Level: " << this->level << endl;
        }
};
int main()
{
    character soldier1(20);
    soldier1.lvup(2);
    soldier1.describe();

    //interesting part
    character soldier2 (soldier1);
    soldier2.describe();
    return 0;
}
