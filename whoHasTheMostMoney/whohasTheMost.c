#include <stdio.h>
#include <unistd.h>

// This is function prototype.
int whoHasTheMostMoney(int balance[][50], int numberOfCustomer, int numberOfBank[]);
// Here it's void function because we want it to perform an action not return a value.
void sleeping();

int main(){
    // Here we only allow for a hundred customer and each customer can only have 50 banks.
    // Since we don't set the the size or customer, there will be error when user input the number of customer more than 100.
    // The reason is because we set the size for balance to store only 100.
    // So we'll limit the number of customer.
    int numberOfCustomer;
    // Moreover, number of bank can't be over 50. However, we can also change the size.
    int numberOfBank[50];
    int balance[100][50];
    int i = 1;
    while (i != 0) {
        printf("Enter the number of customer : "); scanf("%d", &numberOfCustomer);
        if (numberOfCustomer <= 0) {
            printf("Number of customer can't be zero or less than zero");
            // Allow time for user to read.
            sleeping();
        }
        else if (numberOfCustomer == 1) {
            // We can't compare when there's only one customer.
            printf("We can't compare with one customer.\nThat customer has the most money compare to no one");
            sleeping();
        }
        else if (numberOfCustomer > 100) {
            // Here we handle the error when user input size more than array.
            printf("Can't input more than 100 customer!!\n\nPlease try again");
            sleeping();
        }
        else {
            // (i = 0) to terminate the while loop because its condition (i != 0)
            i = 0;
        }
    }
    for (int i = 0; i < numberOfCustomer; i++) {
        numberBank:
        printf("\nEnter number of bank that customer [%d] have: ", i+1); scanf("%d", &numberOfBank[i]);
        if (numberOfBank[i] <= 0) {
            printf("Number of bank can't be less than zero or equal to zero!!\n\nPlease try again");
            sleeping();
            // We use goto to let user enter again. Easier than loop.
            goto numberBank;
        }
        else if (numberOfBank[i] > 50) {
            // We handle the error of 'numberOfBank' size when user input more than 50.
            printf("Number of bank can't be over 50\n\nPlease try again");
            sleeping();
            goto numberBank;
        }
        // The loop down here collect the value of each customer's balance.
        for (int j = 0; j < numberOfBank[i]; j++) {
            balanceAgain:
            printf("Enter the money of customer [%d] have in bank [%d]: ", i+1, j+1 ); scanf("%d", &balance[i][j]);
            // Here we use logic, not allowing the user to input the balance value less than zero.
            // even if the user enter value less than zero, this code would still work, but it's just illogical.
            if (balance[i][j] < 0) {
                printf("\nMoney in bank could not be less than zero. That's mean you're in debt, so you don't own the money or have the money.\n");
                printf("Please try again");
                sleeping();
            }
        }
    }
    int mostMoneyIndex = whoHasTheMostMoney(balance, numberOfCustomer, numberOfBank);
    printf("\nCustomer that has the most money is customer[%d].\n", (mostMoneyIndex + 1));
    return 0;
}

// This is function definition.
// The function is int because we return the integer value.
int whoHasTheMostMoney(int balance[][50], int numberOfCustomer, int numberOfBank[]) {
    // We declare (mostMoney = -1) because when user input 0 for every customer, total would still bigger than mostMoney,
    // and it would return the first customer is the one who has the most money.
    int mostMoney = -1;
    int total = 0;
    int mostMoneyIndex;

    for (int i = 0; i < numberOfCustomer; i++) {
        // Here we set total = 0 again to reset the value of total from the one in the previous i.
        total = 0;
        for (int j = 0; j < numberOfBank[i]; j++) {
            // We calculate the value of total.
            total += balance[i][j];
        }
        // When the loop ends we check if total bigger than mostMoney or not.
        // If it bigger than mostMoney, we'll transfer the value from total to mostMoney.
        // The reason why we use (>) and not (>=) is because we want to return the first customer index when the 2 customer have the same amount of money.
        if (total > mostMoney) {
            mostMoney = total;
            // So here if total bigger than mostMoney, we set something to store the number of its place in the array.
            mostMoneyIndex = i;
        }    
    }
    // Here we return the value of 'mostMoneyIndex'.
    return mostMoneyIndex;
}

void sleeping() {
    for (int r = 0; r < 3; r++) {
        sleep(1);
        printf(".");
    }
    printf("\n\n");
}