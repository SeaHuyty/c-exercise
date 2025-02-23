#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Moderator.h"


// Structure to include all user information
struct user {
    char username[50];
    char password[30];
    char phone[15];
};
struct user user, usr;

// Moderator details
const char moderatorUsername[] = "moderator";
char moderatorPassword[30] = "mod123";  // Initial password

// Function for user input
void takeInput(char ch[50]){
    fgets(ch, 50, stdin);
    ch[strlen(ch) - 1] = 0;
}

// Function to take password
void takePassword(char pwd[30]){
    int i = 0;
    char ch;
    while ((ch = getch()) != '\r' && i < 29){
        if (ch == '\b' && i > 0){
            printf("\b \b");
            i--;
        } else if (ch != '\b'){
            pwd[i++] = ch;
            printf("*");
        }
    }
    pwd[i] = '\0';
}

// Function to check if user already exists
int checkUserExists(char uname[]){
    FILE *fp = fopen("UserProfile.txt", "r");
    if (fp == NULL){
        return 0;
    }
    char storedUsername[50];
    char storedPassword[30];
    char storedPhone[15];
    while (fscanf(fp, "%s %s %s", storedUsername, storedPassword, storedPhone) != EOF){
        if (strcmp(storedUsername, uname) == 0){
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

// Function to change moderator password
void changeModeratorPassword(){
    char oldPassword[30];
    char newPassword[30];
    char confirmPassword[30];

    printf("\nEnter current moderator password: ");
    takePassword(oldPassword);

    if (strcmp(oldPassword, moderatorPassword) == 0){
        do {
            printf("\nEnter new 6-digit password: ");
            takePassword(newPassword);
            if (strlen(newPassword) < 6){
                printf("\nPassword must be at least 6 digits long. Please try again.\n");
            }
        } while (strlen(newPassword) < 6);

        printf("\nConfirm new password: ");
        takePassword(confirmPassword);

        if (strcmp(newPassword, confirmPassword) == 0){
            strcpy(moderatorPassword, newPassword);
            printf("\nPassword changed successfully!\n");
        } else {
            printf("\nPasswords don't match. Try again.\n");
        }
    } else {
        printf("\nIncorrect current password. Try again.\n");
    }
}

// Function to authenticate moderator
int authenticateModerator(){
    char enteredPassword[30];
    printf("\nEnter moderator password: ");
    takePassword(enteredPassword);

    if (strcmp(enteredPassword, moderatorPassword) == 0){
        return 1;  // Authentication successful
    } else {
        printf("\nIncorrect password. Access denied.\n");
        return 0;  // Authentication failed
    }
}

// Function for user to change password using phone number
void changeUserPassword(){
    char phone[15];
    char newPassword[30];
    char confirmPassword[30];
    int userFound = 0;

    printf("\nEnter your registered phone number: ");
    takeInput(phone);

    FILE *fp = fopen("UserProfile.txt", "r+");
    if (fp == NULL){
        printf("\nError opening file!\n");
        return;
    }

    long pos;
    while (!feof(fp)){
        pos = ftell(fp);
        fscanf(fp, "%s %s %s", user.username, user.password, user.phone);
        if (strcmp(user.phone, phone) == 0){
            userFound = 1;
            break;
        }
    }

    if (userFound){
        do {
            printf("\nEnter new 6-digit password: ");
            takePassword(newPassword);
            if (strlen(newPassword) < 6){
                printf("\nPassword must be at least 6 digits long. Please try again.\n");
            } else if (strcmp(newPassword, user.password) == 0) {
                printf("\nNew password cannot be the same as the old password. Please try again.\n");
            }
        } while (strlen(newPassword) < 6 || strcmp(newPassword, user.password) == 0);

        printf("\nConfirm new password: ");
        takePassword(confirmPassword);

        if (strcmp(newPassword, confirmPassword) == 0){
            fseek(fp, pos, SEEK_SET);
            fprintf(fp, "%s %s %s\n", user.username, newPassword, user.phone);
            printf("\nPassword changed successfully!\n");
        } else {
            printf("\nPasswords don't match. Try again.\n");
        }
    } else {
        printf("\nNo user found with the given phone number.\n");
    }

    fclose(fp);
}


int main(){
    int opt;
    char repassword[30];
    char logUserName[50];
    char logPassword[30];
    struct user user;
    struct user usr;
    int userFound = 0;

    FILE *fp;
    do{
        system("cls");
        printf("\n\t\t\t\t----------Welcome to Kleb Jeb Express----------\n");
        printf("1. Signup\n");
        printf("2. Login\n");
        printf("3. Moderator\n");
        printf("4. Change Password Using Phone Number\n");
        printf("0. Exit\n");

        printf("\nYour Choice: ");
        scanf("%d", &opt);
        fgetc(stdin);

        switch (opt){
            case 0:
                system("cls");
                break;
            case 1:
                system("cls");
                printf("\n\t\t\t\t----------Account Signup----------\n");
                printf("Enter your username: ");
                takeInput(user.username);
                // Check if user already exists
                if (checkUserExists(user.username)) {
                    printf("\n!!!Username already exists!!!\n");
                    printf("\nPress any key to continue...");
                    getch();
                    break;
                }

                printf("Enter your phone number: ");
                takeInput(user.phone);

                do {
                    printf("\nEnter your 6-digit password: ");
                    takePassword(user.password);
                    if (strlen(user.password) < 6) {
                        printf("\nPassword must be at least 6 digits long. Please try again.\n");
                    }
                } while (strlen(user.password) < 6);

                printf("\nConfirm your password: ");
                takePassword(repassword);

                if (strcmp(user.password, repassword) == 0) {
                    system("cls");
                    printf("\nAccount Created Successfully\n");
                    // Open file to append user data
                    fp = fopen("UserProfile.txt", "a");
                    if (fp == NULL) {
                        perror("Error opening file");
                        exit(1);
                    }
                    // Write user data to file
                    fprintf(fp, "%s %s %s\n", user.username, user.password, user.phone);
                    fclose(fp);
                    printf("Your username is: %s\n", user.username);
                } else {
                    printf("\n!!!Passwords Don't Match!!!\n");
                }
                printf("\nPress any key to continue...");
                getch();
                break;
            case 2:
                system("cls");
                printf("\n\t\t\t\t----------Account Login----------\n");
                printf("Enter your username: ");
                takeInput(logUserName);
                printf("Enter your password: ");
                takePassword(logPassword);

                fp = fopen("UserProfile.txt", "r");
                if (fp == NULL){
                    printf("\nError opening file!\n");
                    break;
                }
                char storedUsername[50];
                char storedPassword[30];
                char storedPhone[15];
                while (fscanf(fp, "%s %s %s", storedUsername, storedPassword, storedPhone) != EOF){
                    if (strcmp(storedUsername, logUserName) == 0){
                        if (strcmp(storedPassword, logPassword) == 0){
                            printf("\nWelcome %s. You have logged in successfully!!!\n", logUserName);
                        } else {
                            printf("\n!!!!!Invalid password!!!!!\n");
                        }
                        userFound = 1;
                        break;
                    }
                }
                if (!userFound){
                    printf("\n!!!!!User has not registered yet!!!!!\n");
                }
                fclose(fp);
                printf("\nPress any key to continue...");
                getch();
                break;
            case 3:
                system("cls");
                printf("\n\t\t\t\t----------Moderator----------\n");
                if (authenticateModerator()){
                    Moderator();
                }
                //     int modOpt;
                //     printf("1. Change Password\n");
                //     printf("2. View All Users\n");
                //     printf("0. Back\n");
                //     printf("\nYour Choice: ");
                //     scanf("%d", &modOpt);
                //     fgetc(stdin);

                //     switch (modOpt){
                //         case 0:
                //             break;
                //         case 1:
                //             changeModeratorPassword();
                //             break;
                //         case 2:
                //             viewAllUsers();
                //             break;
                //         default:
                //             printf("\n!!!Invalid Option!!!\n");
                //             break;
                //     }
                // }
                printf("\nPress any key to continue...");
                getch();
                break;
            case 4:
                changeUserPassword();
                printf("\nPress any key to continue...");
                getch();
                break;
            default:
                system("cls");
                printf("\t\t\a!!!!INVALID OPTION!!!!\n\n");
                printf("\t\t\aPress any button to go back\n\n");
                getch();
                break;
        }
    } while (opt != 0);
    return 0;
}