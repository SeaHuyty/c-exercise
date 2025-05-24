// Exercise: Write a C function that takes two arrays of integers and their size, then returns a new array where each
//           element is the sum of the corresponding elements from the input arrays.

#include <stdio.h>

int main() {
    int array_01[10];
    int array_02[10];
    int sum[10];
    int subtract[10];
    int element_array01, element_array02;

    printf("Number of element in array_01: ");
    scanf("%d", &element_array01);
    if (element_array01 > 10) {
        printf("Can't input more than 10 elements in the array!!\n");
        return 0;
    }

    printf("Number of element in array_02: ");
    scanf("%d", &element_array02);
    if (element_array02 > 10) {
        printf("Can't input more than 10 elements in the array!!\n");
        return 0;
    } 
    else if (element_array01 != element_array02) {
        printf("Number of elements in the two arrays are not equal\n");
        return 0;
    }

    printf("\n");
    for (int j = 0; j < element_array01; j++) {
        printf("Enter element[%d] in array_01: ", j + 1);
        scanf("%d", &array_01[j]);
    }

    printf("\n");
    for (int j = 0; j < element_array02; j++) {
        printf("Enter element[%d] in array_02: ", j + 1);
        scanf("%d", &array_02[j]);
    }

    for (int i = 0; i < element_array01; i++) {
        sum[i] = array_01[i] + array_02[i];
        subtract[i] = array_01[i] - array_02[i];
    }

    printf("\nThe sum of the two arrays: {");
    for (int i = 0; i < element_array01; i++) {
        printf("%d, ", sum[i]);
    }
    printf("\b\b}\n");

    printf("Subtraction of the two arrays: {");
    for (int i = 0; i < element_array01; i++) {
        printf("%d, ", subtract[i]);
    }
    printf("\b\b}\n");

    return 0;
}
