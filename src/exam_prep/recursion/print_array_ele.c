#include <stdio.h>

void p_ele(int* arr, int size, int i){
    if (i == size) return;
    //print in ascending order
    printf("%d ", *(arr + i));
    p_ele(arr, size, i + 1);
}

int main(){
    int arr[] = {2, 4, 9, 20};
    p_ele(arr, 4, 0);
    return 0;
}