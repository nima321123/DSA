#include <stdio.h>

/*
   SELECTION SORT
      - Time complexity:
         O(N^2) (Best = Average = Worst)
      - Space complexity: O(1)

      
   arr[] = 64 25 12 22 11

   Find the minimum element in arr[0...4]
   and place it at beginning
   11 25 12 22 64

   Find the minimum element in arr[1...4]
   and place it at beginning of arr[1...4]
   11 12 25 22 64

   Find the minimum element in arr[2...4]
   and place it at beginning of arr[2...4]
   11 12 22 25 64

   Find the minimum element in arr[3...4]
   and place it at beginning of arr[3...4]
   11 12 22 25 64 
*/

void SelectionSort(int arr[], int size){
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

   SelectionSort(arr, n);
   printArray(arr, n);

   return 0;
}

