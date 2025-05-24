// Identify Leap Years: Determine if a given year is a leap year based on leap year rules.
#include <stdio.h>

int main() {
    int year;
    printf("Leap year is a year that has 366 days with February having 29 days.\n");
    printf("Please enter a year: ");
    scanf("%d", &year);

    if (year <= 0) {
        printf("Please enter a valid year!!");
    }
    else if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        printf("It's a leap year!!");
    }
    else {
        printf("It's not a leap year");
    }

    return 0;
}
