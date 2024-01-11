

#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key){
    int first = 0, last = size - 1, mid;
    cout << "\nMid scores: ";
    while (first <= last){
        mid = (first + last) / 2;
        cout << arr[mid] << " ";
        
        if (arr[mid] == key) return mid + 1;
        else if (arr[mid] < key) first = mid + 1;
        else last = mid - 1;
    }
    return 0;
}
int main()
{
    cout<<"Enter the number of teams: ";
    int no, score, result;
    cin >> no;
    int teams[no];
    cout <<"Enter the score: \n";
    for (int idx = 0; idx < no; idx ++){
        cin >> teams[idx];
    }
    cout << "Enter the score to be searched: ";
    cin >> score;
    
    result = binarySearch(teams, no, score);
    if (result == 0) cout << "\nScore not found";
    else cout << "\nScore found for the team "<< result;
    return 0;

    
}
