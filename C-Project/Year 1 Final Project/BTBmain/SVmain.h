#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void seatSV(int seats, char *file2, float price)
{
    FILE *file = fopen(file2, "r");
    if (file == NULL)
    {
        printf("Can't open the file %s\n", file2);
        exit(0);
    }

    int buffer;
    int seatArray[seats];
    int index = 0;

    while (fscanf(file, "%d", &buffer) != EOF)
    {
        seatArray[index++] = buffer;
    }
    fclose(file);

    printf("\nAvailable seats of bus 2\n");
    for (int i = 0; i < seats; i++)
    {
        if (i % 4 == 0 && i != 0)
        {
            printf("\n");
        }
        if (seatArray[i] == 0)
        {
            printf("    ");
        }
        else
        {
            printf(" %d", seatArray[i]);
            if (i % 2 == 1)
            {
                printf("\t");
            }
        }
    }
    printf("\n");

    printf("Enter number of seats you want to reserve: ");
    int n;
    scanf("%d", &n);

    int unavailable[n];
    for (int i = 0; i < n; i++)
    {
        printf("Reserve number: ");
        scanf("%d", &unavailable[i]);
    }

    // Update the seatArray for reserved seats
    for (int i = 0; i < seats; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (seatArray[i] == unavailable[j])
            {
                seatArray[i] = 0;
            }
        }
    }

    // Write the updated seats back to the file
    file = fopen(file2, "w");
    for (int i = 0; i < seats; i++)
    {
        fprintf(file, "%d\n", seatArray[i]);
    }
    fclose(file);

    printf("\nUpdated available seats of bus 1\n");
    for (int i = 0; i < seats; i++)
    {
        if (i % 4 == 0 && i != 0)
        {
            printf("\n");
        }
        if (seatArray[i] == 0)
        {
            printf("    ");
        }
        else
        {
            printf(" %d", seatArray[i]);
            if (i % 2 == 1)
            {
                printf("\t");
            }
        }
    }
    printf("\nReserved seats: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", unavailable[i]);
    }
    printf("\n");
}

void SVmain()
{
    FILE *file = fopen("pp_sv.txt", "r");
    char buffer[255];
    while (fgets(buffer, sizeof(buffer), file))
    {
        printf("%s", buffer);
    }

    int choice;
    int seat1 = 56;
    char file1[25] = "SVseat1.txt";
    float price1 = 14.5;

    int seat2 = 40;
    char file2[25] = "SVseat2.txt";
    float price2 = 13;

    int seat3 = 16;
    char file3[25] = "SVseat3.txt";
    float price3 = 10;

    int seat4 = 12;
    char file4[25] = "SVseat4.txt";
    float price4 = 12;

    while (1)
    {
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("seat 1");
            seatSV(seat1, file1, price1);
            break;
        case 2:
            printf("seat 2");
            seatSV(seat2, file2, price2);
            break;
        case 3:
            printf("seat 3");
            seatSV(seat3, file3, price3);
            break;
        case 4:
            printf("seat 4");
            seatSV(seat4, file4, price4);
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