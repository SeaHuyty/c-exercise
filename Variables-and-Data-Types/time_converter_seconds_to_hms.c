// Time Conversion (seconds to hh:mm:ss): Create a C program that converts a given number 
// of seconds into a human-readable format of hours:minutes:seconds (hh:mm:ss).
#include <stdio.h>

int main() {
    int sec;
    printf("Enter second: ");
    scanf("%d", &sec);

    printf("It is %d hour ", sec / 3600);
    printf("%d min ", (sec % 3600) / 60);
    printf("%d second", sec % 60);

    return 0;
}
