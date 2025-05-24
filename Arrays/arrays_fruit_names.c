// Fruit Names Array: Declare a string array to store names of fruits and print each fruit name on a new line.
#include <stdio.h>

int main() {
    char fruit_names[4][9] = {"Apple", "Banana", "Orange", "Peach"};
    for(int i = 0; i <= 3; i++) {
        printf("%s\n", fruit_names[i]);
    }
    return 0;
}