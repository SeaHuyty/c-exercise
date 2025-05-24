// Copy Contents from One Array to Another:
// Write a program to copy the contents of one integer array into another array of the same size.

#include <stdio.h>

int main() {
    int task_three[] = {5, 4, 3, 2, 1};
    int task_three_parallel[5];  // Corrected size to match the source array

    // Copy elements from task_three to task_three_parallel
    for (int i = 0; i <= 4; i++) {
        task_three_parallel[i] = task_three[i];
    }

    // Print original array
    printf("Original array: ");
    for (int i = 0; i <= 4; i++) {
        printf("%d ", task_three[i]);
    }

    // Print copied array
    printf("\nCopied array: ");
    for (int i = 0; i <= 4; i++) {
        printf("%d ", task_three_parallel[i]);
    }

    return 0;
}
