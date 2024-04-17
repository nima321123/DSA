//Write C program for addition of two polynomials (exponents already arranged from highest to lowest)
#include <stdio.h>
#include <stdlib.h>
//define struct for the linked list
typedef struct Node{
    int coefficient;
    int exponent;
    struct Node* next;
}Node;

//function to input polynomial 
Node* input(Node* head){
    printf("Enter a polynomial (highest exponent to lowest exponent):\n");
    printf("Coefficient of (x1): ");
    scanf(" %d", &head->coefficient);
    printf("Exponent of (x1): ");
    scanf(" %d", &head->exponent);
    printf("Continue? y/n: ");
    char response;
    scanf(" %c", &response);
    int count = 1;
    //create a "traveller node";
    Node* traveller = head;
    while (response == 'y' || response == 'Y'){
        count ++;
        //create a new node
        Node* temp = malloc(sizeof(Node));

        //input value for the new node
        printf("Coefficient of (x%d): ", count);
        scanf(" %d", &temp->coefficient);
        printf("Exponent of (x%d): ", count);
        scanf(" %d", &temp->exponent);

        //add the temp node to the original list
        traveller->next = temp;
        temp->next = NULL;
        traveller = traveller->next;
        printf("Continue? y/n: ");
        scanf(" %c", &response);
    }
    return head;
}

//function for polynomial addition
Node* polynomial_add(Node* head1, Node* head2){
    //create a new linked list to store the result
    Node* result = malloc(sizeof(Node));
    Node* traveller_result = result;
    //create "traveller node" for list1 and list2
    Node* traveller1 = head1;
    Node* traveller2 = head2;
    while(traveller1 != NULL && traveller2 != NULL){
        // Allocate a new node only if there are more coefficients to add
        if (traveller1->next != NULL || traveller2->next != NULL) {
            traveller_result->next = malloc(sizeof(Node));
        }
        //case 1: same exponent
        if (traveller1->exponent == traveller2->exponent){
            traveller_result->coefficient = traveller1->coefficient + traveller2->coefficient;
            traveller_result->exponent = traveller1->exponent;
            
            traveller1 = traveller1->next;
            traveller2 = traveller2->next;
        }
        //case 2: one exponent is higher
        else if (traveller1->exponent > traveller2->exponent){
            traveller_result->coefficient = traveller1->coefficient;
            traveller_result->exponent = traveller1->exponent;
            traveller1 = traveller1->next;
        }
        else{
            traveller_result->coefficient = traveller2->coefficient;
            traveller_result->exponent = traveller2->exponent;
            traveller2 = traveller2->next;
        }
        traveller_result = traveller_result->next;
    }
    //adding the remaining nodes
    while (traveller1 != NULL){
        
        traveller_result->coefficient = traveller1->coefficient;
        traveller_result->exponent = traveller1->exponent;
        if (traveller1->next != NULL){
            traveller_result->next = malloc(sizeof(Node));
            traveller_result = traveller_result->next;
            traveller1 = traveller1->next;
        }
        
    }
    while (traveller2 != NULL){
        traveller_result->coefficient = traveller2->coefficient;
        traveller_result->exponent = traveller2->exponent;
        if (traveller2->next != NULL){
            traveller_result->next = malloc(sizeof(Node));
            traveller_result = traveller_result->next;
            traveller2 = traveller2->next;
        }
        
    }
    return result;
}

//function to print a polynomial
void print_polynomial(Node* head){
    int count = 1;
    Node* traveller = head;
    while (traveller->next!= NULL){
        printf("%d(x%d)^%d + ", traveller->coefficient, count, traveller->exponent);
        count++;
        traveller = traveller->next;
    }
    //print the last node
    //printf("%d(x%d)^%d", traveller->coefficient, count, traveller->exponent);
}

int main(){
    //input polynomials to be added
    Node* head1 = malloc(sizeof(Node));
    Node* head2 = malloc(sizeof(Node));
    head1 = input(head1);
    head2 = input(head2);
    //print the input polynomials for confirmation
    printf("Frist polynomial: ");
    print_polynomial(head1);
    printf("\n");
    printf("Second polynomial: ");
    print_polynomial(head2);
    printf("\n");
    //add the polynomials
    printf("Result polynomial: ");
    Node* result = polynomial_add(head1, head2);
    print_polynomial(result);
    return 0;
}
