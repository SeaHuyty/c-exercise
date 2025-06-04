// Star Pattern: Construct the below pattern of stars using nested for loops.
// *
// **
// ***
// ****
// *****
// ****
// ***
// **
// *
#include <stdio.h>

int main() {
    for(int i = 1; i <= 5; i++) {
        for(int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
    for(int k = 4; k >= 1; k--) {
        for(int t = 1; t <= k; t++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
