// Find Customer with the Most Money Across Banks: Write a C program that reads the number of customers and the number of banks each customer has accounts with. Then, input each customer's balance in each bank. The program should determine which customer has the highest total balance across all their banks and print the customer's index (1-based). Validate user inputs for logical constraints (e.g., no negative balances, limits on number of customers and banks). Use functions to organize the logic, including a function to find the customer with the most money.

#include <stdio.h>
#include <unistd.h>

// Function prototype: returns index of customer with the most total money
int whoHasTheMostMoney(int balance[][50], int numberOfCustomer, int numberOfBank[]);
// Void function to pause execution briefly with dots
void sleeping();

int main() {
    // Max 100 customers, each with up to 50 banks
    int numberOfCustomer;
    int numberOfBank[100];
    int balance[100][50];
    int i = 1;

    // Input validation for number of customers
    while (i != 0) {
        printf("Enter the number of customers: ");
        scanf("%d", &numberOfCustomer);
        if (numberOfCustomer <= 0) {
            printf("Number of customers can't be zero or less than zero\n");
            sleeping();
        }
        else if (numberOfCustomer == 1) {
            printf("Cannot compare with only one customer.\nThat single customer has the most money by default.\n");
            sleeping();
        }
        else if (numberOfCustomer > 100) {
            printf("Can't input more than 100 customers!!\nPlease try again\n");
            sleeping();
        }
        else {
            i = 0; // valid input, break loop
        }
    }

    // Input for each customer's banks and their balances
    for (int i = 0; i < numberOfCustomer; i++) {
        numberBank:
        printf("\nEnter number of banks that customer [%d] has: ", i + 1);
        scanf("%d", &numberOfBank[i]);

        if (numberOfBank[i] <= 0) {
            printf("Number of banks can't be zero or less.\nPlease try again.\n");
            sleeping();
            goto numberBank;
        }
        else if (numberOfBank[i] > 50) {
            printf("Number of banks can't be more than 50.\nPlease try again.\n");
            sleeping();
            goto numberBank;
        }

        for (int j = 0; j < numberOfBank[i]; j++) {
            balanceAgain:
            printf("Enter the money customer [%d] has in bank [%d]: ", i + 1, j + 1);
            scanf("%d", &balance[i][j]);

            if (balance[i][j] < 0) {
                printf("Money in bank cannot be less than zero (no debt allowed here).\nPlease try again.\n");
                sleeping();
                goto balanceAgain;
            }
        }
    }

    int mostMoneyIndex = whoHasTheMostMoney(balance, numberOfCustomer, numberOfBank);
    printf("\nCustomer with the most money is customer[%d].\n", mostMoneyIndex + 1);

    return 0;
}

int whoHasTheMostMoney(int balance[][50], int numberOfCustomer, int numberOfBank[]) {
    int mostMoney = -1;
    int mostMoneyIndex = -1;

    for (int i = 0; i < numberOfCustomer; i++) {
        int total = 0;
        for (int j = 0; j < numberOfBank[i]; j++) {
            total += balance[i][j];
        }
        if (total > mostMoney) {
            mostMoney = total;
            mostMoneyIndex = i;
        }
    }
    return mostMoneyIndex;
}

void sleeping() {
    for (int r = 0; r < 3; r++) {
        sleep(1);
        printf(".");
        fflush(stdout);  // Ensure dot is printed immediately
    }
    printf("\n\n");
}
