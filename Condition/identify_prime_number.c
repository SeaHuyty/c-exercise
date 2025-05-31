// Identify a Prime Number: Write a program to check if a number entered by the user is prime.
#include <stdio.h>

int main() {
    int prime;
    int notprime = 1;
    printf("Please enter an integer number: ");
    scanf("%d", &prime);

    if (prime == 2) {
        printf("It's a prime number!!");
    } else if (prime == 1) {
        printf("It's not a prime number!!");
    } else {
        for (int i = 2; i < prime; i++) {
            if (prime % i == 0) {
                notprime = 0;
                break;
            }
        }
        if (notprime == 0) {
            printf("It's not a prime number");
        } else {
            printf("It's a prime number!!");
        }
    }
    return 0;
}