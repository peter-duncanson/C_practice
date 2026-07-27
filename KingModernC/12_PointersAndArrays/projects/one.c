// ================================================================================================
// Chapter 12 Pointers and Arrays - Project 1
//
// Write a program that reads a message, then prints the reversal of the message, use a pointer
// instead of an integer to keep track of the current position of the char array.
// ================================================================================================
#include <stdio.h>

#define MAXLEN 100

int main(void)
{
    char c, buffer[MAXLEN], *p = buffer;

    printf("Enter a message: ");

    while (((c = getchar()) != '\n') && (p != (buffer + MAXLEN)))
    {
        *p++ = c;
    }

    printf("Reversal is: ");

    for (char *rp = p; rp >= buffer; rp--)
    {
        printf("%c", *rp);
    }

    puts("");

    return 0;
}
