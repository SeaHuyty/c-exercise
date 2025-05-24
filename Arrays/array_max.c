// Find Maximum Value in Array:
// Declare an array of integers and initialize it. Find and print the maximum value in the array.

#include <stdio.h>

int main() {
    int task_four[] = {5, 10, 15, 20, 25};
    int size = sizeof(task_four) / sizeof(task_four[0]);
    int max = task_four[0];  // Assume first element is the maximum

    // Loop through array to find the maximum value
    for (int i = 1; i < size; i++) {
        if (task_four[i] > max) {
            max = task_four[i];  // Update max if a bigger number is found
        }
    }

    printf("The maximum value in the array is: %d\n", max);

    return 0;
}