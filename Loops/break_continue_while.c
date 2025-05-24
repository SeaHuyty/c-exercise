// Using break and continue in a While Loop

#include <stdio.h>

int main() {
    int number;
    while (1) {
        printf("Enter a number: ");
        scanf("%d", &number);
        if (number <= 0) {
            break; // terminate the loop if number equal or less than 0.
        }
        if ((number % 2) != 0) {
            continue; // skip if number is odd
        }
        printf("%d\n", number);
    }
    return 0;
}