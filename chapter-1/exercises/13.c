#include <stdio.h>

#define MAX_LENGTH 10 // Maximum length of a word
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
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else {
            state = IN;
            ++length;
        }

        if (state == OUT) {
            printf("%d\n", length);
            putchar('\n');
            length = 0;
        } else
            putchar(c);
    }

    return 0;
}