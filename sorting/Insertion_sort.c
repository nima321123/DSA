#include <stdio.h>
#include <stdlib.h>

void printList(int arr[], int size){
    
    for (int i=0; i < size; i++){
        printf("%d ", arr[i]);
    }
}

void insertionSort(int arr[], int size){
    int i, j, key;
    for (i = 1; i < size; i++){
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main(){
    int arr[] = {3, 9, 22, 1092, 4783, 29};
    int size = sizeof(arr)/sizeof(int);
    insertionSort(arr, size);
    printList(arr, size);
    return 0;
}