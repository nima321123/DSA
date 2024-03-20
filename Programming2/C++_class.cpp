#include <iostream>
#include <string>
using namespace std;

class Book{
    public: 
        string author;
        string title;
        string genre;
        double price;
        string date;
        string publisher;
        string description;
};

int main()
{
    Book book1;
    book1.author = "Surbhi Kakar";
    book1.title = "Java Programming";
    book1.genre = "Computer";
    book1.price = 30.3;
    book1.date = "2010-08-01";
    book1.publisher = "Dream Tech Press";
    book1.description = "A description here.";
    
    cout << "Author: " << book1.author;
    cout << "\nTitle: " << book1.title;
    cout << "\nGenre: " << book1.genre;
    cout << "\nPrice: " << book1.price;
    cout << "\nDate: " << book1.date;
    cout << "\nPublisher: " << book1.publisher;
    cout << "\nDescription: " << book1.description;
    return 0;
}
