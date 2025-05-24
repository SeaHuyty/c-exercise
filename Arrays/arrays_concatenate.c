// Concatenate Strings: Combine "firstname" and "lastname" with a space in between, then print the full name.
#include <stdio.h>
#include <string.h>  // For strcat

int main() {
    char firstname[20] = "Laruen";  // Increased size to hold full name + space
    char lastname[10] = "Wang";

    strcat(firstname, " ");        // Add space after firstname
    strcat(firstname, lastname);  // Append lastname to firstname

    printf("%s\n", firstname);    // Print full name

    return 0;
}