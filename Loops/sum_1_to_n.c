// Sum From 1 to N: Let user enter a positive integer and calculate the total sum from 1 to that number.
#include <stdio.h>

int main() {
    int index;
    int i;
    int sum = 0;

    printf("Please enter a positive integer: ");
    scanf("%d", &index);

    for(i = 1; i <= index; i++) {
        printf(" %d +", i);
        sum += i;
    }
    printf("\b = %d\n", sum);

    return 0;
}
