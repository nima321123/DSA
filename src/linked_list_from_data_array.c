#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
} node;

node* create_node(int data){
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void print_list(node* head){
    node* current = head;
    while (current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
}

node* array_to_linked_list(int* arr, int size){
    node* head = create_node(arr[0]);
    node* current = head;
    for (int i = 1; i < size; i++){
        current->next = create_node(arr[i]);
        current = current->next;
    }
    return head;
}

node* push_back(node* head, int value){
    node* new_node = create_node(value);
    node* current = head;
    while (current->next != NULL){
        current = current->next;
    }
    current->next = new_node;
    return head;

}



int main(){
    int size;
    int value;
    printf("How many elements? ");
    scanf("%d", &size);

    int my_array[size];
    for (int i = 0; i < size; i++){
        printf("\nEnter a number: ");
        scanf("%d", &my_array[i]);
    }

    node* head = array_to_linked_list(my_array, size);
    print_list(head);

    printf("\nEnter a number to push back: ");
    scanf("%d", &value);

    head = push_back(head, value);
    print_list(head);
    return 0;
}