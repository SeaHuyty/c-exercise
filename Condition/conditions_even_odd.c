// Identify Even or Odd Numbers: Ask user to enter an integer and determine if it is even or odd.
#include <stdio.h>

int main() {
    int odd_or_even;

    printf("Please enter an integer number: ");
    scanf("%d", &odd_or_even);

    if ((odd_or_even % 2) == 0) {
        printf("It's an even number!!");
    }
    else {
        printf("It's an odd number!!");
    }

    return 0;
}