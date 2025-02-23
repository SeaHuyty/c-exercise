#include <stdio.h>
#include <stdlib.h>






void seatKD(int seats, char *file4, float price) {
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

    printf("\nAvailable seats of bus 2\n");
    for (int i = 0; i < seats; i++) {
        if (i % 4 == 0 && i != 0) {
            printf("\n");
        }
        if (seatArray[i] == 0) {
            printf("    ");
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

    int unavailable[n];
    for (int i = 0; i < n; i++) {
        printf("Reserve number: ");
        scanf("%d", &unavailable[i]);
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
    file = fopen(file4, "w");
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
            printf("    ");
        } else {
            printf(" %d", seatArray[i]);
            if (i % 2 == 1) {
                printf("\t");
            }
        }
    }
    printf("\nReserved seats: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", unavailable[i]);
    }
    printf("\n");
}

void KDmain() {
  FILE *file = fopen("pp_kdmv.txt", "r");
  char buffer[255];
  while (fgets(buffer, sizeof(buffer), file)) {
    printf("%s", buffer);
  }
  
  int choice;
  int seat1 = 56;
  char file1[25] = "KDseat1.txt";
  float price1 = 14;

  int seat2 = 40;
  char file2[25] = "KDseat2.txt";
  float price2 = 12;
  int seat3 = 16;
  char file3[25] = "KDseat3.txt";
  float price3 = 11;

  int seat4 = 12;
  char file4[25] = "KDseat4.txt";
  float price4 = 16;


  while (1) {
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("seat 1");
      seatKD(seat1, file1, price1);
      break;
    case 2:
      printf("seat 2");
      seatKD(seat2, file2, price2);
      break;
    case 3:
      printf("seat 3");
      seatKD(seat3, file3, price3);
      break;
    case 4:
      printf("seat 4");
      seatKD(seat4, file4, price4);
      break;
    case 5:
      break;
    default:
    printf("Invalid choice.\n\nPlease try again.");
      break;
    }
  }
  

  fclose(file);


}