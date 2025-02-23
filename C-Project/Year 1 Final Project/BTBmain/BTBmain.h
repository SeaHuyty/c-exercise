#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



void updateSeat_file5(int seats, int seatArray[], char *file5) {
    FILE *file = fopen(file5, "w");
    if (file == NULL) {
        printf("Can't open the file %s\n", file5);
        exit(0);
    }
    for (int i = 0; i < seats; i++) {
        if (seatArray[i] == -1) {
            fprintf(file, "x\n");
        } else {
            fprintf(file, "%d\n", seatArray[i]);
        }
    }
    fclose(file);
}

void printSeats5(int seats, int seatArray[]) {
    for (int i = 0; i < seats; i++) {
        if (i % 4 == 0 && i != 0) {
            printf("\n");
        }
        if (seatArray[i] == -1) {
            printf("  x ");
        } else {
            printf(" %d", seatArray[i]);
            if (i % 2 == 1) {
                printf("\t");
            }
        }
    }
    printf("\n");
}

void seatBTB(int seats, char *file5, float price) {
    FILE *file = fopen(file5, "r");
    if (file == NULL) {
        printf("Can't open the file %s\n", file5);
        exit(0);
    }

    int seatArray[seats];
    char buffer[4];
    int index = 0;

    while (fgets(buffer, sizeof(buffer), file)) {
        if (buffer[0] == 'x') {
            seatArray[index++] = -1;
        } else {
            seatArray[index++] = atoi(buffer);
        }
    }
    fclose(file);

    system("cls");
    printf("\n-------------------------------------------------------Available seats of bus------------------------------------------------------\n");
    printSeats5(seats, seatArray);

    printf("\n\nEnter number of seats you want to reserve: ");
    int n;
    scanf("%d", &n);
    if (n > seats) {
        printf("\nError: You can't reserve more seats than available.\n");
        return;
    }

    int unavailable[n];
    for (int i = 0; i < n; i++) {
        int seatNum;
        printf("\n\nReserve number: ");
        scanf("%d", &seatNum);

        // Validate if the seat is within the valid range and not already reserved or already chosen
        if (seatNum <= 0 || seatNum > seats) {
            printf("Seat number %d is invalid. Please choose a seat number between 1 and %d.\n", seatNum, seats);
            i--;
            continue;
        }

        int isReserved = 0;
        for (int j = 0; j < seats; j++) {
            if (seatArray[j] == seatNum || seatArray[j] == -1) {
                isReserved = 1;
                break;
            }
        }
        for (int k = 0; k < i; k++) {
            if (unavailable[k] == seatNum) {
                isReserved = 1;
                break;
            }
        }
        if (isReserved) {
            printf("Seat %d is available.\n", seatNum);
            i--;
        } else {
            unavailable[i] = seatNum;
        }
    }

    // Calculate price with tax and confirm reservation
    float totalPrice = price * n;
    float tax = totalPrice * 0.1;
    float finalPrice = totalPrice + tax;

    printf("\n------------------------------Reservation details-------------------------------\n");
    printf("Total price: $%.2f\n", totalPrice);
    printf("Tax (10%%): $%.2f\n", tax);
    printf("Final price: $%.2f\n", finalPrice);

    char confirm;
    printf("\n\nDo you want to confirm the reservation? (y/n): ");
    scanf(" %c", &confirm);

    if (confirm == 'y' || confirm == 'Y') {
        // Update the seatArray for reserved seats
        for (int i = 0; i < seats; i++) {
            for (int j = 0; j < n; j++) {
                if (seatArray[i] == unavailable[j]) {
                    seatArray[i] = -1;

                    // Add timestamp
                    time_t t = time(NULL);
                    struct tm tm = *localtime(&t);
                    printf("Reserved seat %d on %d-%02d-%02d %02d:%02d:%02d\n",
                           unavailable[j],
                           tm.tm_year + 1900,
                           tm.tm_mon + 1,
                           tm.tm_mday,
                           tm.tm_hour,
                           tm.tm_min,
                           tm.tm_sec);
                }
            }
        }
        // Write the updated seats back to the file
        updateSeat_file5(seats, seatArray, file5);

        printf("\nUpdated available seats of bus\n");
        printSeats5(seats, seatArray);

        printf("Reserved seats: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", unavailable[i]);
        }
        printf("\n");
    } else {
        printf("Reservation canceled.\n");
    }
}

void BTBmain() {
    FILE *file = fopen("pp_btb.txt", "r");
    char buffer[255];
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }
    fclose(file);

    int choice;
    int seat1 = 56;
    char file1[25] = "BTBseat1.txt";
    float price1 = 14.5;

    int seat2 = 40;
    char file2[25] = "BTBseat2.txt";
    float price2 = 13.0;

    int seat3 = 16;
    char file3[25] = "BTBseat3.txt";
    float price3 = 10.0;

    int seat4 = 12;
    char file4[25] = "BTBseat4.txt";
    float price4 = 12.0;

    while (1) {
        printf("Enter your choice (1-4 to reserve, 5 to exit): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                seatBTB(seat1, file1, price1);
                break;
            case 2:
                seatBTB(seat2, file2, price2);
                break;
            case 3:
                seatBTB(seat3, file3, price3);
                break;
            case 4:
                seatBTB(seat4, file4, price4);
                break;
            case 5:
                return;
            default:
                printf("Invalid choice.\n\nPlease try again.\n");
                break;
        }
    }
}
