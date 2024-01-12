#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//merge two sorted linked struct Lists
struct List{
  int val;
  struct List* next;
};
//function declaration
struct List* createNode();
struct List* input(struct List* head);
struct List* mergeLists(struct List* l1, struct List* l2);
void printList(struct List* head);

//function definitions
struct List* createNode(){
  struct List* list = (struct List*)malloc(sizeof(struct List));
  if (list == NULL){
    printf("Fail to create list!");
    exit(0);
  }
  list->next = NULL;
  return list;
}

struct List* input(struct List* head){
  char response;
  struct List* dummy = createNode(); //first val is random
  struct List* current = dummy;
  
  while(1){
    current->next = createNode();
    current = current->next;
    printf("Enter a number: ");
    scanf("%d", &(current->val));
    
    printf("Continue? (Y/N) ");
    scanf(" %c", &response);
    
    if(response == 'N' || response == 'n'){
    break;
    }
  } 
  struct List* result = dummy->next;
  return result;
}

struct List* mergeLists(struct List* l1, struct List* l2){
  struct List* dummy = createNode(); //first val is random
  struct List* current = dummy;
 

  while(l1 && l2){

    current->next = createNode();
    current = current->next;

    if(l1->val<l2->val){
      current->val = l1->val;
      l1=l1->next;
    }
    else{
      current->val = l2->val;
      l2=l2->next;
    }
   
  }
  if (l1){
    current->next  = l1;
  }
  if (l2){
    current->next = l2;
  }
  struct List* result = dummy->next;
  free(dummy);
  return result;
}
void printList(struct List* head){
  struct List* current = head;
  while(current!= NULL){
    printf("%d ", current->val);
    current = current->next;
  }

}
int main(){
  struct List* l1 = createNode();
  struct List* l2 = createNode();

  l1 = input(l1);
  l2 = input(l2);

  printList(l1);
  printf("\n");
  printList(l2);
  printf("\n");
  printList(mergeLists(l1, l2));
}
