
#include <iostream>

using namespace std;

//classes and methods in this template
class Node{
    public:
    int data;
    Node *left, *right;
};

class BST{ 
    //create the binary search tree
    public:
        Node *root; //referring to the root node of the tree
        BTS(){
            root = NULL; //initializing the root variable with NULL
        }
        Node *insert (Node*, int); //member function insert()
        //return the root of the tree after each insertion
        int search(int); //member function search()
        //return the search data if the search key finds it in the tree, otherwise returns -1
        
}

int main()
{
    cout<<"Hello World";

    return 0;
}
