#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include <conio.h>
int main () 
{
    int month_days, months, year, days;
    int starting_day, day_of_week;
    printf("CALENDER YEAR\n");
    printf("Input year : ");
    scanf("%d", &year);
    printf("Input month: "); scanf("%d", &months);
    system("cls");
        if (months == 2)
        {
            if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) 
            {
                month_days = 29;
            }
            else 
            {
                month_days = 28;
            }
        } 
            else if (months == 4 || months == 6 || months == 9 || months == 11) 
        {
            month_days = 30;
        } 
        else 
        {
            month_days = 31;
        }
        //calculate the starting day
        starting_day = ((year - 1) * 365) + ((year - 1) / 4) - ((year - 1)/100) + ((year - 1) / 400);
        for (int i = 1; i < months; i++)
        {
            if (i == 2)
            {
                if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
                {
                    starting_day += 29;
                } 
                else 
                {
                    starting_day += 28;
                } 
            } 
            else if (i == 4 || i == 6 || i == 9 || i == 11) 
            {
                starting_day += 30;
            } 
            else 
            {
                starting_day += 31;
            }
        }
        day_of_week = (starting_day + 1) % 7;
        //
        char month_name[12][15] = {"January","February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
        // printf calender box
        printf("\n\n  CALENDER : %d - %02s\n", year, month_name[months - 1]);
        printf("-------------------------------\n");
        printf(" SUN MON TUE WED THUR FRI SAT\n");
        // printf space in front of month day
        for (int i = 0; i < day_of_week; ++i)
        {
            printf("    ");
        }
        for (days = 1; days <= month_days; ++days) //printf day of month
        {
            printf("%4d", days);
            if ((days + day_of_week) % 7 == 0) // printf new line 
            {
                printf("\n");
            }
        }
    return 0;
}
