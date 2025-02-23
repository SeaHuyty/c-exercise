#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <conio.h>
#include <string.h>

int a = 15;

int main() {

    // This is a comment code (//)
    // We can use it to debug a block of error code.
    // We use a forward slash (\) infront of a double quote (") to make sure that we intend to put the double quote.
        printf("\"I have no enemies\"");


    // These are variables which is being used to store value.
        char c='a';
        short s= 20;
        int i=200;
        long l= 2000;
        float f=3.45;
        double d= 3.45259;
        printf("char: %c\n", c); // %c for char.
        printf("short: %hd\n", s); // %hd might be for short integer.
        printf("int: %d\n", i); // %d for integer, also %i.
        printf("long: %ld\n", l); // %ld for long integer maybe :Vv.
        printf("float: %f\n", f); // %f for float.
        printf("double: %lf\n", d); // %lf for long float number.


    // Arithmetic operators:
        int a = 20, b = 30;
        printf("We have a = 20 and b = 30\n");
        printf("The result of a + b is: %d\n", a+b); // Sum Operator
        printf("The result of a - b is: %d\n", a-b); // Minus Operator
        printf("The result of a * b is: %d\n", a*b); // Multiply Operator
        printf("The value of a / b is: %d\n", a / b); // Divide Operator
        printf("The value of a %% b is: %d\n", a % b); // It shows Somnorl after the dividing


    // Logical Operators:
        printf("The value of this logical AND operator ((a == b) && (a < b)) is: %d\n", (a == b) && (a < b)); // AND Operator(&&)
        printf("The value of this logical OR operator ((a == b) || (a < b)) is: %d\n", (a == b) || (a < b)); // OR Operator(||)
        printf("The value of this logical NOT operator (!(a == b)) is: %d\n", !(a == b)); // NOT Operator(!)


    // Comparison Operators:
        printf("The value of a == b is: %d\n", a == b); // Equal Operator(==)
        printf("The value of a != b is: %d\n", a != b); // Not Equal Operator(!=)
        printf("The value of a >= b is: %d\n", a >= b); // Bigger-or-equal Operator(>=)
        printf("The value of a <= b is: %d\n", a <= b); // Smaller-or-equal Operator(<=)
        printf("The value of a > b is: %d\n", a > b); // Bigger Operator(>)
        printf("The value of a < b is: %d\n", a < b); // Smaller Operator(<)


    // Increment/Decrement Operators:
        printf("The value of a++ is %d\n", a++); // Pre-increment
        printf("The value of a-- is %d\n", a--); // Pre-decrement
        printf("The value of ++a is %d\n", ++a); // Post-increment
        printf("The value of --a is %d\n", --a); // Post-decrement


    // The different output of this program. let say it is a code or an operator, I don't know but let just call it a code or an operator.
        printf("/%f/\n", 1234.56); 
        //This operator give the full float number.
        printf("/%e/\n", 1234.56); 
        //This operator use lowercase "e" to denote exponents because the longhand version is difficult to display.
        printf("/%4.f/\n", 1234.56); 
        //This operator is used to collect only integer number and increase the number after the period so 1234.56 to 1235 because it increase 0.56 to 1. And the 4 means 4 positions wide.
        printf("/%3.1f/\n", 1234.56); 
        //This operator is used to converts a value of type float (or double) to a decimal positions with k digits after the period.
        printf("/%-10.3f/\n", 1234.56); 
        //This operator is used to output statistics when you want everything to be nicely aligned. -10 positions wide and 3 digits after the period.
        printf("/%10.3f/\n", 1234.56); 
        //This operator is the same as above. 10 positions wide and 3 digits after the period.
        printf("/%10.3e/\n", 1234.56); 
        //This operator is the same as above too. Just 10 positions wide but we can't see the positions wide because it use exponents which is a longhand. so 10 positions wide, 3 digit after the period and exponents.


    // Iteration Operator
    // for loop = repeats a section of code a limited amount of times.
        for (int i = 1; i <= 10; i++) {
        // i = index, i <= 10 means to continue the loop as long as i <= 10 and i++ increase the i value by 1 after each iterations.
            printf("%d\n", i);
            printf("test\n"); // It executes the code from the top to the bottom and it's one iteration.
        }
        for (int i = 1; i <= 100; i+=2) { // We can also use augmented assignment operator (+=).
            printf("%d\n", i);
        }
        // Or We can count down by 1 or by two using (i-=2).
        for (int i = 10; i >= 1; i--) {
        // i >= 1 means to continue the loop as long as i >= 1 and i-- decrease the i value by 1 after each iterations.
            printf("%d\n", i);
        }
        // And we can create this kind of stuff!!
        for (int i = 1; i <= 100; i++) {
        printf("%d. ", i);
        printf("B sl o!!\n");
        }


    // While Loop
        int count = 1;
        while (count < 5) { // If the condition is true then the code will be executed and it will continue until the condition is false.
            count = count + 1; // Due to the code execute from top to bottom. There's different between putting this line above and below the printf() function.
            printf("While loop in C: %d\n", count);
        }
        // Here it is:
        while (count < 5) {
            printf("While loop in C: %d\n", count);
            count = count + 1;
        }
        // Or if we want to print the word or sentence in loop:
        while (count < 5) {
            printf("While loop in C\n");
            count = count + 1;
        }
        // But if you don't write this line [count = count + 1], the loop won't end because the condition will never be false and the code will always executes.
        while (count < 5) {
            printf("While Loop in C\n");
        }


    // Do-while Loop
        int count = 1;
        do {
            printf("%d\n", count); // Body of the loop.
            count = count + 1;
        }   while (count < 5); // If the condition evaluate to true, the body of the loop will be executed. And if the condition is false, then the loop will be terminated.
        // The code got execute in the (do) block and condition checked in (while). and that's what make the code in the (do-while) loop get executed once even when the condition is false.
        // Let's see:
        int countt = 5;
        do {
            printf("%d\n", countt);
            countt = countt + 1;
        }   while (countt < 5); // It display 5 first and then check and see the condition is false, so the loop terminates. It's different from the (while) loop because while loop check first and display later.


    // Selection Statement:
        int num;
        printf("Enter your age: ");
        scanf("%d", &num);
        // if statement: we usually use (if) for the first condition.
        if (num >= 20) { // (if) is a Selection Statement. We use ({}) to open a block of code.
            printf("You're eligible to vote in election\n");
        }
        // else if statement: we usually use (else if) for the conditions between (if) and (else).
        else if (num <= 0 ) { // (else if) to declare another condition different from above.
            printf("You haven't been born yet!!");
        }
        // else statement: we usually use (else) for the last condition.
        else { // (else) to declare a condition different from all above.
            printf("You're not eligible to vote in election\n");
        }


    // Switch = A more efficient alternative to use many "else-if" statements
    //          allows a value to be tested for equality against many cases.
        char grade;
        printf("Enter your grade: ");
        scanf("%c", &grade);
        switch(grade) {
            case 'A': // Enter condition.
                printf("Perfect!\n");
                break; // You have to give it a break from the condition.
            case 'B':
                printf("You did good!!\n");
                break;
            case 'C':
                printf("You did okay!\n!");
                break;
            case 'D':
                printf("At least it's not F!!\n");
                break;
            case 'F':
                printf("You Failed!!\n");
                break;
            default: // Default uses in case if no cases match.  
                printf("Enter only Valid grade");
        }


    // Jump Statement:
        for (int i = 1; i <= 5; i++) {
            printf("%d\n", i);
            break; // (break) use to skip iteration statement.
        // From the top, it's loop. But when the code encounter (break), the loop is gone.
        }  
        for (int i = 1; i <= 5; i++) {
            if (i == 3) {
            break; // (break) use to skip iteration statement.
            }
            printf("%d\n", i);
        }
        for (int i = 1; i <= 5; i++) { // We'll replace (break) by (continue).
            if (i == 3) {
            continue; // (break) use to skip iteration statement.
            }
            printf("%d\n", i); // In the output, (continue) skip i = 3 while (break) terminates the loop when i = 3.
        }                      // So (continue) uses to skip conditions without terminates the loop.


    // Goto Statement
    printf("Statement 1\n");
    goto end; // It's going to skip over statement 2 to statement 3.
    printf("Statement 2\n");
    end: // (end) here is an identifier. which means we could jump to (end)
    printf("Statement 3\n");
    // We don't actually use (goto statement) in our code. But in some areas (goto statement) is okay.
    // (goto) statement can be used to optimize the execution of code.
    // We might use (goto) statement much better with many nested loop because it's better to jump over the loop. then to break each loops.


    // String:
    char string1[] = "Bro";
    char string2[] = "Code";
    
    strlwr(string1);                   // converts a string to lowercase
    strupr(string1);                   // converts a string to uppercase
    strcat(string1, string2);          // appends string2 to end of string1
    strncat(string1, string2, 1);      // appends n characters from string2 to string1
    strcpy(string1, string2);          // copy string2 to string1
    strncpy(string1, string2, 2);      // copy n characters of string2 to string1
    
    strset(string1, '?');              //sets all characters of a string to a given character
    strnset(string1, 'x', 1);          //sets first n characters of a string to a given character
    strrev(string1);                   //reverses a string

    //int result = strlen(string1);                 // returns string length as int
    //int result = strcmp(string1, string2);        // string compare all characters
    //int result = strncmp(string1, string2, 1);    // string compare n characters
    //int result = strcmpi(string1, string1);       // string compare all (ignore case)
    //int result = strnicmp(string1, string1, 1);   // string compare n characters (ignore case)


    // To check how many elements in our array.
    int length = sizeof(student_score) / sizeof(student_score[0]);
    printf("\n\nNumber of element in our array: %d", length);


    // Extern: uses to change global variables value. Global Variables are outside the main function.
    extern a;
    a = 15;




    return 0;
}