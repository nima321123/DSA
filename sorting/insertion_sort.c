#include <stdio.h>

void mySort(int arr[], int size){
   int min, index, temp;
   for (int i = 0; i < size; i ++){
      min = i;
      for (index = i + 1; index < size; index ++){
         if (arr[index] < arr[min]){
            min = index;
         }
      }
      //swap
      temp = arr[i];
      arr[i] = arr[min];
      arr[min] = temp;
   }

}

void printArray(int arr[], int n) {
   int i;
   for (i = 0; i < n; i++)
       printf("%d ", arr[i]);
   printf("\n");
}

int main() {
   int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5};
   int n = sizeof(arr) / sizeof(arr[0]);

   mySort(arr, n);
   printArray(arr, n);

   return 0;
}