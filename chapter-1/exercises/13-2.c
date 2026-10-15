// Exercise 1-13. Write a program to print a histogram of the lengths of words in its input. It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.
#include <stdio.h>

#define MAX_LENGTH 20 // Maximum length of a word

int main() {
    int c, length = 0;

    int lengths[MAX_LENGTH] = {0}; // Initialize array with all elements set to 0

    // Count word lengths
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            ++lengths[length - 1]; // Since array starts at index 0, we subtract 1 to get the proper index
            length = 0; // Reset length counter when c is outside a word
        } else
            ++length; // While c is inside a word, continue incrementing the length
    }

    int lowerBound, upperBound;

    // Find lower and upper bounds (So that the histogram only shows relevant data)
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

    int maxHeight = 0;

    for (int i = 0; i < MAX_LENGTH; ++i) {
        if (maxHeight < lengths[i])
            maxHeight = lengths[i];
    }

    // Print histogram
    printf("Word Lengths\n"); // Print heading

    for (int i = 0; i < maxHeight; ++i) {
        for (int j = 0; j < (upperBound - lowerBound) + 1; ++j) {
            if (lengths[j] < (maxHeight - i)) {
                printf(" \t");
            } else
                printf("■\t");
        }

        printf("\n");
    }

    // Print horizontal axis units
    for (int i = 0; i < (upperBound - lowerBound) + 1; ++i) {
        printf("%d\t", i + 1);
    }

    printf("\n");

    return 0;
}