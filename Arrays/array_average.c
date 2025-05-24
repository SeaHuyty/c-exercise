// Calculate Average of Array Elements:
// Declare an array of integers and initialize it. Calculate and print the average of all elements.

#include <stdio.h>

int main() {
    int task_five[] = {10, 20, 30, 40, 50};
    int sum_five = 0;
    int size = sizeof(task_five) / sizeof(task_five[0]);
    int i;
    float average_five;

    // Sum all elements and print the addition expression
    for (i = 0; i < size; i++) {
        sum_five += task_five[i];
        printf("%d", task_five[i]);
        if (i < size - 1) {
            printf(" + ");
        }
    }
    printf(" = %d\n", sum_five);

    // Calculate average as a float for precision
    average_five = (float)sum_five / size;

    printf("Average of elements in the array = %.2f\n", average_five);

    return 0;
}
