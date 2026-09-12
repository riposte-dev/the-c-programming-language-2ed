#include <stdio.h>

#define MAX_LENGTH 10 /* maximum possible length of a word */
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

int main() {
    int c, state;
    int lengths[MAX_LENGTH];

    // A word needs to be at least one letter
    for (int i = 1; i < MAX_LENGTH + 1; ++i) {
        lengths[i] = 0;
        printf("(%d, %d) ", i, lengths[i]);
    }

    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else
            state = IN;

        if (state == OUT)
            putchar('\n');
        else
            putchar(c);
    }

    return 0;
}