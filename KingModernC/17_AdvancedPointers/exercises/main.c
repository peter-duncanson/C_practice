#include <stdio.h>
#include <stdlib.h>
#include "exercises.h"

void print_array(int *a, int n);

int main(void)
{
    struct
    {
        union
        {
            char a, b;
            int c;
        } d;
        int e[5];
    } f, *p = &f;

    p->d->c = 20;
    printf("%d\n", p->d->c);

    return 0;
}

void print_array(int *a, int n)
{
    for (int *p = a; p < a + n; p++)
        printf("%d ", *p);
    puts("");
}

