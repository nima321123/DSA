#include <stdio.h>
#include <stdlib.h>
/*  
             50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 
```
- Pseudo code:

```
root = create_node(50)
root->left = create_node(30)
root->right = create_node(70)
root->left->left = create_node(20)
...
*/
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
} node;

node* create_node(int data){
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node* insert(node* root, int data){
    node* temp = create_node(data);
    node* parent = root;
    if (root == NULL){
         root = temp;
        return root;
    }

    else{
        while (parent != NULL){
            if (data < parent->data){
                if (parent->left == NULL){
                    parent->left = temp;
                    return root;
                }
                else{
                    parent = parent->left;
                }
            }
            else{
                if (parent->right == NULL){
                    parent->right = temp;
                    return root;
                }
                else{
                    parent = parent->right;
                }
            }
        }
    }
}

//write a function to print the tree in order
void print_in_order(node* root){
    if (root == NULL){
        return;
    }
    print_in_order(root->left);
    printf("%d ", root->data);
    print_in_order(root->right);
}

int main(){
    node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);
    
    print_in_order(root);
    return 0;
}