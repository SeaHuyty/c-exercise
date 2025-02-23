#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int main() {
    // Exercise: Write a C function that takes two arrays of integers and their size, then returns a new array where each
    //           element is the sum of the corresponding elements from the input arrays.
    char filename[30];
    printf("Input file: "); scanf("%s", &filename);
    char fileno[5][30] = {"hello.txt", "hi.txt", "love.txt", "like.txt"};
    char content[1000];
    if (filename == NULL) {
        printf("File not found");
        exit(8);
    }
    else {
        FILE *fptr;
        fptr = fopen(filename, "r");
        while (fgets(content, 1000, fptr) != NULL) {
            printf("%s", content);
        }
    }
    return 0;
}