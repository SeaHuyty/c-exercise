#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char bulk_buses[][30] = {"40-passenger standard coach", "56-passenger luxury coach", "15-passenger Mini-bus", "12-passenger Van"};
    char book_decision;
    char bulk_option;
    char bulk_from[20];
    char bulk_to[20];
    system("cls");
    printf("-----------------Bulk Booking-----------------\n");
    printf(">>>> Search\n");
    printf("From: "); scanf("%s", &bulk_from);
    printf("To: "); scanf("%s", &bulk_to);
    printf("\nPlease wait while we're searching for available bus"); sleep(1); printf("."); sleep(1); printf("."); sleep(1); printf("."); sleep(1);
    do {
        system("cls");
        printf("From %s to %s\n\n", bulk_from, bulk_to);
        FILE* fptr;
        fptr = fopen("book_bulk_bus.txt", "r");
        char content[1000];
        while (fgets(content, 1000, fptr)) {
            printf("%s", content); 
        }
        printf("\n\nBook Now??\n1. Yes\n2. No\n=> Select: "); scanf("%s", &book_decision); 
        switch(book_decision) {
            case '1':
                system("cls");
                break;
            case '2':
                system("cls");
                break;
            default:
                system("cls");
                printf("Invalid Option!!\n < Press any key to go back >\n");
                break;
        }
        getch();
    } while (book_decision != '2');



    return 0;
}
