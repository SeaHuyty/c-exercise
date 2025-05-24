// Find Largest and Smallest Number in an Array: Use an array to store user input (limit 20 numbers) and find the largest and smallest number in the array.
#include <stdio.h>

int main() {
    int user_input;
    printf("Enter how many numbers you want to input: "); 
    scanf("%d", &user_input);

    if (user_input > 20) {
        printf("Limit exceeded! Please enter up to 20 numbers.\n");
        return 1;
    }

    int number[20]; 
    for (int i = 0; i < user_input; i++) {
        printf("Number %d = ", i + 1);
        scanf("%d", &number[i]);
    }

    int max = number[0];
    int min = number[0];

    for(int i = 1; i < user_input; i++) {
        if (number[i] > max) {
            max = number[i];
        }
        if (number[i] < min) {
            min = number[i];
        }
    }

    printf("Largest number: %d\n", max);
    printf("Smallest number: %d\n", min);

    return 0;
}
