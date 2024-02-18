// Get the largest element of an array using recursion.

#include <stdio.h>
#include <stdlib.h>
void largest_ele(int* arr, int* result, int i, int size){
    if (i == size) return;
    if (*(arr + i) > *result) *result = *(arr + i);
    largest_ele(arr, result, i+1, size);
}
int main()
{
    int arr[] = {1, 3, 8, 288, 19};
    int* result = (int*)malloc(sizeof(int));
    *result = 0;
    int i = 0;
    
    largest_ele(arr, result, i, 5);
    printf("Largest element: %d", *result);

    return 0;
}
