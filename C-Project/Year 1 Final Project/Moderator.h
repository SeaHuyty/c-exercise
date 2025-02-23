#include <stdio.h>
#include <stdlib.h>
#include "userInterface.h"



void search2();                             //Function for search
void search_invoice_by_date();              //Function search invoice by date
void print_invoice(char *invoice);          //Function to print invoice


void Moderator() {
    int choice;
    FILE *fptr; 
    do {
        system("cls");
        printf("==================================================\n    Moderator\n==================================================\n\n");
        printf("\t1. Booking ticket\n");
        printf("\t2. Bulk booking\n");
        printf("\t3. Policy\n");
        printf("\t4. Invoice\n\n");
        printf("\t0. Log out\n\n");
        printf("=> Select option: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character left by scanf

        switch (choice) {

            //For booking ticket
            case 1:
                system("cls");
                userbooking(); //come from userInterface.h
                break;

            //For bulk booking
            case 2:
                system("cls");
                bulk_bus(); //come from userInterface.h
                break;

            //For open policy
            case 3:
            system("cls");
                fptr = fopen("bus_policy.txt", "r"); // Open file with quotes
                if (fptr == NULL) {
                    printf("Error opening file.\n");
                } else {
                    char content[1000];
                    while (fgets(content, sizeof(content), fptr)) { // Read file content
                        printf("%s", content);
                    }
                    fclose(fptr); // Close file after reading
                }
                printf("\nPress any key to continue...");
                getchar();
                break;

            //Search invoice
            case 4:
                system("cls");
                search2();
                break;

            //Exit program
            case 0:
                system("cls");
                printf("Exiting...\n");
                break;

            default:
                system("cls");
                printf("Invalid option! Please try again.\n");
                printf("\nPress any key to continue...");
                getchar();
                break;
        }
    } while (choice != 0);
}


void search2() {
    int choice;
    int continue_search = 1;    //Assume that 1 is true


    //choice of moderator
    while (continue_search) {
        printf("\n----------------Search here--------------\n");
        printf("1. Search invoice by departure date\n");
        printf("2. Display Booking Invoice\n");
        printf("3. Display Bulk Booking Invoice\n\n");
        printf("0. Exit\n");
        printf("=> Select option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                system("cls");
                search_invoice_by_date();
                break;
            case 2:
                system("cls");
                FILE *Iloveyou = fopen("BookingInvoice.txt", "r");
                char buffer[100];
                while(fgets(buffer, sizeof(buffer), Iloveyou)) {
                    printf("%s", buffer);
                }
                getch();
                break;
            case 3:
                system("cls");
                FILE *Ihateyou = fopen("bulk_booking_invoice.txt", "r");
                char leaveme[100];
                while(fgets(leaveme, sizeof(leaveme), Ihateyou)) {
                    printf("%s", leaveme);
                }
                getch();
                break;
            case 0:
                system("cls");
                continue_search = 0;
                break;
            default:
                printf("Invalid choice, please try again.\n");
                getch();
                break;
        }
    }
}


//Function for search departure date of each invoice
void search_invoice_by_date() {
    FILE *fp = fopen("bulk_booking_invoice.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file\n");
        return;
    }

    //ask for departure date of invoice 
    int search_day, search_month, search_year;
    printf("Enter departure date to search (DD MM YYYY): ");
    scanf("%d %d %d", &search_day, &search_month, &search_year);


    //line: to store each line read from the file.
    //invoice: to accumulate the lines of an invoice.
    //invoice_len: to track the length of the accumulated invoice.
    //found_invoice: to indicate if a matching invoice has been found.

    char line[256];
    char invoice[5000] = {0};       //Initialized invoice with {0} to ensure it starts empty
    int invoice_len = 0;            //// no lines have been read
    int found_invoice = 0;

    while (fgets(line, sizeof(line), fp)) {
        if (strncmp(line, "-------------->> Invoice <<---------------", 40) == 0) {
            if (invoice_len > 0) {
                // Check the previous invoice's date
                char *date_str = strstr(invoice, "Departure date:");
                if (date_str != NULL) {
                    int day, month, year;
                    sscanf(date_str, "Departure date: %d/%d/%d", &day, &month, &year);     //The sscanf function parses the date from the date_str
                    if (day == search_day && month == search_month && year == search_year) {
                        printf("\nFound Invoice:\n");
                        print_invoice(invoice);
                        found_invoice = 1;
                    }
                }
                // Reset the invoice buffer
                invoice[0]=0;
                invoice_len = 0;
            }
        }
        // Append line to the invoice buffer
        strncat(invoice, line, sizeof(line) - 1);
        invoice_len += strlen(line);
    }

    // Check the last invoice in the file
    if (invoice_len > 0) {
        char *date_str = strstr(invoice, "Departure date:");   //searches for the substring "Departure date:" within the "invoice" buffer and returns a pointer to the first occurrence of this substring.
        if (date_str != NULL) {
            int day, month, year;
            sscanf(date_str, "Departure date: %d/%d/%d", &day, &month, &year);
            if (day == search_day && month == search_month && year == search_year) {
                printf("\nFound Invoice:\n");
                print_invoice(invoice);
                found_invoice = 1;
            }
        }
    }

    if (!found_invoice) {
        printf("No invoice found with the specified departure date.\n");
    }

    fclose(fp);
}


//Function for print invoice
void print_invoice(char *invoice) {
    printf("%s", invoice);
}



