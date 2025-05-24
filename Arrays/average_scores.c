// Find Average and Scores Above Average:
// Write a program to ask a user for 10 scores, calculate the average,
// and display the scores that are greater than the average.

#include <stdio.h>

int main() {
    int score[10];
    int sum = 0;
    int n = 10;
    float average;

    printf("We're going to ask you for 10 scores\n");

    for (int i = 0; i < n; i++) {
        printf("Score [%d]: ", i + 1);
        scanf("%d", &score[i]);
        if (score[i] < 0) {
            printf("Score can't be lower than 0!!\n");
        }
        sum += score[i];
    }

    average = (float)sum / n;
    printf("Average = %.2f\n", average);

    printf("Scores that are above average: ");
    for (int k = 0; k < n; k++) {
        if (score[k] > average) {
            printf("%d, ", score[k]);
        }
    }
    printf("\b\b.\n");

    return 0;
}
