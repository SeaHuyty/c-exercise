// Count Positive Numbers Until Negative is Entered:
// Ask the user to enter numbers. Keep accepting input using a while loop.
// Stop when a negative number is entered. Then print how many positive numbers were entered.

#include <stdio.h>

int main() {
    int num;
    int count = 0;

    printf("1. Use while loop and input positive number until a negative number is entered.\n");

    // Use while loop to repeatedly ask for number until user enters a negative number
    while (1) {
        printf("\tEnter any number: ");
        scanf("%d", &num);

        if (num < 0) {
            break;  // Exit loop if negative number is entered
        }

        count++;  // Count only positive numbers
    }

    printf("\tTotal positive numbers entered: %d\n", count);

    return 0;
}
