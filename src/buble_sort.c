#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void bubble_sort(int* arr, int size){
    int temp;
    for (int i = 0; i < size; i++){
        bool swapped = false;
        for (int j = 0; j < size - i - 1; j++){
            if (arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp; 
                swapped = true;
            }
        }
        if (!swapped){
            break;
        }
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

    bubble_sort(my_array, size);
    
    //print the sorted array
    for (int i = 0; i < size; i++){
        printf("%d ", my_array[i]);
    }
    return 0;

}