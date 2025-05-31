// User Input and Output: User input and print it out.
#include <stdio.h>
int main() {
    int num;
    char name[50];

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your age: ");
    scanf("%d", &num);

    printf("So your name is %s and you're %d years old.", name, num);
    
    return 0;
}