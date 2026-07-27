// Some idioms when working with strings in C

#include <stdio.h>

size_t my_strlen(const char *s);
size_t my_strlen_faster(const char *s);

// The statement
// while (*s)
//     s++;
// and
// while (*s++);
// are both idioms for 'search for the null terminator'
// The second version is more concise, but leaves s pointing just past the null terminator.


int main(void)
{
    

    return 0;
}

// strlib strlen function, searches for the end of a string.
size_t my_strlen(const char *s)
{
    size_t n = 0;

    while (*s++) n++;

    return n;
}

// for some compilers, this version may be faster.
size_t my_strlen_faster(const char *s)
{
    const char *p = s;

    while (*s) s++;

    return s - p;
}

char *my_strcat(char *s1, const char *s2)
{
    char *p = s1;

    while (*p != '\0') p++;

    while (*s2 != '\0')
    {
        *p = *s2;
        p++;
        s2++;
    }
    *p = '\0';

    return s1;
}
