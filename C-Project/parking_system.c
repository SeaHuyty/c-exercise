#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
// This is a parking system that use a 24-hour time format.
// The parking lot open from 1:00 to 24:00.
    int options = 1, start_time, start_hour, start_minute, leave_hour, leave_minute, parking_fee, total_parking_time;
    int motorcycle = 0, car = 0, bicycle = 0, total_income;
    int option;
int main () {
    while (options =! 0) {
    system("cls");
    printf("-----Parking System-----\n");
    printf("1. Motorcycle\n2. Car\n3. Bicycle\n4. Income\n5. Exit\n");
    printf("=>Select option: "); scanf("%d", &option);
    switch(option) {
        case 1:
            system("cls");
            printf("-----Motorcycle-----\n");
            printf("Start time: "); scanf("%d:%d", &start_hour, &start_minute);
            printf("Leave time: "); scanf("%d:%d", &leave_hour, &leave_minute);
            total_parking_time = (leave_hour + (leave_minute/60)) - (start_hour + (start_minute/60));
            parking_fee = total_parking_time * 1000;
            motorcycle = motorcycle + 1;
            total_income = total_income + parking_fee;
            printf("Total Parking time: %d hours\n", total_parking_time);
            printf("Parking fee       : %d riel", parking_fee);
            getch();
            break;
        case 2:
            system("cls");
            printf("-----Car-----\n");
            printf("Start time: "); scanf("%d:%d", &start_hour, &start_minute);
            printf("Leave time: "); scanf("%d:%d", &leave_hour, &leave_minute);
            total_parking_time = (leave_hour + (leave_minute/60)) - (start_hour + (start_minute/60));
            parking_fee = total_parking_time * 2500;
            car = car + 1;
            total_income = total_income + parking_fee;
            printf("Total Parking time: %d hours\n", total_parking_time);
            printf("Parking fee       : %d riel", parking_fee);
            getch();
            break;
        case 3:
            system("cls");
            printf("-----Bicycle-----\n");
            printf("Start time: "); scanf("%d:%d", &start_hour, &start_minute);
            printf("Leave time: "); scanf("%d:%d", &leave_hour, &leave_minute);
            total_parking_time = (leave_hour + (leave_minute/60)) - (start_hour + (start_minute/60));
            parking_fee = total_parking_time * 500;
            bicycle = bicycle + 1;
            total_income = total_income + parking_fee;
            printf("Total Parking time: %d hours\n", total_parking_time);
            printf("Parking fee       : %d riel", parking_fee);
            getch();
            break;
        case 4:
            system("cls");
            printf("-----Income-----\n");
            printf("Number of: \n1. Motorcycle = %d\n2. Car = %d\n3. Bicycle = %d\n", motorcycle, car, bicycle);
            printf("Total income: %d", total_income);
            getch();
            break;
        case 5:
            system("cls");
            goto close_application;
            break;
        default: 
            system("cls");
            printf("Invalid Option!!\nPress any keys to go back.\n");
            getch();
            break;
    }
    }
    close_application:
    return 0;
}