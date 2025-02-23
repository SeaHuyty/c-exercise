#include <stdio.h>
#include <stdlib.h>
#include "SRmain.h"
#include "SVmain.h"
#include "KDmain.h"
#include "KOMmain.h"
#include "BTBmain.h"

void SRmain();
void SVmain();
void KDmain();
void KOMmain();
void BTBmain();

void userbooking() {
    int choice;
    while (choice != 0) {
        system("cls");
        FILE *Mine = fopen("routes.txt", "r");
        char allMine[200];
        while(fgets(allMine, sizeof(allMine), Mine)) {
            printf("%s", allMine);
        }
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            system("cls");
            SVmain();
            break;
        case 2:
            system("cls");
            SRmain();
            break;
        case 3:
            system("cls");
            KOMmain();
            break;
        case 4:
            system("cls");
            BTBmain();
            break;
        case 5:
            system("cls");
            KDmain();
            break;
        case 0:
            system("cls");
            break;
        default:
            printf("\nInvalid choice. Please try again.\n");
            break;
        }
    }
}