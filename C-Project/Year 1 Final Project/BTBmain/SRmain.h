#include<stdio.h>
#include<stdlib.h>
#include <time.h>




void seatSR(int seats, char *file1, float price) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    FILE *file = fopen(file1, "r");
    if (file == NULL) {
        printf("Can't open the file %s\n", file1);
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
    printf("\n--------------------------------------------------------------Available seats of bus----------------------------------------------------------------\n");

    for (int i = 0; i < seats; i++) {
        if (i % 4 == 0 && i != 0) {
            printf("\n");
        }
        if (seatArray[i] == 0) {
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
        scanf("%d", &seatNum);

        // Validate seat number
        if (seatNum < 1 || seatNum > seats) {
          printf("Seat number %d is invalid. \t\t\tPlease choose a seat number between 1 and %d.\n", seatNum, seats);
          i--;
          continue;
        }

        int isReserved = 0;
        // Check for reserved seats only (not empty ones)
        for (int j = 0; j < seats; j++) {
          if (seatArray[j] == seatNum && seatArray[j] != 0) {
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
          printf("Seat %d is available.\n", seatNum); // Added message for available seat
          continue;
        } else {
          printf("Seat %d is not available.\n", seatNum);
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
    printf("\n\nFinal price: $%.2f\n", finalPrice);

    char confirm;
    printf("\n\nDo you want to confirm the reservation? (y/n): ");
    scanf(" %c", &confirm);

    if (confirm == 'y' || confirm == 'Y') {
      // Update the seatArray for reserved seats
      for (int i = 0; i < seats; i++) {
        for (int j = 0; j < n; j++) {
          if (seatArray[i] == unavailable[j]) {
            seatArray[i] = 0;

            // Add timestamp
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
      // Update the seatArray for reserved seats
      for (int i = 0; i < seats; i++) {
          for (int j = 0; j < n; j++) {
              if (seatArray[i] == unavailable[j]) {
                  seatArray[i] = 0;
              }
          }
      }

      // Write the updated seats back to the file
      file = fopen(file1, "w");
      for (int i = 0; i < seats; i++) {
          fprintf(file, "%d\n", seatArray[i]);
      }
      fclose(file);

      printf("\nUpdated available seats of bus 1\n");
      for (int i = 0; i < seats; i++) {
          if (i % 4 == 0 && i != 0) {
              printf("\n");
          }
          if (seatArray[i] == 0) {
              printf(" X ");
          } else {
              printf(" %d", seatArray[i]);
              if (i % 2 == 1) {
                  printf("\t");
              }
          }
      }
    }
    else {
      printf("\nReservation cancelled.\n");
      goto love;
    }

}

void SRmain() {
  
  int choice;
  int seat1 = 56;
  char file1[25] = "SRseat1.txt";
  float price1 = 14.5;

  int seat2 = 40;
  char file2[25] = "SRseat2.txt";
  float price2 =	12;

  int seat3 = 16;
  char file3[25] = "SRseat3.txt";
  float price3 =	9.5;

  int seat4 = 12;
  char file4[25] = "SRseat4.txt";
  float price4 =	11;

  while (1) {
    char buffer[255];
    FILE *file = fopen("pp_sr.txt", "r");
    while (fgets(buffer, sizeof(buffer), file)) {
      printf("%s", buffer);
    }
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("seat 1");
      seatSR(seat1, file1, price1);
      break;
    case 2:
      printf("seat 2");
      seatSR(seat2, file2, price2);
      break;
    case 3:
      printf("seat 3");
      seatSR(seat3, file3, price3);
      break;
    case 4:
      printf("seat 4");
      seatSR(seat4, file4, price4);
      break;
    case 5:
      break;
    default:
    printf("Invalid option\n");
      break;
    }
  }
}

