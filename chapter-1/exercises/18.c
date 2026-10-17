// Exercise 1-18. Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines.
#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */

int get_line(char line[], int maxline);

int main() {
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */

    while ((len = get_line(line, MAXLINE))) {
        if (len == 1) {
            continue;
        }

        for (int i = len; i > 0; --i) {
            if (line[i - 1] == ' ') {
                continue;
            }
            printf("%c", line[i - 1]);
        }
    }
    return 0;
}

/* get_line: read a line into s, return length */
int get_line(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}