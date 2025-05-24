// Day of the Week by Number: User inputs a number (1-7) and program prints the corresponding day of the week.
#include <stdio.h>

int main() {
    int daynumber;
    printf("Enter a number between 1 and 7: ");
    scanf("%d", &daynumber);

    switch (daynumber) {
        case 1:
            printf("Monday");
            break;
        case 2:
            printf("Tuesday");
            break;
        case 3:
            printf("Wednesday");
            break;
        case 4:
            printf("Thursday");
            break;
        case 5:
            printf("Friday");
            break;
        case 6:
            printf("Saturday");
            break;
        case 7:
            printf("Sunday");
            break;
        default:
            printf("Please enter a valid number");
    }

    return 0;
}