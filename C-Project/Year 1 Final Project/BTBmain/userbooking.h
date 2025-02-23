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
    while (1) {
        system("cls");
        printf("Pick a choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            SRmain();
            break;
        case 2:
            SVmain();
            break;
        case 3:
            KDmain();
            break;
        case 4:
            KOMmain();
            break;
        case 5:
            BTBmain();
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("\nInvalid choice. Please try again.\n");
            break;
        }
    }
}
