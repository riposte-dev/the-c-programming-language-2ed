// Exercise 1-13. Write a program to print a histogram of the lengths of words in its input. It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.
#include <stdio.h>

#define MAX_LENGTH 20 // Maximum length of a word

int main() {
    int c, length = 0;

    int lengths[MAX_LENGTH] = {0}; // Initialize array with all elements set to 0

    // Count the lengths of words
    while ((c = getchar())) {
        if (c == ' ' || c == '\n' || c == '\t') {
            // Outside word
            ++lengths[length - 1]; // Since index starts at 0, subtract 1 to get the corresponding index for length
            length = 0; // Reset length counter
        } else if (c == EOF) {
            ++lengths[length - 1];
            break;
        } else {
            // Inside word
            ++length;
        }
    }

    int lowerBound, upperBound;

    // Find lower and upper bounds (So that the histogram only shows relevant data)
    for (int i = 0; i < MAX_LENGTH; ++i) {
        if (lengths[i] != 0) {
            lowerBound = i;
            break;
        }
    }

    for (int i = MAX_LENGTH - 1; i > 0; --i) {
        if (lengths[i] != 0) {
            upperBound = i;
            break;
        }
    }

    int maxHeight = 0;

    for (int i = 0; i < MAX_LENGTH; ++i) {
        if (maxHeight < lengths[i]) {
            maxHeight = lengths[i];
        }
    }

    // Print histogram
    printf("Word Lengths\n"); // Print heading

    for (int i = 0; i < maxHeight; ++i) {
        for (int j = lowerBound; j <= upperBound; ++j) {
            if (lengths[j] < (maxHeight - i)) {
                printf(" \t");
            } else {
                printf("■\t");
            }
        }

        printf("\n");
    }

    // Print horizontal axis units
    for (int i = lowerBound; i <= upperBound; ++i) {
        printf("%d\t", i + 1);
    }

    printf("\n");

    return 0;
}