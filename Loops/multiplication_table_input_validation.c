// Multiplication Table with Input Validation: Ask the user to enter a positive number. If the number is not positive, ask again. When a valid number is entered, print its multiplication table from 1 to 10.
#include <stdio.h>

int main() {
    int number;

start:  // Label for goto to restart input if invalid
    printf("Enter a positive integer for multiplication list: ");
    scanf("%d", &number);

    if (number < 0) {
        printf("It's not a positive integer!!\n");
        goto start;  // Restart input
    } else if (number == 0) {
        printf("Please enter a positive number bigger than zero!!\n");
        goto start;  // Restart input
    } else {
        // Print multiplication table for the entered number
        for (int i = 1; i <= 10; i++) {
            printf("%d * %d = %d\n", number, i, number * i);
        }
    }

    return 0;
}