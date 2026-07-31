#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define DEBUG 0

FILE *fptr = NULL;
int c, i, j, a[5][16];

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        #if DEBUG
        printf("%s\n", argv[1]);
        #endif

        fptr = fopen(argv[1], "r");
    }

    if (fptr == NULL)
    {
        printf("Unable to read file.\n");
        exit(1);
    }

    while ((c = (fgetc(fptr))) != EOF)
    {
        if (c == '\n')
        {
            i++;
            j = 0;
            continue;
        }
        else if (c == '*') a[i][j] = 1;
        else a[i][j] = 0;
        j++;
    }

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 16; j++)
        {
            printf("%d ", a[i][j]);
        }
        puts("");
    }

    return 0;
}
