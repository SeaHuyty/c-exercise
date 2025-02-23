#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int main () {
    // Exercise: Convert Binary to Decimal.
    int binnote[8] = {128, 64, 32, 16, 8, 4, 2, 1};
    int binnum[8];
    int decimal = 0;
    printf("Input binary number (Sample: 1 1 1 0 1 1 1 1): "); scanf("%d %d %d %d %d %d %d %d", &binnum[0], &binnum[1], &binnum[2], &binnum[3], &binnum[4], &binnum[5], &binnum[6], &binnum[7], &binnum[8]);
    for (int i = 0; i < 8; i++) {
        decimal += (binnote[i] * binnum[i]);
    }
    printf("Decimal number: %d", decimal);
    return 0;
}
