// Exercise 1-13. Write a program to print a histogram of the lengths of words in its input. It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.
#include <stdio.h>

#define MAX_LENGTH 20 // Maximum length of a word to measure

int main() {
    int c, length = 0;

    int lengths[MAX_LENGTH] = {0}; // Initialize array with all elements set to 0

    // Count the lengths of words
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            // Outside word
            ++lengths[length - 1]; // Since index starts at 0, subtract 1 to get the corresponding index for length
            length = 0; // Reset length counter
        } else
            // Inside word
            ++length;
    }

    int lowerBound, upperBound;

    // Find lower and upper bounds (So that the histogram isn't largely empty space)
    for (int i = 0; i < MAX_LENGTH; ++i) {
        if (lengths[i] != 0) {
            lowerBound = i + 1;
            break;
        }
    }

    for (int i = MAX_LENGTH - 1; i > 0; --i) {
        if (lengths[i] != 0) {
            upperBound = i + 1;
            break;
        }
    }

    // Print histogram
    printf("Length\tOccurences\n"); // Print heading
    for (int i = lowerBound; i <= upperBound; ++i) {
        printf("%6d\t", i); // Print "Length" (1, 2, 3, ...)

        for (int j = 0; j < lengths[i - 1]; ++j)
            printf("■"); // Print "Occurences"

        printf("\n");
    }

    return 0;
}