// Print Elements of an Integer Array:
// Write a program to declare and initialize an integer array of size 5,
// then use a loop to print all its elements.

#include <stdio.h>

int main() {
    int task_one[] = {1, 2, 3, 4, 5};

    // Loop through array and print each element
    for (int i = 0; i <= 4; i++) {
        printf("%d ", task_one[i]);
    }

    printf("\n"); // Add newline for cleaner output

    return 0;
}