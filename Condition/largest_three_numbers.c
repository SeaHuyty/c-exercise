// Largest of Three Numbers: Ask the user to enter three integers and print the largest one.
#include <stdio.h>

int main() {
    int number1, number2, number3;

    printf("Please enter the first integer value: ");
    scanf("%d", &number1);

    printf("Please enter the second integer value: ");
    scanf("%d", &number2);

    printf("Please enter the third integer value: ");
    scanf("%d", &number3);

    if (number1 > number2 && number1 > number3) {
        printf("The first integer you entered is the largest number.\n");
    }
    else if (number2 > number1 && number2 > number3) {
        printf("The second integer you entered is the largest number.\n");
    }
    else {
        printf("The third integer you entered is the largest number.\n");
    }

    return 0;
}
