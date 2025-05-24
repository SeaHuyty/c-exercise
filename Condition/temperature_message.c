// Deliver a message based on temperature input: Write a program that asks the user to input the temperature (in degrees Celsius). 
// Based on the input temperature, the program displays an appropriate message about the weather.

#include <stdio.h>

int main() {
    float temperature;
    printf("Please enter the temperature in degrees Celsius: ");
    scanf("%f", &temperature);

    if (temperature >= 30) {
        printf("It's a hot day. Make sure to stay hydrated.\n");
    }
    else if (temperature >= 20) {
        printf("The weather is warm and pleasant.\n");
    }
    else if (temperature >= 10) {
        printf("It's a bit chilly. You might want to wear a jacket.\n");
    }
    else {
        printf("It's cold outside. Dress warmly.\n");
    }

    return 0;
}