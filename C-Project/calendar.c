#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include <conio.h>
    int month_days, months, year, days, starting_day, day_of_week, options = 0, option;
    void calculation() {
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
        // Set name for each months
        // Set the dimension of the month_name [][] the first for the number of element in it and the second for the number of letter in the dimension.
        char month_name[12][15] = {"January","February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
        // Display calender box
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
    }

int main () 
{
    while (options != 1) {
        system("cls");
        printf("----------------------\n       Calendar\n----------------------\n");
        printf("1. Year\n2. Month\n3. Exit\n==>Select option: "); scanf("%d", &option);
        switch(option) {
            case 1:
                system("cls");
                printf("----------Year----------\nYear : "); scanf("%d", &year);
                system("cls");
                for (months = 1; months <= 12; months++)
                {
                    calculation();
                }
                printf("\n\n<Press any keys to go back>");
                getch();
                break;
            case 2:
                system("cls");
                printf("----------Month----------\n");
                printf("Year : "); scanf("%d", &year);
                printf("Month: "); scanf("%d", &months);
                system("cls");
                calculation();
                printf("\n\n<Press any keys to go back>");
                getch();
                break;
            case 3:
                goto end;
                break;
            default:
                printf("Invalid Option!!\n\n<Press any keys to go back>\n");
                getch();
                break;
        }
    }
    end:
    return 0;
}