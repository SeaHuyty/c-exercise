// Exercise: Convert an 8-bit binary number to decimal

#include <stdio.h>

int main() {
    int binnote[8] = {128, 64, 32, 16, 8, 4, 2, 1};
    int binnum[8];
    int decimal = 0;

    printf("Input binary number (8 bits, e.g. 1 1 1 0 1 1 1 1): ");
    // Note: The original code has an error in scanf with 9 arguments for an 8-element array
    if (scanf("%d %d %d %d %d %d %d %d", 
              &binnum[0], &binnum[1], &binnum[2], &binnum[3], 
              &binnum[4], &binnum[5], &binnum[6], &binnum[7]) != 8) {
        printf("Invalid input. Please enter exactly 8 binary digits.\n");
        return 1;
    }

    // Validate binary input (only 0 or 1)
    for (int i = 0; i < 8; i++) {
        if (binnum[i] != 0 && binnum[i] != 1) {
            printf("Invalid binary digit detected: %d. Use only 0 or 1.\n", binnum[i]);
            return 1;
        }
    }

    for (int i = 0; i < 8; i++) {
        decimal += binnote[i] * binnum[i];
    }

    printf("Decimal number: %d\n", decimal);

    return 0;
}
