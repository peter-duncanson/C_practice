#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// prints a warning message to stderr
void Warning(char *message)
{
    fprintf(stderr, "WARNING: %s\n", message);
}

// prints an error message to stderr and terminates the program
void Error(char *message)
{
    fprintf(stderr, "FATAL ERROR: %s\n", message);
    exit(1);
}
