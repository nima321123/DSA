//reverse array by swapping elements

#include <stdio.h>
#include <stdlib.h>

void reverse_array(int* arr, int size){
    int temp;
    int mid = size/2;
    for (int i = 0; i < mid; i++){
        temp = arr[i];
        arr[i] = arr[size-i-1];
        arr[size - i - 1] = temp;
    }
    
}

int main(){
    int size;
    printf("How many elements? ");

    scanf("%d", &size);
    int my_array[size];

    for (int i = 0; i < size; i++){
        printf("\nEnter a number: ");
        scanf("%d", &my_array[i]);
    }

    reverse_array(my_array, size);

    for (int i = 0; i < size; i++){
        printf("%d ", my_array[i]);
    }
    return 0;

}