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
            ++lengths[length]; // Increment the number count for words with a given length
            length = 0; // Reset length counter for new word
        } else {
            state = IN;
            ++length; // So long as c is inside a word, continue incrementing the length
        }
    }

    for (int j = 1; j < MAX_LENGTH + 1; ++j)
        printf("(%d, %d)\n", j, lengths[j]);

    return 0;
}