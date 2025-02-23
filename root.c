#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct Car {    // Line 942th
    int carID;
    char carModel[20];
    int rentalRatePerDay;
};

// NOTE: This file contains a bunch of exercises. Please copy a block of exercise into a separate file to run.
int main() {

    
    // Exercise: Declare an integer variable and assign it the value 5. Print the integer value.
    int five = 5;
    printf("Integer value: %d\n", five);


    // Exercise: Declare a float variable and assign it the value 3.14159. Print the float value.
    float phi = 3.14159;
    printf("float value: %f\n", phi);


    // Exercise: Declare a character variable and assign it the value 'X'. Print the character value.
    char ex = 'X';
    printf("Character value: %c\n", ex);


    // Exercise: Declare two integer variables, assign values 10 and 20 respectively. Print both integer value.
    int x = 20, y = 30;
    printf("Both integer value are: %d and %d\n", x, y);


    // Exercise: Declare and assign
    float gpa = 3.75;
    char level = 'S';
    int course = 5;
    printf("GPA: %f\n", gpa);
    printf("Grade Level: %c\n", level);
    printf("Number of courses: %d\n", course);


    // Exercise: Declare a double variable to store the average temperature of a city.
    double temperature = 24.5;
    char Amsterdam = 'A';
    int population = 1000000;
    printf("Average Temperature: %.1lf\n", temperature);
    printf("City Name: %c\n", Amsterdam);
    printf("Population: %d\n", population);


    // Exercise: Declare two integer variables n1 and n2, then calculate the sum of them.
    int one = 20, two = 30;
    printf("20 + 30 = %d\n", one + two);


    // Exercise: Create a program to sum two integer numbers and output value of the sum.
    int x = 20, y = 10;
    printf("This is the sum value of x = 20 and y = 10: %d\n", x + y);


    // Exercise: Create a program to divide two float numbers and out value of the division.
    float phi = 3.14, k = 4.13;
    printf("This is the division of phi = 3.14 and k = 4.13: %f\n", phi / k);


    // Exercise: User input and print it out.
    int num;
    char name[50];
    printf("Enter your name: ");
    scanf("%s", &name);
    printf("Enter your age: ");
    scanf("%d", &num);
    printf("So your name is %s and you're %d years old.", name, num);


    // Variable Exercise:
    int age = 25;
    float height = 2.35;
    char firstInitial = 'S';
    // We use %.2f means we take 2 digits after the period. You can change the digit before (f) to suit your desire number.
    printf("My name is %c, and I'm %d years old\n", firstInitial, age);
    printf("I'm %.2f meters tall.\n", height);


    // Exercise: break and continue
    int number;
    while (1) {
        printf("Enter a number: ");
        scanf("%d", &number);
        if (number <= 0) {
            break; // terminate the loop if number equal or less than 0.
        }
        if ((number % 2) != 0) {
            continue; // to skip if remainder not equal to 0 after being divided by 2.
        }
        printf("%d\n", number);
    }


    // Exercise: Read input from user (n) then calculate the multiplication.
    int number;
    start:
    printf("Enter a positive integer for multiplication list: ");
    scanf("%d", &number);
    if (number < 0) {
        printf("It's not a positive integer!!\n");
        goto start;
    }
    else if (number == 0) {
        printf("Please enter a positive number bigger than zero!!\n");
        goto start;
    }
    else {
        for(int i = 1; i <= 10; i++) {
        printf("%d * %d = %d\n", number, i, (number*i));
    }
    }


    // Exercise: Write a small program to calculate roots of expression: ax*2 + bx + c = 0, where a, b, c are constant.
    int first_real_number;
    int second_real_number;
    int third_real_number;
    int delta;
    float x1;
    float x2;
    printf("Enter the value of each constant of (ax^2 + bx + c = 0)\n");
    printf("Value of a = ");
    scanf("%d", &first_real_number);
    printf("Value of b = ");
    scanf("%d", &second_real_number);
    printf("Value of c = ");
    scanf("%d", &third_real_number);
    // Calculate the value of Delta:
    delta = (second_real_number*second_real_number) - (4*first_real_number*third_real_number);
    if (delta > 0) {
        printf("Delta > 0\n");
        printf("There are two roots:\n");
        float square_root_of_delta = sqrt(delta);
        x1 = (-second_real_number + square_root_of_delta) / (2*first_real_number);
        printf("x1 = %1.2f\n", x1);
        x2 = (-second_real_number - square_root_of_delta) / (2*first_real_number);
        printf("x2 = %1.2f", x2);
    } else if (delta == 0) {
        printf("Delta = 0\n");
        x1 = x2 = (-second_real_number / first_real_number);
        printf("So x1 = x2 = %f", x1);
    } else {
        printf("It has no root!!");
    }


    // Exercise: Use while loop and input positive number and terminate loop when input negative number.
    printf("1.Use while loop and input positive number until negative.\n");
    int num;
    int count = 0;
    while (num >= 0) 
    {
        printf("\tEnter any number : ");
        scanf("%d", &num);
        if (num < 0) {
            break;
        } count++;
    } printf("\tTotal positive number is %d\n", count);


    // Exercise: Write a small program by using switch, in case user input number of months from 1 to 12, and the program will need to show 
    //           full name of the month(likes: January, February,...)
    int number_of_month;
    printf("Enter a number of month: ");
    scanf("%d", &number_of_month);
    switch (number_of_month) {
        case 1:
            printf("It's January");
            break;
        case 2:
            printf("It's February");
            break;
        case 3:
            printf("It's March");
            break;
        case 4:
            printf("It's April");
            break;
        case 5:
            printf("It's May");
            break;
        case 6:
            printf("It's June");
            break;
        case 7:
            printf("It's July");
            break;
        case 8:
            printf("It's August");
            break;
        case 9:
            printf("It's September");
            break;
        case 10:
            printf("It's October");
            break;
        case 11:
            printf("It's November!!");
            break;
        case 12:
            printf("It's December!!");
            break;
        default:
            printf("Please enter a valid number!!");
    }


    // Exercise: Write a program to declare and initialize an integer array of size 5 and print its elements.
    int task_one[] = {1, 2, 3, 4, 5};
    for (int i = 0; i <= 4; i++) {
        printf("%d ", task_one[i]);
    }


    // Exercise: Create a program that calculates the sum of all elements in an integer array of size 7.
    int task_two[] = {1, 2, 3, 4, 5, 6, 7}, sum = 0;
    for (int i = 0; i <= 6; i++) {
        sum += task_two[i];
    }
    printf("\nSum = %d\n", sum);


    // Exercise: Write a program to copy the contents of one integer array into another array of same size.
    int task_three[] = {5, 4, 3, 2, 1}, task_three_parallel[4];
    for (int i = 0; i <= 4; i++) {
        printf("%d ", task_three[i]);
        task_three_parallel[i] = task_three[i];
    }
    printf("\n");
    for (int k = 0; k <= 4; k++) {
        printf("%d ", task_three_parallel[k]);
    }


    // Exercise: Declare an array of integers and initialize it. Find and print the maximum value in the array.
    int task_four[] = {5, 10, 15, 20, 25};
    

    // Exercise: Declare an array of integers and initialize. Calculate and print the average of all elements in the array.
    int task_five[] = {10, 20, 30, 40, 50}, average_five, i, sum_five = 0;
    for (i = 0; i <= 4; i++) {
        sum_five += task_five[i];
        printf("%d + ", task_five[i]);
    }
    printf("\b\b= %d", sum_five);
    average_five = sum_five / (i);
    printf("\nAverage of elements in the array = %d\n", average_five);


    // Exercise: Declare a character array to store a string. Print the string.
    char task_six[20] = "Hello, World!!";
    printf("%s\n", task_six);


    // Exercise: Print each character in the string "CADT".
    char string[] = "CADT";
    for (int i = 0; i <= 3; i++)
    {
        printf("%c ", string[i]);
    }
    printf("\n");


    // Exercise: Concatenate the strings "firstname" and "lastname" to create and print the full name.
    char firstname[10] = "Laruen", lastname[10] = "Wang";
    strcat(firstname, " "); // Combine firstname with space to create space between firstname and lastname.
    strcat(firstname, lastname); // Combine firstname with lastname to create a full name.
    printf("%s\n", firstname);


    // Exercise: Declare a string array to store names of fruits. Print each fruit name on a new line.
    char fruit_names[4][9] = {"Apple", "Banana", "Orange", "Peach"};
    for(int i = 0; i <= 3; i++) {
        printf("%s\n", fruit_names[i]);
    }


    // Exercise: Create a 3x3 two-dimensional integer named matrrix and initialize it.
    //           Then, write code to print the elements of the matrix in a 3x3 grid format.
    int matrix[3][3] = {1, 2 ,3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i <= 2; i++) {
        for (int k = 0; k <= 2; k++) {
            printf("%d ", matrix[i][k]);
        }
        printf("\n");
    }


    // Exercise: Create a program that let user input the number from 1-7 and print the day
    //           of the week based on the number. Example: (1. Monday, 2. Tuesday...etc).
    int daynumber;
    printf("Enter a number between 1 and 7: ");
    scanf("%d", &daynumber);
    switch (daynumber) {
        case 1:
        printf("Monday");
        break;
        case 2:
        printf("Tuesday");
        break;
        case 3:
        printf("Wednesday");
        break;
        case 4:
        printf("Thursday");
        break;
        case 5:
        printf("Friday");
        break;
        case 6:
        printf("Saturday");
        break;
        case 7:
        printf("Sunday");
        break;
        default:
        printf("Please enter a valid number");
    }


    // Exercise: Write a C program that prompts the user to enter two integer numbers. The program should then 
    //           compare these numbers and determine if they are equal.
    int x;
    int y;
    printf("Enter an integer value of x: ");
    scanf("%d", &x);
    printf("Enter an integer value of y: ");
    scanf("%d", &y);
    if (x > y) {
        printf("The value of x is bigger than the value of y.");
    }
    else if (x < y) {
        printf("The value of y is bigger than the value of x.");
    }
    else if (x = y) {
        printf("The value of x is equal to the value of y.");
    }


    // Exercise: Identify Even or Odd Numbers.
    //           Write a C program that asks the user to enter an integer number. The program should then determine if 
    //           the number is even or odd.
    int odd_or_even;
    printf("Please enter an integer number: ");
    scanf("%d", &odd_or_even);
    if ((odd_or_even % 2) == 0) {
        printf("It's an even number!!");
    }
    else {
        printf("It's an odd number!!");
    }


    // Exercise: Identify Positive, Negative or Zero.
    //           Write a C program that prompts the user to enter a number. The program should then determine if the 
    //           number is positive, negative, or zero.
    int identify;
    printf("Please enter an integer number: ");
    scanf("%d", &identify);
    if (identify == 0) {
        printf("It's zero");
    }
    else if (identify > 0) {
        printf("It's a positive number!!");
    }
    else {
        printf("It's a negative number!!");
    }


    // Exercise: Identify Leap Years.
    //           Write a C program that asks the user to enter a year. The program should then determine if the entered 
    //           year is a leap year based on the leap year rule (divisible by 4 but not by 100, or divisible by 400).
    int year;
    printf("Leap year is a year that has 366days which February has 29days.\n");
    printf("Please enter a year: ");
    scanf("%d", &year);
    if (year%4==0 && year%100==0 && year%400!=0) {
        printf("It's not a leap year");
    }
    else if (year%4==0) {
        printf("It's a leap year!!");
    }
    else if (year <= 0) {
        printf("Please enter a valid year!!");
    }


    // Exercise: Check age for eligibility.
    //           Write a C program that prompts the user to enter their age. The program should then determine if the 
    //           person is eligible to vote based on the voting age in your country (replace with the specific voting age).
    int age;
    printf("In any country on earth, you're allowed to vote in the election only when you're above 18 years old.\n");
    printf("Please enter your age: ");
    scanf("%d", &age);
    if (age >= 18) {
        printf("You're eligible to vote in the election!!");
    }
    else if (age < 0) {
        printf("Screw you!!");
    }
    else {
        printf("You're not eligible to vote in the election!!");
    }


    // Exercise: Find the largest of Three Numbers
    //           Write a C program that asks the user to enter three integer numbers. The program should then identify 
    //           the largest number among the three.
    int number1;
    int number2;
    int number3;
    printf("Please enter the first integer value: ");
    scanf("%d", &number1);
    printf("Please enter the second integer value: ");
    scanf("%d", &number2);
    printf("Please enter the third integer value: ");
    scanf("%d", &number3);
    if (number1 > number2 && number1 > number3) {
        printf("The first integer you entered is the largest number.");
    }
    else if (number2 > number1 && number2 > number3) {
        printf("The second integer you entered is the largest number.");
    }
    else {
        printf("The third integer you entered is the largest number.");
    }


    // Exercise: Write a program to print counting from 1 to 10.
    for(int index = 1; index <= 10; index++) {
        printf("%d\n", index);
    }


    // Exercise: Write a program that prints the numbers from 1 to 100. But for multiples of three print “Fizz” instead of 
    //           the number and for the multiples of five print “Buzz”. For numbers which are multiples of both three 
    //           and five print “FizzBuzz”.
    int game = 1;
    for(game = 1; game <= 100; game++) {
        if (game % 3 == 0 && game % 5 == 0) {
            printf("FizzBuzz\n");
        }
        else if (game % 5 == 0) {
            printf("Buzz\n");
        }
        else if (game % 3 == 0) {
            printf("Fizz\n");
        }
        else {
            printf("%d\n", game);
        }
    }


    // Exercise: Write a program to print all the numbers between 1000 and 2000 which are divisible by 7 but are not a multiple of 5.
    int between;
    for(between = 1000; between <= 2000; between++) {
        if (((between % 7) == 0) && ((between % 5) != 0 )) {
            printf("%d\n", between);
        }
    }


    // Exercise: Write a program to calculate factorial of a number.
    int number;
    int i = 1;
    int factorial = 1;
    printf("Enter a positive integer: ");
    scanf("%d", &number);
    if (number == 0) {
        printf("Factorial of 0 = 1");
    }
    else if (number < 0) {
        printf("Bro!!!, I said enter a positive integer.");
    }
    else {
        printf("Factorial of %d: ", number);
        for(i = number; i >= 1; --i) {
            printf("%d x ", i);
            factorial = (factorial*i);
        }
        printf("\b\b");
        printf("= %d", factorial);
    }


    // Exercise: Write a program to sum two integers. However, if the sum is between 15 and 20 it will return 20.
    int x;
    int y;
    int sum;
    printf("Enter the first integer number: ");
    scanf("%d", &x);
    printf("Enter the second integer number: ");
    scanf("%d", &y);
    sum = x + y;
    if (sum < 20 && sum > 15) {
        return printf("20");
    }
    else {
        printf("The value of sum = %d", sum);
    }


    // Exercise: Write a program to construct the following pattern, using a nested for loop.
    /*
    * 
    * * 
    * * * 
    * * * * 
    * * * * * 
    * * * * 
    * * * 
    * * 
    *          */
    for(int i = 1; i <= 5; i++) {
        for(int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
    for(int k = 4; k >= 1; k--) {
        for(int t = 1; t <= k; t++) {
            printf("*");
        }
        printf("\n");
    }


    // Exercise: Write a program to display prime number between 3 to 45
    int number = 45;
    printf("Prime number between 3 to 45 are: ");
    for(int i = 3; i < number; i++) {
        int prime = 1;
        for(int j = 2; j < i; j++) {
            if (i % j == 0) {
                prime = 0;
                break;
            }
        }
        if(prime != 0) {
            printf("%d, ", i);
        }
    }
    printf("\b\b.");


    // Exercise: Write a program that let user enter a positive integer and then calculate the total from (1 to the number input).
    int index;
    int i;
    int sum;
    printf("Please enter a positive integer: ");
    scanf("%d", &index);
    for(i = 1; i <= index; i++) {
        printf(" %d +", i);
        sum += i;
    }
    printf("\b = %d", sum);


    // Exercise: Identify if the number the user input is an odd number or an even number.
    int define;
    printf("Please enter a number: ");
    scanf("%d", &define);
    if ((define % 2) == 0) {
        printf("The number is an even number.");
    }
    else {
        printf("The number is an odd number.");
    }


    // Exercise: Identify a Prime Number.
    int prime;
    int notprime = 1;
    printf("Please enter an integer number: ");
    scanf("%d", &prime);
    if (prime == 2) {
        printf("It's a prime number!!");
    }
    else if (prime == 1) {
        printf("It's not a prime number!!");
    }
    else {
        for (int i = 2; i<(prime); i++) {
            if (prime % i == 0) {
                notprime = 0;
                break;
            }
        }
    }
    if (notprime == 0) {
        printf("It's not a prime number");
    }
    else {
        printf("It's a prime number!!");
    }


    // Exercise: Write a program to deliver a message with a set temperature.
    float temperature;
    printf("Input the temperature darling: ");
    scanf("%f", &temperature); // If noticed the output, you know that the condition is displayed in the new line even when we didn't use (\n). But if we use it, the condition will only display when you run the code again after you've input it.
    if (temperature >= 30) {
        printf("It's a hot day darling, Stay home :)");
    }
    else if (temperature >= 20) {
        printf("It's a nice day to go out. Let's go on a date. Tell me where you wanna go and I'll pick you up.");
    }
    else if (temperature >= 10) {
        printf("It's a bit cold today. You should wear gloove and wool or we can cuddle at home.-,-");
    }
    else {
        printf("No need to go out today. I'll prepare hot food for you.");
    }


    // Exercise: Time Conversion (hh:mm:ss to second). Create a C program that acts as a time converter. 
    //           It should convert time entered in the format hours:minutes:seconds (hh:mm:ss) to its equivalent total number of seconds.
    int hour;
    int minute;
    int second;
    printf("Enter hour: ");
    scanf("%d", &hour);
    printf("Enter minute: ");
    scanf("%d", &minute);
    printf("Enter second: ");
    scanf("%d", &second);
    printf("It is: %d second", hour * 3600 + minute * 60 + second);


    // Exercise: Create a C program that acts as a time converter. It should convert a given number 
    //           of seconds into a human-readable format of hours:minutes:seconds (hh:mm:ss).
    int sec;
    printf("Enter second: ");
    scanf("%d", &sec);
    printf("It is %d hour ", sec / 3600);
    printf("%d min ", sec % 3600 / 60);
    printf("%d second", sec % 3600 % 60);


    // Exercise: Use array to store student scores and then calculate the total of student's scores.
    int student_score[] = {20, 40, 50, 45, 30};
    // Initial sum = 0 so that sum start from 0.
    int sum = 0;
    // Dimension of subject, the first bracket for the number of elements and the second bracket for the number of character in each element.
    char subject[][12] = {"Mathematic", "Physic", "Chemistry", "Histroy", "English"};
    printf("Score of your five subjects: \n");
    // Use (for) to help us display the five subjects.
    // Kind of work smart not hard thing.
    for (int i = 0; i <= 4; i++) {
        //Display the subjects and score of each subject.
        printf("    %s = %d\n", subject[i], student_score[i]);
        //Calculate the sum of points
        sum += student_score[i];
    }
    // Display the total value of sum after the loop ends.
    printf("Sum: %dpoints", sum);


    // Exercise: Use array to store input from user (array limit 20) and find the largest and
    //           smallest number in the array.
    int user_input;
    printf("Enter how many numbers you want to input: "); scanf("%d", &user_input);
    int number[20]; 
    for (int i = 0; i < user_input; i++) {
        printf("Number %d = ", i + 1); scanf("%d", &number[i]);
    }
    int max, min;
    max=number[0];
    min=number[0];
    for(int i = 1; i < user_input; i++){
        // printf("%d",number);
        if (number[i] > max) {
            max = number[i];
        }
        if (number[i] < min) {
            min = number[i];
        }
    }
    printf("%d\n", max);
    printf("%d\n", min);


    // Exercise: Given an array of 9 integer numbers (3, -3, 1, 5, 7, 0, 8, 9, 6). 
    // Write a program that test if an integer number input by a user exist in that array or not.
    int array[9] = {3, -3, 1, 5, 7, 0, 8, 9, 6};
    int k = 0;
    int userInput;
    printf("Please enter a number: "); scanf("%d", &userInput);
    for (int i = 0; i < 9; i++) {
        if (userInput == array[i]) {
            k = 1;
            break;
        }
    }
    if (k == 1) {
        printf("The number %d exists in the array!!", userInput);
    }
    else {
        printf("The number %d does not exists in the array!!", userInput);
    }


    // Exercise: There are n kids with candies. You are given an integer array candies, where each candies[i] represents the number of candies
    //           the ith kid has, and an integer extraCandies, denoting the number of extra candies that you have. Return a boolean array 
    //           result of length n, where result[i] is true if, after giving the ith kid all the extraCandies, 
    //           they will have the greatest number of candies among all the kids, or false otherwise.
    int candies[100];
    int nKids, extraCandies, k = 1;
    int greatestKid, r = 0;
    // If the extra candies is givien to the kids if they have the candies greater thann all kid in the array print True else print flase
    while (k != 0) {
        printf("How many kid have candy? "); scanf("%d", &nKids);
        if (nKids <= 0) {
            printf("Ah pler hg bompenh lop lop jg.\n");
        }
        else {
            k = 0;
        }
    }
    for (int i = 0; i < nKids; i++) {  
        candiess:
        printf("Enter the amount of Candy that [%d] kid has: ", i+1);
        scanf("%d", &candies[i]);
        if (candies[i] > 100) {
            printf("Please enter the amount of candy less than 100. Thank ah pler.\n");
            goto candiess;
        }
    }
    printf("Please enter the amount of extra Candy: "); scanf("%d",&extraCandies);
    printf("Overall candy=[");
    for (int i = 0; i < nKids; i++) {
        if (i == (nKids - 1)) {
            printf("%d]",candies[i]);
        }
        else {
            printf("%d,",candies[i]);  
        }
    }   
    printf("\nThe amount of extra candy is: %d\n",extraCandies);
    printf("Boolean result = [");
    for (int i = 0; i < nKids; i++) {
        r = 0;
        greatestKid = 0;
        greatestKid = candies[i] + extraCandies;
        for (int j = 0; j < nKids; j++) {
            if (greatestKid < candies[j]) {
                r = 1;
            }
        }
        if (r == 1) {
            printf("False, ");
        }
        else {
            printf("True, ");
        }
    }
    printf("\b\b]");


    // Exercise: Write a program to ask a user for 10 scores then find the average of those scores and shows the scores 
    //           that are greater than the average.
    int score[10]; 
    int sum = 0;
    int n = 10;
    float average;
    printf("We're going to ask you for 10 scores\n");
    for (int i = 0; i < 10; i++) {
        printf("Score [%d]: ", i+1); scanf("%d", &score[i]);
        if (score[i] < 0) {
            printf("Score can't be lower than 0!!\n");
        }
        sum += score[i];
    }
    average = (float)sum / n;
    printf("Average = %.2f\n", average);
    printf("Scores that are above average: ");
    for (int k = 0; k < 10; k++) {
        if (score[k] > average) {
            printf("%d, ", score[k]);
        }
    }
    printf("\b\b.");


    // Exercise: Write an algorithm that takes two 2D arrays (matrices) of integers and their dimensions, then print a new matrix
    //           where each element is the sum of the corresponding elements from the matrices.
    int matrix_01[10][10], matrix_02[10][10];
    int matrix01_row, matrix01_column;
    int matrix02_row, matrix02_column;
    int matrix_sum[10][10], matrix_subtract[10][10], matrix_multiplication[10][10];
    printf("Write in this format, Example: 3x3, 3x2, 4x4\n");
    printf("Size of matrix_01: "); scanf("%dx%d", &matrix01_row, &matrix01_column);
    printf("Size of matrix_02: "); scanf("%dx%d", &matrix02_row, &matrix02_column);
    if ((matrix01_row * matrix01_column) != (matrix02_row * matrix02_column)) {
        printf("The two matrices do not have the same size. Can not do addition and subtraction.\n");
        return 0;
    }
    else if (((matrix01_row * matrix01_column) == 100) || ((matrix02_row * matrix02_column) == 100)) {
        printf("The size of matrices can't be bigger than 10x10\n");
        return 0;
    }
    printf("\nMatrix_01:\n");
    for (int i = 0; i < matrix01_row; i++) {
        for (int j = 0; j < matrix01_column; j++) {
            printf("Row[%d]th column[%d]th: ", i+1, j+1); scanf("%d", &matrix_01[i][j]);
        }
    }
    printf("\nMatrix_02:\n");
    for (int i = 0; i < matrix02_row; i++) {
        for (int j = 0; j < matrix02_column; j++) {
            printf("Row[%d]th column[%d]th: ", i+1, j+1); scanf("%d", &matrix_02[i][j]);
        }
    }
    for (int k = 0; k < matrix01_row; k++) {
        for (int l = 0; l < matrix01_column; l++) {
            matrix_sum[k][l] = matrix_01[k][l] + matrix_02[k][l];
            matrix_subtract[k][l] = matrix_01[k][l] - matrix_02[k][l];
        }
    }
    for (int a = 0; a < matrix01_row; a++) {
        for (int b = 0; b < matrix01_column; b++) {
            matrix_multiplication[a][b] = 0;
            for (int c = 0; c < matrix01_row; c++) {
                // Use matrix box to understand it faster.
                matrix_multiplication[a][b] += matrix_01[a][c] * matrix_02[c][b];
            }
        }
    }
    printf("\n\nThe sum of the two matrices: \n");
    for (int d = 0; d < matrix01_row; d++) {
        for (int n = 0; n < matrix01_column; n++) {
            printf("%d   ", matrix_sum[d][n]);
        }
        printf("\n");
    }
    printf("\n\nThe subtract of the two matrices: \n");
    for (int d = 0; d < matrix01_row; d++) {
        for (int n = 0; n < matrix01_column; n++) {
            printf("%d   ", matrix_subtract[d][n]);
        }
        printf("\n");
    }
    printf("\n\nThe multiplication of the two matrices: \n");
    for (int d = 0; d < matrix01_row; d++) {
        for (int n = 0; n < matrix01_column; n++) {
            printf("%d   ", matrix_multiplication[d][n]);
        }
        printf("\n");
    }


    // Exercise: Write a C function that takes two arrays of integers and their size, then returns a new array where each
    //           element is the sum of the corresponding elements from the input arrays.
    int array_01[10];
    int array_02[10];
    int sum[10];
    int subtract[10];
    int element_array01, element_array02;
    printf("Number of element in array_01: "); scanf("%d", &element_array01);
    if (element_array01 > 10) {
        printf("Can't input more than 10 elements in the array!!\n");
        return 0;
    }
    printf("Number of element in array_02: "); scanf("%d", &element_array02);
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
        printf("Enter element[%d] in array_01: ", j+1); scanf("%d", &array_01[j]);
    }
    printf("\n");
    for (int j = 0; j < element_array02; j++) {
        printf("Enter element[%d] in array_02: ", j+1); scanf("%d", &array_02[j]);
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


    // Exercise: Convert Decimal To Binary.
    int binarynum[8];
    int binnote[8] = {128, 64, 32, 16, 8, 4, 2, 1};
    int num;
    printf("Input decimal number: "); scanf("%d", &num);
    for (int i = 0; i < 8; i++) {
        if (num >= binnote[i]) {
            binarynum[i] = 1;
            num -= binnote[i];
        }
        else if (num < binnote[i]) {
            binarynum[i] = 0;
        }
    }
    printf("Binary: ");
    for (int k = 0; k < 8; k++) {
        printf("%d", binarynum[k]);
    }


    // Exercise: Convert Binary to Decimal.
    int binnote[8] = {128, 64, 32, 16, 8, 4, 2, 1};
    int binnum[8];
    int decimal = 0;
    printf("Input binary number (Sample: 1 1 1 0 1 1 1 1): "); 
    scanf("%d %d %d %d %d %d %d %d", &binnum[0], &binnum[1], &binnum[2], &binnum[3], &binnum[4], &binnum[5], &binnum[6], &binnum[7], &binnum[8]);
    for (int i = 0; i < 8; i++) {
        decimal += (binnote[i] * binnum[i]);
    }
    printf("Decimal number: %d", decimal);


    // Exercise: Design a structure named 'Car'.
    struct Car model[3];
    for (int i = 0; i < 3; i++) {
        printf("\033[0;35m>>> Car 0%d <<<\n\033[0m", i + 1);
        printf("Car ID: ");
        scanf("%d", &model[i].carID); fflush(stdin);
        printf("Car model: ");
        scanf("%[^\n]s", &model[i].carModel);
        printf("Rental rate per day: ");
        scanf("%d", &model[i].rentalRatePerDay);
        printf("\n");
    }
    int rentalDay;
    printf("Number of rental day: "); scanf("%d", &rentalDay);
    for (int i = 0; i < 3; i++) {
        float rentalPrice = 0;
        rentalPrice = rentalDay * model[i].rentalRatePerDay;
        printf("\nCar ID: %d\n", model[i].carID);
        printf("Car model: %s\n", model[i].carModel);
        printf("Price to the number of rental day: \033[0;33m$%.2f\033[0m\n", rentalPrice);
    }

















    return 0;
}