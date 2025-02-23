// Bus Reservation System: a system on terminal for user to book a bus physically.
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "userBooking.h"

// These are function prototypes
void bulk_nobus();              // Function for option No Bus available for 'bulk booking'
void bulk_bus();                // Function for option Bus available for 'Bulk Booking'
void bulk_booking();            // Function for option 'Bulk booking'
void review();                  // Function for option 'review'
void sleeping();                // Function for pause simulation.
void bulk_book();               // Function for 'bulk_book'
void invalid_option();          // Function to hanlde invalid option
void bulk_file();               // Function for bulk_file
void content_files();           // Function to display content files
void bulk_invoice();            // Function to generate invoice for bulking
int departureDate();            // Function to handle validation in bulk booking

char bulkbus_booking;
int k, l, j;

void user_interface() {
    // Main function for managing bus reservation system options
    char selected;
    do {
        j = 0;  // Index corresponding to the content files (e.g., menu options)
        content_files(j);   // Display available menu options

        scanf("%s", &selected); // Get user input for the selected option

        switch(selected) {
            case '0':
                // Clear the terminal screen and exit
                system("cls");
                break;
            case '1':
                system("cls");
                userbooking();  //function for userbooking
                break;
            case '2':
                // Proceed with bulk bus booking
                system("cls");
                bulk_bus();
                break;
            case '3':
                j = 3;  // Index corresponding to bus_whyus option
                content_files(j);
                getch();
                break;
            case '4':
                j = 4;  // Index corresponding to bus_policy option
                content_files(j);
                getch();
                break;
            case '5':
                system("cls");
                review();   // Proceed with reviewing function
                break;
            case '6':
                system("cls");  // Clear the screen
                break;
            default:
                invalid_option();   // Handle invalid input
                break;
        }
    } while (selected != '0');  // Repeat until user chooses to exit
}

void content_files(int j) {

    // Array of file names
    char main_contents[6][30] = {"main_content.txt", "Nothing", "bulkbus_available.txt", "bus_whyus.txt", "bus_policy.txt", "bus_review.txt"};

    system("cls");
    FILE* fptr;

    // Open the specified file for reading
    fptr = fopen(main_contents[j], "r");
    char content[1000];

    // Read and print each line from the file
    while (fgets(content, 1000, fptr)) {
        printf("%s", content); 
    }

}

void bulk_bus() {
    // Manages bulk bus booking options.
    char bulk_options;
    do {
        j = 2;  // Index corresponding to "bulkbus_available.txt" in the file array
        content_files(j);   // Display available bulk bus options
        scanf("%s", &bulk_options); // Get user input for the selected option
        fflush(stdin);
        switch(bulk_options) {
            case '0':
                system("cls");  // Clear the terminal screen and exit
                break;
            case '1':
                do {
                    k = 1;  // Index corresponding to the first bus type
                    bulk_file(k);   // Display details of the selected bus type
                    bulk_book(k);   // Proceed with booking for the selected bus type
                } while (bulkbus_booking != '0');   // Repeat until user cancels booking
                break;
            // Similar cases for other bus types (2, 3, 4, 5)
            case '2':
                do {
                    k = 2;
                    bulk_file(k);
                    bulk_book(k);
                } while (bulkbus_booking != '0');
                break;
            case '3':
                do {
                    k = 3;
                    bulk_file(k);
                    bulk_book(k);
                } while (bulkbus_booking != '0');
                break;
            case '4':
                do {
                    k = 4;
                    bulk_file(k);
                    bulk_book(k);
                } while (bulkbus_booking != '0');
                break;
            case '5':
                do {
                    k = 5;
                    bulk_file(k);
                    bulk_book(k);
                } while (bulkbus_booking != '0');
                break;
            default:
                invalid_option();   // Handle invalid input
                break;
        }
    } while (bulk_options != '0');  // Repeat until user chooses to exit
}

void bulk_file(int k) {

    // Array of file names
    char bulk_route_file[10][30] = {"Nothing", "bulk_pp_sv.txt", "bulk_pp_sr.txt", "bulk_pp_kompot.txt", "bulk_pp_btb.txt", "bulk_pp_kdmv.txt"};
    system("cls");

    // Open the specified file for reading
    FILE* fptr;
    fptr = fopen(bulk_route_file[k], "r");
    char content[1000];

    // Read and print each line from the file
    while (fgets(content, 1000, fptr)) {
        printf("%s", content); 
    }

}

void bulk_book(int k) {
    // Manages bulk bus booking based on user input
    scanf("%c", &bulkbus_booking);  // Get user input for booking option
    switch (bulkbus_booking) {
        case '0':
            system("cls");  // Clear the terminal screen and exit
            break;
        case '1':
            system("cls");
            l = 1;  // Index representing the first booking option
            bulk_booking(k, l); // Proceed with booking for the selected bus type
            getch();  // Wait for user input
            break;
            // Similar cases for other booking options (2, 3, 4)
        case '2':
            system("cls");
            l = 2;
            bulk_booking(k, l);
            getch();
            break;
        case '3':
            system("cls");
            l = 3;
            bulk_booking(k, l);
            getch();
            break;
        case '4':
            system("cls");
            l = 4;
            bulk_booking(k, l);
            getch();
            break;
        default:
            invalid_option();   // Handle invalid input
            break;
    }
}

void bulk_booking(int k , int l ) {
    int u;  // User identifier
    int s=0;  // Service identifier
    char journey_type;
    select_type:
    printf("\033[0;36m>>>>>>> Journey type\n\n\033[0m    1. Round-trip\n    2. One way\n\n    0. Exit\n\n=> Select: ");
    scanf("%s", &journey_type); // Get user input for journey type
    fflush(stdin);
    if (journey_type == '1') {
        u = 0;  // Set user identifier for round-trip
        s = 15; // Set service identifier for round-trip
        bulk_invoice(s, u); // Proceed with bulk invoice for round-trip
    }
    else if (journey_type == '2') {
        u = 1;  // Set user identifier for one-way
        s = 0;  // Set service identifier for one-way
        bulk_invoice(s, u); // Proceed with bulk invoice for one-way
    }
    else if (journey_type == '0') {
        system("cls");  // Clear the terminal screen and exit
    }
    else {
        invalid_option();   // Handle invalid input
        goto select_type;   // Repeat input prompt
    }
}

void bulk_invoice(int s, int u) {
    // Generates bulk booking invoices for bus services

    // Prices for different bus types (index 0 is unused)
    int car_price[10][5] = {
        {0, 0, 0, 0, 0}, 
        {0, 160, 120, 90, 55}, 
        {0, 130, 120, 90, 65}, 
        {0, 140, 120, 90, 55}, 
        {0, 120, 90, 140, 50}, 
        {0, 140, 50, 80, 100}
    };

    // Bus names and routes
    char bulk_buses[5][30] = {"Nothing", "56-passenger luxury coach", "40-passenger standard coach", "16-passenger Mini-bus", "12-passenger Van"};
    char bulk_routes[6][50] = {"Nothing", "Sihanouk Ville", "Siem Reap", "Kompot", "Battambang", "MondulKiri"};

    char name_invoice[20];
    char phone_number_invoice[10];
    int depart_day = 0, depart_month = 0, car_actual_price, depart_year = 0, car_amount = 1, service = 5;
    float payment;
    char tripType[2][20] = {"Round-Trip", "One-way"};

    // Get current date and time
    time_t t = time(NULL);
    struct tm date = *localtime(&t);

    // Clear the terminal screen
    system("cls");

    // Open the invoice file in append mode
    FILE *fp = fopen("bulk_booking_invoice.txt", "a");
    printf("Name: ");
    fgets(name_invoice, sizeof(name_invoice), stdin);   // Get user's name
    int correct = 0;
    while (correct != 1) {
        printf("Departure date:\n");    // Get departure date
        printf("Day No: ");
        scanf("%d", &depart_day);
        printf("Month No: ");
        scanf("%d", &depart_month);
        printf("Year: ");
        scanf("%d", &depart_year);

        // Validate the departure date
        if (depart_year == date.tm_year + 1900 && depart_day > 0) {
            if (depart_month == date.tm_mon + 1) {
                // If the month is the current month, ensure the day is not in the past
                if (depart_day >= date.tm_mday) {
                    correct = departureDate(depart_month, depart_year, depart_day);
                }
                else {
                    correct = 0;  // Invalid day
                }
            }
            else if (depart_month > date.tm_mon + 1 && depart_month <= 12) {
                // For future months in the same year, validate the day
                correct = departureDate(depart_month, depart_year, depart_day);
            }
            else  {
                correct = 0;  // Invalid month
            }
        }
        else if (depart_day > 0 && depart_day <= 31 && depart_month <= 12 && depart_month >= 1 && depart_year > (date.tm_year + 1900) && depart_year <= (date.tm_year + 1900 + 1)) {
            // For dates in the next year, validate the day
            correct = departureDate(depart_month, depart_year, depart_day);
        }
        else {
            correct = 0;
        }
        if (correct == 0) {
            // Checks if the correct flag is set to 0, indicating an invalid date
            printf("\033[0;31mInvalid Date\n\033[0m");    // Displays an error message in red color
            printf("Press any key to continue...");
            getch();    // Wait for user to press any key
            system("cls");
        }
    }
    printf("Amount of car: ");
    scanf("%d", &car_amount);   // Get number of car
    fflush(stdin);

    // Calculate the actual car price after subtracting any discounts (e.g., service fee)
    car_actual_price = car_price[k][l];
    car_actual_price -= s;

    // Calculate the total payment including car rental and service fee
    payment = ((car_actual_price*car_amount) + service);

    system("cls");  // Clear the terminal screen

    // Print a loading message while generating the invoice
    printf("\033[0;34mPlease wait while we're generating your invoice\033[0m");
    sleeping();  // Simulate waiting time
    system("cls");  // Clear the screen again
    
    // Write the invoice details to the file
    fprintf(fp, "\n-------------->> Invoice <<---------------\nName: %s\nDeparture date:                 %02d/%02d/%d\n", name_invoice, depart_day, depart_month, depart_year);
    fprintf(fp, "\nVehicle Type: %s\nJourney Type: %s\n\n", bulk_buses[l], tripType[u]);
    fprintf(fp, "Boarding: Phnom Penh\nDrop off: %s\n\n", bulk_routes[k]);
    fprintf(fp, "Car rental price:                     %d$\nAmount of car:                        %d\nService:                              %d$\n------------------------------------------\nTotal price:                      %.2f$\n\n", car_actual_price, car_amount, service, payment);
    fprintf(fp,"Reservation date:               %02d-%02d-%d\nReservation Expiration date:    %02d-%02d-%d\n==========================================\n", date.tm_mday, date.tm_mon + 1, date.tm_year + 1900, date.tm_mday + 2, date.tm_mon + 1, date.tm_year + 1900);
    fclose(fp); // Close the file

    // Print the invoice details to the console
    printf("\t\t\t\t-------------->> Invoice <<---------------\n\t\t\t\tName: %s\n\t\t\t\tDeparture date:                 %02d/%02d/%d\n", name_invoice, depart_day, depart_month, depart_year);
    printf("\n\t\t\t\tVehicle Type: %s\n\t\t\t\tJourney Type: %s\n\n", bulk_buses[l], tripType[u]);
    printf("\t\t\t\tBoarding: Phnom Penh\n\t\t\t\tDrop off: %s\n\n", bulk_routes[k]);
    printf("\t\t\t\tCar rental price:                     %d$\n\t\t\t\tAmount of car:                        %d\n\t\t\t\tService:                              %d$\n\t\t\t\t------------------------------------------\n\t\t\t\tTotal price:                      %.2f$\n\n", car_actual_price, car_amount, service, payment);
    printf("\t\t\t\tReservation date:               %02d-%02d-%d\n\t\t\t\tReservation Expiration date:    %02d-%02d-%d\n\t\t\t\t==========================================\n", date.tm_mday, date.tm_mon + 1, date.tm_year + 1900, date.tm_mday + 2, date.tm_mon + 1, date.tm_year + 1900);
    
    // Display a message for the user
    printf("\033[0;33m\nThanks for your booking. Please come to pay for your reservation in 2days and/or 24-hours before departure time.\n\033[0m\033[0;35mOtherwise, Your reservation will be cancelled.\n\033[0m\n\t\t\t\t< Press any key to go back >\n");
}

int departureDate(int depart_month, int depart_year, int depart_day) {
    int month_days;     // Number of days in the specified month
    int correct02;      // Flag to indicate whether the date is correct (1) or not (0)

    // Check for February
    if (depart_month == 2) {
        // Leap year calculation
        if (depart_year % 4 == 0 && depart_year % 100 != 0 || depart_year % 400 == 0) {
            month_days = 29;
            // Validate the day against the month's maximum days
            if (depart_day > month_days) {
                return correct02 = 0;    // Invalid date
            }
            else {
                return correct02 = 1;   // Valid date
            }
        }
        else {
            month_days = 28;
            // Validate the day against the month's maximum days
            if (depart_day > month_days) {
                return correct02 = 0;
            }
            else {
                return correct02 = 1;
            }
        }
    } 
    // Check for months with 30 days
    else if (depart_month == 4 || depart_month == 6 || depart_month == 9 || depart_month == 11) {
        month_days = 30;
        // Validate the day against the month's maximum days
        if (depart_day > month_days) {
            return correct02 = 0;
        }
        else {
            return correct02 = 1;
        }
    }
    // All other months have 31 days
    else {
        month_days = 31;
        if (depart_day > month_days) {
            return correct02 = 0;
        }
        else {
            return correct02 = 1;
        }
    }
}

void review() {
    // Collects user reviews and ratings for a bus service.
    char name[20], user_review[1500], decision;
    int heart;
    j = 5;  // Index corresponding to "bus_review.txt" in the file array
    content_files(j);   // Display existing reviews
    do {
        printf("\n\nReview us?\n1. Yes\n2. No\n=> Select: ");
        scanf("%s", &decision);    // Get user input (1 or 2)
        fflush(stdin);
        switch (decision) {
            case '1':
                system("cls");
                FILE *fp = fopen("bus_review.txt", "a");    // Open the review file in append mode

                // Get user's name
                printf("Enter your name: ");
                gets(name);
                fflush(stdin);

                // Get user's review
                printf("Write your review: ");
                gets(user_review);
                fflush(stdin);

                // Get user's rating
                printf("Rate us from 1-5: ");
                scanf("%d", &heart);
                fflush(stdin);
                if (heart > 5) {
                    heart = 5;    // Cap the rating at 5
                }
                printf("\033[0;34mPlease wait\033[0m");

                // Simulate waiting time
                sleeping();

                // Display a message for user in yellow color.
                printf("\n\n\033[0;33mReview Uploaded!!\n\033[0m");
                fprintf(fp,"\n\nRate: ");

                // Print stars corresponding to the rating
                for (int i = 1; i <= heart; i++) {
                    fprintf(fp,"* ");
                }

                // Record the review with timestamp
                time_t t = time(NULL);
                struct tm date = *localtime(&t);
                fprintf(fp,"\n%s    %02d-%02d-%d    %02d:%02d\n\"%s\"", name, date.tm_mday, date.tm_mon + 1, date.tm_year + 1900, date.tm_hour, date.tm_min, user_review);
                fclose(fp);     // Close the file
                getch();
                break;
            case '2':
                system("cls");   // Clear the screen and exit
                break;
            default:
                invalid_option();    // Handle invalid input
                break;
        }
    } while (decision != '2');    // Repeat until user chooses to exit
}
void sleeping() {
    // Simulate a brief pause by printing three dots with a one-second delay between each dot
    for (int k = 0; k < 3; k++) {
        sleep(1);   // Sleep for 1 second
        printf(".");  // Print a dot
    }
}
void invalid_option() {
    // Handle Invalid Option
    system("cls");  // Clear the terminal screen
    printf("\033[0;31mInvalid Option!!\n\033[0m\n< Press any key to go back >\n"); // Display an error message in red color
    getch();  // Wait for user input
}
