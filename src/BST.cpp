
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
        BST(){
            root = NULL; //initializing the root variable with NULL
        }
        Node* insert (Node*, int); //member function insert()
        //return the root of the tree after each insertion
        int search(int); //member function search()
        //return the search data if the search key finds it in the tree, otherwise returns -1
        
};
Node* BST:: insert (Node*, int num){
    //insertion of the node in the tree
    //return the root of the tree after each insertion
    Node *temp = new Node();
    temp->data = num;
    temp->left = temp->right = NULL;
    if (this->root == NULL){
        this->root = temp;
        return this->root;
    }
    else{
        Node *parent = NULL, *current = root;
        while (current != NULL){
            parent = current;
            if (current->data > num){
                current = current->left;
            }
            else{
                current = current->right;
            }
        }
        if (parent->data > num){
            parent->left = temp;
        }
        else{
            parent->right = temp;
        }
        return root;
    }
}
int BST :: search(int searchKey){
    Node *temp = root;
    while (temp != NULL){
        if (temp->data == searchKey){
            return searchKey;
        }
        else if (temp->data > searchKey){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    return -1;
}
int main()
{
    BST tree;
    string ch = "yes";
    int num, searchKey;
    cout << "Enter the key number: \n";
    cin >> num;

    tree.root = tree.insert(tree.root, num);
    //insert(where to insert, what to insert)
    //return the root of the tree after each insert
    do {
        cout << "Do you want to create another junction?\n";
        cin >> ch;
        if (ch.compare("yes") == 0){
            cout << "Enter the key number: \n";
            cin >> num;
            tree.root = tree.insert(tree.root, num);
        }
        else{
            break;
        }
    }while(true);
     
    cout << "Enter the key to be searched: ";
    cin >> searchKey;
    int flag = tree.search(searchKey);
    if (flag == searchKey){
        cout << "\n" << searchKey << " is found in the tree.\n";
    }
    else{
        cout << "\n" << searchKey << " is not found in the tree.\n";
    }
    return 0;
}
