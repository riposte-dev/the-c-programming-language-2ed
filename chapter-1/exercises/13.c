/*
Exercise 1-13.
Write a program to print a histogram of the lengths of words in its input.
It is easy to draw the histogram with the bars horizontal;
a vertical orientation is more challenging.
*/
#include <stdio.h>

#define MAX_LENGTH 20 // Maximum length of a word
#define IN 1 // Inside a word
#define OUT 0 // Outside a word

int main() {
    int c, state, length;
    int lengths[MAX_LENGTH];

    // Initialize array (A word needs to be at least one letter, so i > 0)
    for (int i = 1; i < MAX_LENGTH + 1; ++i)
        lengths[i] = 0;

    state = OUT;
    length = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;

            ++lengths[length];
            length = 0; // Reset length counter when c is outside a word
        } else {
            state = IN;

            ++length; // So long as c is inside a word, continue incrementing the length
        }
    }

    printf("Length\tOccurences\n"); // Print heading
    for (int j = 1; j < MAX_LENGTH + 1; ++j) {
        printf("%6d\t", j); // Print word length on the left column (1, 2, 3...)

        // Print number of occurences on the right column
        for (int k = 1; k < lengths[j] + 1; ++k) {
            printf("|");
        }

        printf("\n");
    }

    return 0;
}