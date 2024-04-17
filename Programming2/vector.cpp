#include <vector>
#include <iostream>
using namespace std;

int main(){
    // initializer list
    vector <int> num = {1, 2, 3, 4, 5};

    cout << "vector1 = ";
    // ranged loop
    for (const int& i : num) {
        cout << i << "  ";
    }
    /*
    Basic vector operations:
        Add elements
        Access elements
        Change elements
        Remove elements
    */

    // add 4, 8, and 10 to the end of the vector
    num.push_back(4);
    num.push_back(8);
    num.push_back(10);
    // print updated vector
    cout << endl;
    for (const int& i : num) {
        cout << i << "  ";
    }
    

    // n C++, we use the index number to access the vector elements. 
    //Here, we use the at() function to access the element from the specified index
    cout << endl;
    cout << "Element at index 0: " << num.at(0) << endl;
    cout << "Element at index 1: " << num.at(1) << endl;
    cout << "Element at index 2: " << num.at(2) << endl;
    // Like an array, we can also use the square brackets [] to access vector elements
    cout << "Element at index 3: " << num[3];
    cout << endl;
    /*However, the at() function is preferred over [] because at() throws an exception 
    whenever the vector is out of bound, while [] gives a garbage value*/

    // change elements at index 3 and 5
    num.at(3) = 11;
    num.at(5) = 100;
    // print the updated vector
    for (const int& i : num) {
        cout << i << "  ";
    }
    cout << endl;
    
    // To delete a single element from a vector, we use the pop_back() function
    // remove the last element in vector num
    num.pop_back();
    // print the updated vector
    cout << "Last element removed. \n";
    for (const int& i : num) {
        cout << i << "  ";
    }    

    return 0;
}


