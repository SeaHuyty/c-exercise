// Sum Student Scores Using Arrays: Use an array to store student scores and then calculate the total of the student's scores.
#include <stdio.h>

int main() {
    int student_score[] = {20, 40, 50, 45, 30};
    int sum = 0;
    char subject[][12] = {"Mathematic", "Physic", "Chemistry", "Histroy", "English"};

    printf("Score of your five subjects: \n");

    for (int i = 0; i <= 4; i++) {
        printf("    %s = %d\n", subject[i], student_score[i]);
        sum += student_score[i];
    }

    printf("Sum: %d points", sum);

    return 0;
}
