// Quadratic Equation Roots: Ask the user to enter constants a, b, and c, then calculate and print the roots of ax^2 + bx + c = 0.
#include <stdio.h>
#include <math.h>  // Required for sqrt()

int main() {
    int first_real_number;
    int second_real_number;
    int third_real_number;
    int delta;
    float x1;
    float x2;

    // Get constants from the user
    printf("Enter the value of each constant of (ax^2 + bx + c = 0)\n");
    printf("Value of a = ");
    scanf("%d", &first_real_number);
    printf("Value of b = ");
    scanf("%d", &second_real_number);
    printf("Value of c = ");
    scanf("%d", &third_real_number);

    // Calculate the value of delta (discriminant)
    delta = (second_real_number * second_real_number) - (4 * first_real_number * third_real_number);

    if (delta > 0) {
        // Two distinct roots
        printf("Delta > 0\n");
        printf("There are two roots:\n");

        float square_root_of_delta = sqrt(delta);

        x1 = (-second_real_number + square_root_of_delta) / (2 * first_real_number);
        x2 = (-second_real_number - square_root_of_delta) / (2 * first_real_number);

        printf("x1 = %1.2f\n", x1);
        printf("x2 = %1.2f\n", x2);
    } else if (delta == 0) {
        // One real root (double root)
        printf("Delta = 0\n");
        
        x1 = x2 = (-second_real_number / (float)(2 * first_real_number));

        printf("So x1 = x2 = %f\n", x1);
    } else {
        // No real roots
        printf("It has no real root!!\n");
    }

    return 0;
}
