// Exercise Name: Calculate Average Grades for Students
// Exercise Instruction:
// Define a Student struct with fields for an ID, a name, and an array of 5 grades. Create an array of 5 students initialized with sample data. Write a function calculateAverage that takes a Student struct and returns the average of the student's grades as a floating-point number. In the main function, loop through the array of students and print each student's name along with their average grade formatted to two decimal places.

#include <stdio.h>

struct Student {
    int id;
    char name[50];
    int grades[5];
};

struct Student students[5] = {
    {1, "Alice", {85, 92, 78, 94, 88}},
    {2, "Bob", {76, 81, 72, 85, 79}},
    {3, "Charlie", {93, 89, 84, 91, 95}},
    {4, "David", {65, 70, 75, 60, 80}},
    {5, "Eve", {54, 68, 72, 77, 65}}
};

float calculateAverage(struct Student student) {
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += student.grades[i];
    }
    return sum / 5.0;
}

int main() {
    for (int i = 0; i < 5; i++) {
        float average = calculateAverage(students[i]);
        printf("Student: %s, Average Grade: %.2f\n", students[i].name, average);
    }
    return 0;
}
