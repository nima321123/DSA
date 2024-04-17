#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int value;
    struct Node* next;
}Node;

// Function to test for an empty list
bool is_empty(Node head){
    return (head.next == NULL);
}

// Function to check whether the current position is the last position
// in a linked list
bool is_last(Node* current){
    return (current->next == NULL);
}
/*In the case of the is_last function, you're not modifying the Node, 
so you could technically pass a Node instead of a pointer. However, 
it's more efficient to pass a pointer, because COPYING A POINTER IS
FASTER THAN COPYING A NODE, especially if the Node is large.*/

/* Function to return the position of value X in list L (return a pointer
to the node containing X), return NULL if not found
*/
Node* find_value(int val, Node* head){
    Node* current = head;
    while (current != NULL){
        if (current->value == val) return current;
        current = current->next;
    }
    return NULL;
}

// Function to find the previous node of the node we want to delete
Node* find_previous(int val, Node* head){
    Node* current = head;
    while(current != NULL && current->next->value != val){
        current = current->next;
    }
    return current;
    // if the value to be removed is in the first node, the head is returned
}

// Function to delete a value from the list
Node* delete_val(int val, Node* head){
    Node* previous = find_previous(val, head);
    if (previous == NULL){
        return head; // value not found in the list
    }
    Node* to_delete = previous->next;
    if (to_delete == NULL) {
        return head; // value not found in the list
    }
    previous->next = to_delete->next;
    // use the FREE function to deallocate the memory for the node
    free(to_delete); 
    return head;
}

void print_list(Node* head){
    Node* current = head;
    while (current != NULL){
        printf("%d ", current->value);
        current = current->next;
    }
}




