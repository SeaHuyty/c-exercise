// Compare Ages by Date of Birth

// Exercise Instruction:
// Write a program that asks the user to input the date of birth for two persons in the format year/month/day. The program should then compare these two dates and print which person is the youngest. If both persons have the same birth date, print a message indicating they are the same age.

// Input format example: 1990/12/25

// Output should be one of the following messages:

// “The first person is the youngest”

// “The second person is the youngest”

// “Both persons have the same age”



#include <stdio.h>

int main() {
    int year1, month1, day1;
    int year2, month2, day2;

    // Input dates of birth for two persons
    printf("Enter the first person date of birth (year/month/day): ");
    scanf("%d/%d/%d", &year1, &month1, &day1);

    printf("Enter the second person date of birth (year/month/day): ");
    scanf("%d/%d/%d", &year2, &month2, &day2);

    // Compare the two dates to determine who is younger
    if (year1 < year2 || (year1 == year2 && month1 < month2) || (year1 == year2 && month1 == month2 && day1 < day2)) {
        printf("The first person is the youngest\n");
    } else if (year2 < year1 || (year2 == year1 && month2 < month1) || (year2 == year1 && month2 == month1 && day2 < day1)) {
        printf("The second person is the youngest\n");
    } else {
        printf("Both persons have the same age\n");
    }

    return 0;
}
