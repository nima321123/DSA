#include <stdio.h>

// Function to calculate the Stirling number of the second kind
int stirling(int n, int k) {
    // Base case: If both n and k are 0, there is exactly one way to partition an empty set
    if (n == 0 && k == 0) {
        return 1;
    } 
    // If either n or k is 0, return 0 as there are no ways to partition an empty set or to partition a set into 0 subsets.
    else if (n == 0 || k == 0) {
        return 0;
    } 
    else {
        // If both n and k are non-zero, use the recursive formula for Stirling numbers of the second kind:
        // S(n, k) = k*S(n-1, k) + S(n-1, k-1)
        // The first term, k*S(n-1, k), represents the number of ways to partition a set of n elements into k non-empty subsets
        // where each subset contains at least one of the n elements.
        // The second term, S(n-1, k-1), represents the number of ways to partition a set of n elements into k non-empty subsets
        // where one of the subsets is a singleton set containing the nth element.
        return k * stirling(n - 1, k) + stirling(n - 1, k - 1);
    }
}

int main() {
    int n = 4; // The number of elements in the set
    int k = 3; // The number of subsets to partition the set into
    // Call the stirling function to calculate the Stirling number of the second kind, S(n, k),
    // and print the result.
    printf("S(%d, %d) = %d\n", n, k, stirling(n, k));
    return 0;
}