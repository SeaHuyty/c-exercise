// Prime Numbers: Display prime numbers between 3 and 45.
#include <stdio.h>

int main() {
    int number = 45;
    printf("Prime numbers between 3 to 45 are: ");
    for (int i = 3; i < number; i++) {
        int prime = 1;
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                prime = 0;
                break;
            }
        }
        if (prime != 0) {
            printf("%d, ", i);
        }
    }
    printf("\b\b.\n");
    return 0;
}
