#include <stdlib.h>
#include <stdio.h>



int main(){
    int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, n);
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}