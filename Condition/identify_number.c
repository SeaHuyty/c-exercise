// Identify Positive, Negative or Zero: Prompt user to enter a number and determine if it is positive, negative, or zero.
#include <stdio.h>

int main() {
    int identify;
    printf("Please enter an integer number: ");
    scanf("%d", &identify);

    if (identify == 0) {
        printf("It's zero");
    }
    else if (identify > 0) {
        printf("It's a positive number!!");
    }
    else {
        printf("It's a negative number!!");
    }

    return 0;
}
