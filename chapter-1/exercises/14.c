// Exercise 1-14. Write a program to print a histogram of the frequencies of different characters in its input.
#include <stdio.h>

int main() {
    int c;

    while ((c = getchar())) {
        printf("%d ", c - '0');

        if (c == EOF) {
            break;
        }
    }
    printf("\n");

    return 0;
}