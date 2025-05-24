// Numbers Divisible by 7 but Not by 5:
// Write a program to print all the numbers between 1000 and 2000 which are divisible by 7 but not a multiple of 5.
#include <stdio.h>

int main() {
    for (int between = 1000; between <= 2000; between++) {
        if ((between % 7 == 0) && (between % 5 != 0)) {
            printf("%d\n", between);
        }
    }

    return 0;
}
