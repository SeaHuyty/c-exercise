#include <stdio.h>

int main() 
{

    // TODO

    //  Enter the first person date of birth (year/month/day)
    //  Enter the second person date of birth (year/month/day)
    
    //  Depending on the 2 dates of birth, print either:
    //  - The first person is the youngest
    //  - The second person is the youngest
    //  - Both persons have the same age

    int year1, month1, day1;
    int year2, month2, day2;

    printf("Enter the first person date of birth (year/month/day): ");
    scanf("%d/%d/%d", &year1, &month1, &day1);

    printf("Enter the second person date of birth (year/month/day): ");
    scanf("%d/%d/%d", &year2, &month2, &day2);

    if (year1 < year2 || (year1 == year2 && month1 < month2) || (year1 == year2 && month1 == month2 && day1 < day2)) {
        printf("The first person is the youngest\n");
    } else if (year2 < year1 || (year2 == year1 && month2 < month1) || (year2 == year1 && month2 == month1 && day2 < day1)) {
        printf("The second person is the youngest\n");
    } else {
        printf("Both persons have the same age\n");
    }

    return 0;
}
