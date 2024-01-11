

#include <iostream>

using namespace std;

int main()
{
    int size;
    cout << "How many boxes of chocolates? ";
    cin >> size;
    if (size <= 0 || size > 10){
        cout << "Invalid input. The number of boxes should be positive and less than 10.";
        return 0;
    }
    else{
        int box[size];
        int flag = 0;
        //input for chocolate boxes
        for (int i = 0; i < size; i++){
            cout << "Number of chocolates in box " << i + 1 << ": ";
            cin >> box[i];
            if (box[i] < 0 || box[i] > 50){
                cout << "Invalid input. The number of chocolates in the box shoudl be positive and less than 50.";
                return 0;
                
            }
            else if (i == 0 && box[i]%2 != 0){
                cout << "Invalid input. The number of chocolates in the first box should be an even positive number.";
                return 0;
            }
            else if (box[i]%2 != 0){
                flag += 1;
            }
            
        }
        cout << "The number of chocolates in boxes are: ";
        for (flag; flag < size; flag++){
            cout << box[flag] << " ";
        }
        
    }

    return 0;
}
