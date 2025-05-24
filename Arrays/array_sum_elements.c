// Sum of Elements in an Integer Array:
// Create a program that calculates the sum of all elements in an integer array of size 7.

#include <stdio.h>

int main() {
    int task_two[] = {1, 2, 3, 4, 5, 6, 7};
    int sum = 0;

    // Loop through array and add each element to sum
    for (int i = 0; i <= 6; i++) {
        sum += task_two[i];
    }

    printf("\nSum = %d\n", sum);

    return 0;
}
