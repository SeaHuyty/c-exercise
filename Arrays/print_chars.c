// Print Each Character of a String: Print each character of the string "CADT" one by one.

#include <stdio.h>

int main() {
    // Initialize the string
    char string[] = "CADT";

    // Loop through each character and print it
    for (int i = 0; i <= 3; i++) {
        printf("%c ", string[i]);
    }
    printf("\n");

    return 0;
}