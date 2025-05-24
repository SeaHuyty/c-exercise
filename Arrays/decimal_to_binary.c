// Exercise: Convert a decimal number to binary (8-bit representation)

#include <stdio.h>

int main() {
    int binarynum[8];
    int binnote[8] = {128, 64, 32, 16, 8, 4, 2, 1};
    int num;

    printf("Input decimal number (0-255): ");
    scanf("%d", &num);

    if (num < 0 || num > 255) {
        printf("Number out of range! Please enter a number between 0 and 255.\n");
        return 1;
    }

    for (int i = 0; i < 8; i++) {
        if (num >= binnote[i]) {
            binarynum[i] = 1;
            num -= binnote[i];
        } else {
            binarynum[i] = 0;
        }
    }

    printf("Binary: ");
    for (int k = 0; k < 8; k++) {
        printf("%d", binarynum[k]);
    }
    printf("\n");

    return 0;
}
