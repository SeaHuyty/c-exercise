// Kids With the Greatest Number of Candies:
// Given an array candies representing candies each kid has, and extraCandies,
// determine for each kid if giving all extraCandies makes them have the greatest number.

#include <stdio.h>

int main() {
    int candies[100];
    int nKids, extraCandies;
    int greatestKid, flag;

    // Input validation for number of kids
    do {
        printf("How many kids have candies? ");
        scanf("%d", &nKids);
        if (nKids <= 0) {
            printf("The number of kids should be bigger than zero.\n");
        }
    } while (nKids <= 0);

    // Input candies per kid, with validation
    for (int i = 0; i < nKids; i++) {
        candy_input:
        printf("Enter the amount of candy that kid [%d] has: ", i + 1);
        scanf("%d", &candies[i]);
        if (candies[i] > 100) {
            printf("Please enter the amount of candy less than or equal to 100.\n");
            goto candy_input;
        }
    }

    // Input extra candies
    printf("Please enter the amount of extra candy: ");
    scanf("%d", &extraCandies);

    // Display the candies array
    printf("Overall candy = [");
    for (int i = 0; i < nKids; i++) {
        if (i == nKids - 1)
            printf("%d]", candies[i]);
        else
            printf("%d, ", candies[i]);
    }
    printf("\nThe amount of extra candy is: %d\n", extraCandies);

    // Calculate and display boolean results
    printf("Boolean result = [");
    for (int i = 0; i < nKids; i++) {
        flag = 0;
        greatestKid = candies[i] + extraCandies;
        for (int j = 0; j < nKids; j++) {
            if (greatestKid < candies[j]) {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            printf("False");
        else
            printf("True");

        if (i != nKids - 1)
            printf(", ");
    }
    printf("]\n");

    return 0;
}
