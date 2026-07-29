#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

// exercise 1
void *my_malloc(size_t size)
{
    void *p = malloc(size);
    if (p == NULL)
    {
        puts("FATAL ERROR: malloc returned null pointer.");
        exit(EXIT_FAILURE);
    }
    else return p;
}

// exercise 2
char *duplicate(const char *str)
{
    char *copy = malloc(strlen(str) + 1);
    return strcpy(copy, str);
}

// exercise 3
int *create_array(int n, int initial_value)
{
    int *array = malloc(sizeof(int) * n);
    if (array == NULL)
    {
        return NULL;
    }
    for (int *p = array; p < array + n; p++)
        *p = initial_value;
    return array;
}
