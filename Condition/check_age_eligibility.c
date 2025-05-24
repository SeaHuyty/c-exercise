// Check Age for Eligibility: Determine if a person is eligible to vote based on age.
#include <stdio.h>

int main() {
    int age;
    printf("In any country on earth, you're allowed to vote in the election only when you're above 18 years old.\n");
    printf("Please enter your age: ");
    scanf("%d", &age);

    if (age < 0) {
        printf("Please enter a valid age.");
    }
    else if (age >= 18) {
        printf("You're eligible to vote in the election!!");
    }
    else {
        printf("You're not eligible to vote in the election!!");
    }

    return 0;
}
