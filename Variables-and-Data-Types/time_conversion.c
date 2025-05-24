// Time Conversion (hh:mm:ss to seconds): Create a C program that acts as a time converter. 
// It should convert time entered in the format hours:minutes:seconds (hh:mm:ss) to its equivalent total number of seconds.
#include <stdio.h>

int main() {
    int hour;
    int minute;
    int second;
    printf("Enter hour: ");
    scanf("%d", &hour);
    printf("Enter minute: ");
    scanf("%d", &minute);
    printf("Enter second: ");
    scanf("%d", &second);
    printf("It is: %d seconds\n", hour * 3600 + minute * 60 + second);
    return 0;
}
