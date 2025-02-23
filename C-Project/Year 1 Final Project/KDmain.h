#include <stdio.h>
#include <stdlib.h>



void seatKD(int seats, char *file4, float price, char bus[]) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    FILE *file = fopen(file4, "r");
    if (file == NULL) {
        printf("Can't open the file %s\n", file4);
        exit(0);
    }
    
    int buffer;
    int seatArray[seats];
    int index = 0;

    while (fscanf(file, "%d", &buffer) != EOF) {
        seatArray[index++] = buffer;
    }
    fclose(file);

    love:
    system("cls");
    printf("\n---------------Available seats of bus---------------\n");

    for (int i = 0; i < seats; i++) {
        if (i % 4 == 0 && i != 0) {
            printf("\n");
        }
        if (seatArray[i] == 1) {
            printf(" X ");
        } else {
            printf(" %d", seatArray[i]);
            if (i % 2 == 1) {
                printf("\t");
            }
        }
    }
    printf("\n");

    printf("Enter number of seats you want to reserve: ");
    int n;
    scanf("%d", &n);
    int seatNum;
    int unavailable[n];
    for (int i = 0; i < n; i++) {
        printf("Reserve number: ");
        scanf("%d", &unavailable[i]);
    }
    // Calculate price with tax and confirm reservation
    float totalPrice = price * n;
    float tax = totalPrice * 0.1;
    float finalPrice = totalPrice + tax;

    printf("\n------------------------------Reservation details-------------------------------\n");
    printf("Total price: $%.2f\n", totalPrice);
    printf("Tax (10%%): $%.2f\n", tax);
    printf("\n\nFinal price: $%.2f\n", finalPrice);

    char confirm;
    printf("\n\nDo you want to confirm the reservation? (y/n): ");
    scanf(" %c", &confirm);
    fflush(stdin);

    if (confirm == 'y' || confirm == 'Y') {
      // Update the seatArray for reserved seats
      for (int i = 0; i < seats; i++) {
        for (int j = 0; j < n; j++) {
          if (seatArray[i] == unavailable[j]) {
            seatArray[i] = 1;
          }
        }
      }
        // Invoice
        printf("\n>>>>  Invoice  <<<<\n");
        char booking_name[15];
        printf("Your name: ");
        gets(booking_name);
        fflush(stdin);

        char booking_phone[12];
        printf("Phone number: ");
        gets(booking_phone);
        fflush(stdin);

        char departureDate[15];
        printf("Departure Date: ");
        gets(departureDate);
        fflush(stdin);

        // Write to file
        FILE *getin = fopen("BookingInvoice.txt", "a");
        fprintf(getin, "\n------------ Invoice -------------\n");
        fprintf(getin, "Name: %s\n", booking_name);
        fprintf(getin, "Phone Number:            %s\n", booking_phone);
        fprintf(getin, "Departure Date:         %s\n", departureDate);
        fprintf(getin, "\nDestination: Mondulkiri\n");
        fprintf(getin, "Reserved seat: ");
        for (int i = 0; i < n; i++) {
            fprintf(getin, "%d", unavailable[i]);
        }
        fprintf(getin, "\nFinal price: $%.2f\n", finalPrice);
        fprintf(getin, "\nBus type: %s\n", bus);
        fprintf(getin, "==================================\n");
        fprintf(getin, "Reservation Date:       %d-%02d-%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
        fprintf(getin, "Specific Time:               %02d-%02d\n", tm.tm_hour, tm.tm_min);
        fprintf(getin, "Expired Date:           %d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday + 2);
        fprintf(getin, "\n==================================\n");
        fclose(getin);

        // Display information
        system("cls");
        printf("------------ Invoice -------------\n");
        printf("Name: %s\n", booking_name);
        printf("Phone Number:            %s\n", booking_phone);
        printf("Departure Date:         %s\n\n", departureDate);
        printf("Destination: MondulKiri\n");
        printf("Reserved seat: ");
        for (int i = 0; i < n; i++) {
            printf("%d", unavailable[i]);
        }
        printf("\nFinal price: $%.2f\n", finalPrice);
        printf("\nBus type: %s\n", bus);
        printf("==================================\n");
        printf("Reservation Date:       %d-%02d-%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
        printf("Expired Date:           %d-%02d-%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday + 2);
        printf("==================================\n");
        printf("\nThank for your booking. Please comme to pay for your reservation before the expired date.\nOtherwise, your reservation will be cancelled.");

        // Write the updated seats back to the file
        file = fopen(file4, "w");
        for (int i = 0; i < seats; i++) {
            fprintf(file, "%d\n", seatArray[i]);
        }
        fclose(file);
    }
    else {
      printf("\nReservation cancelled.\n");
      goto love;
    }
}

void KDmain() {
  
  int choice;
  int seat1 = 56;
  char file1[25] = "KDseat1.txt";
  char bus1[40] = "56-passenger luxury coach";
  float price1 = 14;

  int seat2 = 40;
  char file2[25] = "KDseat2.txt";
  char bus2[40] = "40-passenger standard coach";
  float price2 = 12;

  int seat3 = 16;
  char file3[25] = "KDseat3.txt";
  char bus3[40] = "16-passenger Mini-bus";
  float price3 = 11;

  int seat4 = 12;
  char file4[25] = "KDseat4.txt";
  char bus4[40] = "12-passenger Luxury Van";
  float price4 = 16;


  while (choice != 0) {
    system("cls");
    FILE *file = fopen("pp_kdmv.txt", "r");
    char buffer[255];
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("seat 1");
      seatKD(seat1, file1, price1, bus1);
      getch();
      break;
    case 2:
      printf("seat 2");
      seatKD(seat2, file2, price2, bus2);
      getch();
      break;
    case 3:
      printf("seat 3");
      seatKD(seat3, file3, price3, bus3);
      getch();
      break;
    case 4:
      printf("seat 4");
      seatKD(seat4, file4, price4, bus4);
      getch();
        break;
    case 0:
        system("cls");
        break;
    default:
        printf("Invalid choice.\n\nPlease try again.");
        break;
    }
  }
}