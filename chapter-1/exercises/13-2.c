/*
Exercise 1-13.
Write a program to print a histogram of the lengths of words in its input.
It is easy to draw the histogram with the bars horizontal;
a vertical orientation is more challenging.
*/
#include <stdio.h>

#define MAX_LENGTH 20 // Maximum length of a word

int main() {
    int c, length;
    int lengths[MAX_LENGTH];

    // Initialize array (A word needs to be at least one letter, so i > 0)
    for (int i = 1; i < MAX_LENGTH + 1; ++i)
        lengths[i] = 0;

    length = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            ++lengths[length];
            length = 0; // Reset length counter when c is outside a word
        } else
            ++length; // So long as c is inside a word, continue incrementing the length
    }

    // Find the most commonly occuring length of a word
    int top_length = 0;
    for (int j = 1; j < MAX_LENGTH + 1; ++j) {
        if (lengths[j] > top_length) {
            top_length = lengths[j];
        }
    }

    return 0;
}