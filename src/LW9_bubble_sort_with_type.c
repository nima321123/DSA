
#include <stdio.h>
#include <string.h>
// exchange values of the pointers
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int* arr, int N)
{
    if (N >= 2)
    {
        for (int i = 0; i < N - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(&(arr[i]), &arr[i + 1]);
            }
        }

        bubble_sort(arr, N - 1);
    }
}

int greater(int a, int b)
{
    return a > b ? 1 : 0; // ternary operator
}

int less(int a, int b)
{
    return a < b ? 1 : 0; // ternary operator
}

void bubble_sort_with_type(int* arr, int N, int (*compare_func)(int, int)) {
    if(N >= 2) {
        for (int i = 0; i < N - 1; i++) {
            if (compare_func(arr[i], arr[i + 1])) {
                swap(&(arr[i]), &(arr[i + 1]));
            }
        }

        bubble_sort_with_type(arr, N - 1, compare_func);
    }
}

int main()
{
    int N = 5;
    int arr[] = {1, 4, 3, 7, 6};

    bubble_sort_with_type(arr, N, greater); // [7, 6, 4, 3, 1]
    //print the sorted array
    for (int i = 0; i < N; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    bubble_sort_with_type(arr, N, less); // [1, 3, 4, 6, 7]
    //print the sorted array
    for (int i = 0; i < N; i++){
        printf("%d ", arr[i]);
    }
    return 0; // set break point
}