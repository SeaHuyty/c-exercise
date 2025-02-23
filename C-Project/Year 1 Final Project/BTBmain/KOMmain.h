#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>





void seatKOM(int seats, char *file4, float price) {
  FILE *file = fopen(file4, "r");
  if (file == NULL) {
    printf("Can't open the file %s\n", file4);
    exit(0);
  }

  int seatArray[seats];
  char buffer[4];
  int index = 0;

  while (fgets(buffer, sizeof(buffer), file)) {
    if (buffer[0] == 'x') {
      seatArray[index++] = 0;
    } else {
      seatArray[index++] = atoi(buffer);
    }
  }
  fclose(file);

  system("cls");
  printf("\n--------------------------------------------------------------Available seats of bus----------------------------------------------------------------\n");
 

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
  printf("Reserve number: ", i);
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

    system("cls");
    printf("\nUpdated available seats of bus\n");
 

    
    
  } else {
    printf("Reservation canceled.\n");
  }
}

void KOMmain() {
  FILE *file = fopen("pp_kompot.txt", "r");
  if (file == NULL) {
    printf("Can't open the file pp_kompot.txt\n");
    exit(0);
  }

  char buffer[255];
  while (fgets(buffer, sizeof(buffer), file)) {
    printf("%s", buffer);
  }
  fclose(file);

  int choice;
  int seat1 = 56;
  char file1[25] = "KOMseat1.txt";
  float price1 = 11.5;

  int seat2 = 40;
  char file2[25] = "KOMseat2.txt";
  float price2 = 10.0;

  int seat3 = 16;
  char file3[25] = "KOMseat3.txt";
  float price3 = 7.0;

  int seat4 = 12;
  char file4[25] = "KOMseat4.txt";
  float price4 = 9.5;

  while (1) {
    printf("Enter your next car if you wanna reserve (1-4 to reserve next car , 5 to exit): ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        seatKOM(seat1, file1, price1);
        break;
      case 2:
        seatKOM(seat2, file2, price2);
        break;
      case 3:
        seatKOM(seat3, file3, price3);
        break;
      case 4:
        seatKOM(seat4, file4, price4);
        break;
      case 5:
        return;
      default:
        printf("Invalid choice.\n\nPlease try again.\n");
        break;
    }
  }
}