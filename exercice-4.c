#include <stdio.h>
#include <string.h>

// Defining the structures to represent the data

struct Lecturer {
    int lecturer_id;
    char first_name[50];
    char last_name[50];
};

struct Course {
    char course[50];
    int lecturer_id;
    char country[50];
};

// Array of lecturers
struct Lecturer lecturers[] = {
    {30, "Him", "Hey"},
    {31, "Ronan", "Ogor"},
    {32, "Gran", "Sabandal"},
    {33, "Christian", "Mediola"}
};

// Array of courses
struct Course courses[] = {
    {"java", 32, "Philippines"},
    {"java", 33, "Philippines"},
    {"html", 30, "Cambodia"},
    {"java", 31, "Cambodia"}
};
 

int main() {
     // You code here
 
    return 0;
}
