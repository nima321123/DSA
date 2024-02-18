//binary search tree

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct BinaryTreeNode{
    int val;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
}node;

node* newNodeCreate(int val){
    node* temp = (node*)malloc(sizeof(node));
    temp->val = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

/*node* insert(node** root, int val){
    node* temp = create_node(val);
    
    if (*root == NULL) {
        *root = temp;
        return temp;
    }
    else{
        node* current = *root;
        //traverse to the right position
        while (current != NULL){
            if (temp->val < current-> val){
                current = current->left;
            }
            else if (temp->val >= current->val){
                current = current->right;
            }
        }
        if (temp->val < current->val) current->left = temp;
        else current->right = temp;
    }
    return *root;
}*/

/*node* insert_val(node** root){
    
    int val;
    char response;
    printf("Enter a number: ");
    scanf("%d", &val);
    //getchar();
    if (root == NULL) return create_node(val);
    insert(root, val);
    printf("\nDo you want to continue? ");
    scanf("%c", &response);
    //getchar();
    while(response != 'n'){
        printf("Enter a number: ");
        scanf("%d", &val);
        //getchar();
        insert(root, val);
        printf("\nDo you want to continue? ");
        scanf("%c", &response);
        //getchar();
    }
}*/

// Function to insert a node with a specific value in the
// tree
struct BinaryTreeNode* insertNode(struct BinaryTreeNode* node, int value)
{
    if (node == NULL) {
        return newNodeCreate(value);
    }
    if (value < node->val) {
        node->left = insertNode(node->left, value);
    }
    else if (value > node->val) {
        node->right = insertNode(node->right, value);
    }
    return node;
}


//check search key
// Function to search for a node with a specific key in the
// tree
node* searchNode(struct BinaryTreeNode* root, int target)
{
    if (root == NULL || root->val == target) {
        return root;
    }
    if (root->val < target) {
        return searchNode(root->right, target);
    }
    return searchNode(root->left, target);
}
 
/*bool search_key(node* root, int val){
    bool flag = false;
    node* current = root;
    while(current != NULL){
        
        if (current->val == val){
            
            flag = true;
            break;
        }
        
        if (current->val < val){
                current = current->left;
            }
            else if (current->val >= val){
                current = current->right;
            }
           
        
    }
    return flag;
}*/
//print BST

void print_BST(node* root){
    if (root != NULL){
        node* current = root;
        print_BST(current->left);
        printf("%d ", current->val);
        print_BST(current->right); 
    }
    
}

int main()
{
    node* root = NULL;
    int num;
    
    
    char response;
    do{
        printf("Enter a number: ");
        scanf("%d", &num);
        getchar();
        root = insertNode(root, num);
        printf("Continue adding values? y/n ");
        scanf("%c", &response);
        getchar();
    }while (response != 'n');
    
    print_BST(root);
    
    printf("Enter a search key: ");
    scanf("%d", &num);
    if (searchNode(root, num) != NULL) printf("%d is found in the tree.", num);
    else printf("%d is not found in the tree.", num);
    return 0;
}
