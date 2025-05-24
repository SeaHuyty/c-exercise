// Factorial Calculator:
// Write a program to calculate factorial of a number.
#include <stdio.h>

int main() {
    int number;
    int i = 1;
    int factorial = 1;

    printf("Enter a positive integer: ");
    scanf("%d", &number);

    if (number == 0) {
        printf("Factorial of 0 = 1");
    }
    else if (number < 0) {
        printf("Please enter a positive integer.\n");
    }
    else {
        printf("Factorial of %d: ", number);
        for (i = number; i >= 1; --i) {
            printf("%d x ", i);
            factorial *= i;
        }
        printf("\b\b");  // Removes the last " x"
        printf("= %d", factorial);
    }

    return 0;
}
