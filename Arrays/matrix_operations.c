// Matrix Operations:
// Write an algorithm that takes two 2D integer arrays (matrices) and their dimensions,
// then prints new matrices for their sum, difference, and multiplication.

#include <stdio.h>

int main() {
    int matrix_01[10][10], matrix_02[10][10];
    int matrix01_row, matrix01_column;
    int matrix02_row, matrix02_column;
    int matrix_sum[10][10], matrix_subtract[10][10], matrix_multiplication[10][10];

    printf("Write in this format, Example: 3x3, 3x2, 4x4\n");
    printf("Size of matrix_01: ");
    scanf("%dx%d", &matrix01_row, &matrix01_column);

    printf("Size of matrix_02: ");
    scanf("%dx%d", &matrix02_row, &matrix02_column);

    if ((matrix01_row * matrix01_column) != (matrix02_row * matrix02_column)) {
        printf("The two matrices do not have the same size. Cannot do addition and subtraction.\n");
        return 0;
    }
    else if (((matrix01_row * matrix01_column) > 100) || ((matrix02_row * matrix02_column) > 100)) {
        printf("The size of matrices can't be bigger than 10x10\n");
        return 0;
    }

    printf("\nMatrix_01:\n");
    for (int i = 0; i < matrix01_row; i++) {
        for (int j = 0; j < matrix01_column; j++) {
            printf("Row[%d]th column[%d]th: ", i + 1, j + 1);
            scanf("%d", &matrix_01[i][j]);
        }
    }

    printf("\nMatrix_02:\n");
    for (int i = 0; i < matrix02_row; i++) {
        for (int j = 0; j < matrix02_column; j++) {
            printf("Row[%d]th column[%d]th: ", i + 1, j + 1);
            scanf("%d", &matrix_02[i][j]);
        }
    }

    // Addition and Subtraction
    for (int k = 0; k < matrix01_row; k++) {
        for (int l = 0; l < matrix01_column; l++) {
            matrix_sum[k][l] = matrix_01[k][l] + matrix_02[k][l];
            matrix_subtract[k][l] = matrix_01[k][l] - matrix_02[k][l];
        }
    }

    // Multiplication (note: multiplication requires matrix01_column == matrix02_row)
    if (matrix01_column != matrix02_row) {
        printf("\nMatrix multiplication not possible due to incompatible dimensions.\n");
        return 0;
    }

    for (int a = 0; a < matrix01_row; a++) {
        for (int b = 0; b < matrix02_column; b++) {
            matrix_multiplication[a][b] = 0;
            for (int c = 0; c < matrix01_column; c++) {
                matrix_multiplication[a][b] += matrix_01[a][c] * matrix_02[c][b];
            }
        }
    }

    printf("\n\nThe sum of the two matrices: \n");
    for (int d = 0; d < matrix01_row; d++) {
        for (int n = 0; n < matrix01_column; n++) {
            printf("%d   ", matrix_sum[d][n]);
        }
        printf("\n");
    }

    printf("\n\nThe subtract of the two matrices: \n");
    for (int d = 0; d < matrix01_row; d++) {
        for (int n = 0; n < matrix01_column; n++) {
            printf("%d   ", matrix_subtract[d][n]);
        }
        printf("\n");
    }

    printf("\n\nThe multiplication of the two matrices: \n");
    for (int d = 0; d < matrix01_row; d++) {
        for (int n = 0; n < matrix02_column; n++) {
            printf("%d   ", matrix_multiplication[d][n]);
        }
        printf("\n");
    }

    return 0;
}
