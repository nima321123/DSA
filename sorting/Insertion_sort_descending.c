#include<stdio.h>

void InsertDescend(int arr[], int size){
    int i, j, key;
    for (i = 1; i < size; i++){
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] < key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArr(int arr[], int size){
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    int array[] = {2, 9, 5, 6, 1, 83};
    int size = sizeof(array)/sizeof(int);
    InsertDescend(array, size);
    printArr(array, size);
    return 0;
}