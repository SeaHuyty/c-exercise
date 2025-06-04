// FizzBuzz: Print numbers from 1 to 100. For multiples of 3, print “Fizz”; for multiples of 5, print “Buzz”; 
// and for multiples of both, print “FizzBuzz”.
#include <stdio.h>

int main() {
    for (int game = 1; game <= 100; game++) {
        if (game % 3 == 0 && game % 5 == 0) {
            printf("FizzBuzz\n");
        } else if (game % 5 == 0) {
            printf("Buzz\n");
        } else if (game % 3 == 0) {
            printf("Fizz\n");
        } else {
            printf("%d\n", game);
        }
    }

    return 0;
}
