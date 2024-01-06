//Allow user to enter a linked list then reverse it and print the result

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode{
    int val;
    struct ListNode* next;
};
//function declarations
struct ListNode* input(struct ListNode* head);
struct ListNode* reverse(struct ListNode* head);
void print(struct ListNode* head);

//function definitions
struct ListNode* input(struct ListNode* head){
    char response;
    struct ListNode* current = head;
    do{
        printf("Enter a number: ");
        scanf("%d", &(current->val));
        printf("Continue? (Y/N) ");
        scanf(" %c", &response);
        if (response != 'N' && response != 'n'){
            struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
            current->next = newNode;
            current = current->next;
        }
        
    }while (response != 'N' && response != 'n');
    return head;
}

struct ListNode* reverse(struct ListNode* head){
    struct ListNode* new_list = NULL;
    struct ListNode* previous = NULL;
    struct ListNode* current = head;
    struct ListNode* next_node = NULL;
    while (current){
        next_node = current->next; //save the next node
        current->next = new_list;
        new_list = current;
        current = next_node;
    }
    
    return new_list;
}

void print(struct ListNode* head){
    struct ListNode* current = head;
    while(current != 0){
        printf("%d ", current->val);
        current = current->next;
    }
}

int main(){
    struct ListNode* List = (struct ListNode*)malloc(sizeof(struct ListNode));
    List->next = NULL;
    List = input(List);
    print(reverse(List));
}