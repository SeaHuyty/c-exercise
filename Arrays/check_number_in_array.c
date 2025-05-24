// Check if a Number Exists in an Array: Given an array of 9 integers, write a program that tests if a user input number exists in the array.
#include <stdio.h>

int main() {
    int array[9] = {3, -3, 1, 5, 7, 0, 8, 9, 6};
    int found = 0;
    int userInput;

    printf("Please enter a number: ");
    scanf("%d", &userInput);

    for (int i = 0; i < 9; i++) {
        if (userInput == array[i]) {
            found = 1;
            break;
        }
    }

    if (found == 1) {
        printf("The number %d exists in the array!!\n", userInput);
    } else {
        printf("The number %d does not exist in the array!!\n", userInput);
    }

    return 0;
}
