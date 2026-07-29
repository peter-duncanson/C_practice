#include <stdio.h>
#include <stdlib.h>
#include "exercises.h"

void print_array(int *a, int n);

int main(void)
{
    int *a = create_array(10, 500);
    
    print_array(a, 10);

    free(a);

    return 0;
}

void print_array(int *a, int n)
{
    for (int *p = a; p < a + n; p++)
        printf("%d ", *p);
    puts("");
}

