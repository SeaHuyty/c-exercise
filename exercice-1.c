#include <stdio.h>

int main()
{
    // TODO
    //  Input the number, the range min and the range max 
    //  Output "inside" if the number is in the range [min, max], "outside" otherwise
    int number;
    int min_val = 5;
    int max_val = 15;
    print("Input a number: ");
    scanf("%d", &number);
    
    if (number >= min_val && number <= max_val) {
        printf("inside\n");
    } else {
        printf("outside\n");
    }

    return 0;
}
