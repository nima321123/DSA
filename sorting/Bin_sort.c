#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define MAX_SIZE 100

void binSort(int a[], int size, int K) {
    int i, j, idx;
    int bins[K+1][MAX_SIZE];
    int bin_sizes[K+1];

    // Initialize bins and their sizes
    for (i = 0; i <= K; ++i) {
        bin_sizes[i] = 0;
        for (j = 0; j < MAX_SIZE; ++j) {
            bins[i][j] = 0;
        }
    }

    // Distribute the numbers in a[] into the bins
    for (i = 0; i < size; ++i) {
        idx = bin_sizes[a[i]]++;
        bins[a[i]][idx] = a[i];
    }

    // Print the numbers from the bins in order
    for (i = 0; i <= K; ++i) {
        for (j = 0; j < bin_sizes[i]; ++j) {
            printf("%d ", bins[i][j]);
        }
    }
}

int main() {
    int a[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int size = sizeof(a) / sizeof(a[0]);
    int K = 9; // Maximum value in a[]
    binSort(a, size, K);
    return 0;
}