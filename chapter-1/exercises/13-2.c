/*
Exercise 1-13-2. (Vertical Orientation)
Write a program to print a histogram of the lengths of words in its input.
It is easy to draw the histogram with the bars horizontal;
a vertical orientation is more challenging.
*/
#include <stdio.h>

#define MAX_LENGTH 20 // Maximum length of a word

int main() {
    int c, length = 0;
    int lengths[MAX_LENGTH];

    // Initialize array
    for (int i = 0; i < MAX_LENGTH; ++i)
        lengths[i] = 0;

    // Count word lengths
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            ++lengths[length - 1]; // Since array starts at index 0, we subtract 1 to get the proper index
            length = 0; // Reset length counter when c is outside a word
        } else
            ++length; // While c is inside a word, continue incrementing the length
    }

    // Find lower and upper bounds (So that the histogram isn't largely empty space)
    int lowerBound, upperBound;

    for (int n = 0; n < MAX_LENGTH; ++n) {
        if (lengths[n] != 0) {
            lowerBound = n + 1;
            break;
        }
    }

    for (int m = MAX_LENGTH - 1; m > 0; --m) {
        if (lengths[m] != 0) {
            upperBound = m + 1;
            break;
        }
    }

    int maxHeight = 0;

    for (int p = 0; p < MAX_LENGTH; ++p) {
        if (maxHeight < lengths[p])
            maxHeight = lengths[p];
    }

    // Print histogram
    printf("Word Lengths\n"); // Print heading

    for (int k = 0; k < maxHeight; ++k) {
        for (int x = 0; x < (upperBound - lowerBound) + 1; ++x) {
            if (lengths[x] < (maxHeight - k)) {
                printf(" \t");
            } else
                printf("■\t");
        }

        printf("\n");
    }

    // Print horizontal axis units
    for (int j = 0; j < (upperBound - lowerBound) + 1; ++j) {
        printf("%d\t", j + 1);
    }

    printf("\n");

    return 0;
}