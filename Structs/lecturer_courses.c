// Exercise Name: Find Lecturers Teaching Java in the Philippines

// Exercise Instruction:
// Given arrays of Lecturer and Course structs, write a program that lists all lecturers who teach the course "java" in the country "Philippines". For each matching lecturer, print their full name (first and last name) along with the course they teach and the country.


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
    int nLecturers = sizeof(lecturers) / sizeof(lecturers[0]);
    int nCourses = sizeof(courses) / sizeof(courses[0]);

    printf("Lecturers teaching java in the Philippines:\n");

    for (int i = 0; i < nCourses; i++) {
        if (strcmp(courses[i].course, "java") == 0 && strcmp(courses[i].country, "Philippines") == 0) {
            // Find the lecturer with lecturer_id matching courses[i].lecturer_id
            for (int j = 0; j < nLecturers; j++) {
                if (lecturers[j].lecturer_id == courses[i].lecturer_id) {
                    printf("%s %s\n", lecturers[j].first_name, lecturers[j].last_name);
                    break;
                }
            }
        }
    }

    return 0;
}
