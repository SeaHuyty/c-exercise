// 3x3 Matrix Initialization and Printing: Initialize a 3x3 integer matrix and print its elements in a grid format.
#include <stdio.h>

int main() {
    int matrix[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i <= 2; i++) {
        for (int k = 0; k <= 2; k++) {
            printf("%d ", matrix[i][k]);
        }
        printf("\n");
    }
    return 0;
}