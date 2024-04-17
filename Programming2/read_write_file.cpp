#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // Append to the file
    ofstream outFile("kitten.txt", ios::app);
    if (outFile.is_open()) {
        outFile << "\nHello, kitten!\n";
        outFile.close();
    } else {
        cout << "Unable to open file for writing.\n";
    }

    // Read from the file
    string line;
    ifstream inFile("kitten.txt");
    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            cout << line << '\n';
        }
        inFile.close();
    } else {
        cout << "Unable to open file for reading.\n";
    }

    return 0;
}