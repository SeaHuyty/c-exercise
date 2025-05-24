// Sum with Special Condition: Write a program to sum two integers.
// If the sum is between 15 and 20, it will return 20.
#include <stdio.h>

int main() {
    int x;
    int y;
    int sum;

    printf("Enter the first integer number: ");
    scanf("%d", &x);
    printf("Enter the second integer number: ");
    scanf("%d", &y);

    sum = x + y;

    if (sum < 20 && sum > 15) {
        printf("20");
    } else {
        printf("The value of sum = %d", sum);
    }

    return 0;
}
