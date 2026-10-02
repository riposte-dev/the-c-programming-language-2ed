// Exercise 1-8. Write a program to count blanks, tabs, and newlines.
#include <stdio.h>

int main()
{
    int c, nc;

    nc = 0;
    while ((c = getchar()) != EOF)
        if (c == ' ' || c == '\t' || c == '\n')
            ++nc;
    
    printf("%d\n", nc);
}