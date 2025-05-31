// Compare Two Integers: Prompt user to enter two integers and determine if they are equal or which one is bigger.
#include <stdio.h>

int main() {
    int x;
    int y;

    printf("Enter an integer value of x: ");
    scanf("%d", &x);

    printf("Enter an integer value of y: ");
    scanf("%d", &y);

    if (x > y) {
        printf("The value of x is bigger than the value of y.");
    } else if (x < y) {
        printf("The value of y is bigger than the value of x.");
    } else {  // covers x == y
        printf("The value of x is equal to the value of y.");
    }

    return 0;
}