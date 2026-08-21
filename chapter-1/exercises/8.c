#include <stdio.h>

/* count blanks, tabs, and newlines in input */
int main()
{
    int c, nc;

    nc = 0;
    while ((c = getchar()) != EOF)
        if (c == ' ' || c == '\t' || c == '\n')
            ++nc;
    printf("%d\n", nc);
}