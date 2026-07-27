// =================================================================================================
// Chapter 13 exercises
// =================================================================================================

// =================================================================================================
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

void one(void);
void two(void);
void three(void);
int four_a(char str[], int n);
int four_b(char str[], int n);
int four_c(char str[], int n);
int four_d(char str[], int n);
void capitalize(char *str);
void censor(char *str);
void seven(char str[]);
void eight(char str[]);
void nine(char s1[], char s2[]);
void duplicate(const char *p, char *q);

char str[100];
char s1[100];
char s2[100];

int main(int argc, char **argv)
{
    char *p = "hello";
    char s[strlen(p) + 1];
    duplicate(p, s);
    printf("%s\n", s);
    return 0;
}
// =================================================================================================

// =================================================================================================
// (1) The following function calls supposedly write a single newline char but some are incorrect.
void one(void)
{
    // printf("%c", '\n'); // this is fine
    // printf("%c", "\n"); // this is NOT, format expects int type, "\n" is char *
    // printf("%s", '\n'); // this is wrong, format expects char *, will seg fault
    // printf("%s", "\n"); // this is fine
    // printf('\n'); // this is wrong, printf expects const char *
    // printf("\n"); // this is fine
    // putchar('\n'); // this is fine
    // putchar("\n"); // this is wrong, putchar expects int, "\n" is const char *
    // puts('\n'); // this is wrong, puts expects const char *, '\n' is char type 
    // puts("\n"); // this is TECHNICALLY fine but will not behave as 'expected', will print 2 newlines
    // puts(""); // this is fine
}
// =================================================================================================

// =================================================================================================
// (2) Suppose that p has been declared as char *p = "abc";
// which of the following calls are legal?
void two(void)
{
    char *p = "abc";

    // putchar(p); // this is wrong, p is const char *, not char (integer)
    putchar(*p); // this is fine, will print 'a'
    puts(p); // this is also fine, will print "abc\n"
    // puts(*p); // this is wrong, puts expects const char * but *p is char (integer)
}
// =================================================================================================

// =================================================================================================
// (3) suppose that we call scanf as follows. what will be the values of i, s, and j if the user
// enters "12abc34 56def78" -> i = 12, s = abc34, j = 56. %d format reads digits 0-9. when 'a' is
// reached, begins storing in s. When %s format reaches whitespace, begins storing in j. When j
// reaches non 0-9 digit (d in def) it will terminate.
void three(void)
{
    int i, j;
    char s[10];

    scanf("%d %s %d", &i, s, &j);

    printf("i = %d\ns = %s\nj = %d\n", i, s, j);
}
// =================================================================================================

// =================================================================================================
// (4) modify read_line() in the following ways
// (a) have it skip whitespace before beginning to store input characters
// (b) have it stop reading at the first whitespace character
// (c) have it stop reading at the first newline char, then store the newline char in the string
// (d) have it leave behind characters that it doesnt have room to store
// int read_line(char str[], int n)
// {
//      int ch, i = 0;
//
//      while ((ch = getchar()) != '\n')
//      {
//          if (i < n) str[i++] = ch;
//      }
//      str[i] = '\0';
//      return i;
// }
int four_a(char str[], int n)
{
    int c, i = 0;
    bool read = false;

    while ((c = getchar()) != '\n')
    {
        if (c != ' ') read = true;
        if (i < n && read) str[i++] = c;
    }
    str[i] = 0;
    return i;
}

int four_b(char str[], int n)
{
    int c, i = 0;

    while (true)
    {
        c = getchar();
        if (isspace(c) || c == '\n') break;
        if (i < n) str[i++] = c;
    }
    str[i] = 0;
    return i;
}

int four_c(char str[], int n)
{
    int c, i = 0;

    while ((c = getchar()) != '\n')
    {
        if (i < n) str[i++] = c;
    }
    str[i] = '\n';
    str[++i] = 0;
    return i;
    
}

int four_d(char str[], int n)
{
    int c, i = 0;

    while ((c = getchar()) != '\n')
    {
        if (i < n) str[i++] = c;
        else break;
    }
    str[i] = 0;

    return i;
}
// =================================================================================================

// =================================================================================================
// (5) Write a function that capitalizes all letters in a null terminated string.

void capitalize(char *str)
{
    while (*str != 0)
    {
        *str = toupper(*str);
        str++;
    }
}
// =================================================================================================

// =================================================================================================
// (6) write a function that turns all occurances of foo in a string into xxx
void censor(char str[])
{
    while (*(str + 2))
    {
        if (!strncmp(str, "foo", 2))
        {
            *str = 'x';
            *(str + 1) = 'x';
            *(str + 2) = 'x';
            str += 2;
        }
        else str++;
    }
}
// =================================================================================================

// =================================================================================================
// (7) Suppose that str is a char array, which of the statements is not equivalent to the others?
void seven(char str[])
{
    *str = 0;
    str[0] = '\0';
    strcpy(str, "");
    strcat(str, ""); // <- this is the odd man out, adds a null byte to the end of str
}
// =================================================================================================

// =================================================================================================
// (8) What will the value of the string str be after the following statements have been executed?
void eight(char str[])
{
    strcpy(str, "tire-bouchon"); // tire-bouchon
    strcpy(&str[4], "d-or-wi");  // tired-or-wi
    strcat(str, "red?");         // tired-or-wired?
}
// =================================================================================================

// =================================================================================================
// (9) what will the value of the string s1 be after the following statements have been executed?
void nine(char s1[], char s2[])
{
    strcpy(s1, "computer");
    strcpy(s2, "science");
    if (strcmp(s1, s2) < 0) // s1 shorter than s2? (no)
        strcat(s1, s2);
    else
        strcat(s2, s1);     // this will execute -> "computerscience"
    s1[strlen(s1) - 6] = '\0'; // "computers\0"
}
// =================================================================================================

// =================================================================================================
// (10) The following function is supposed to create a identical copy of a string, what is wrong
// with it?
// char *duplicate(const char *p)
// {
//     char *q;
//
//     strcpy(q, p);
//     return q;
// }
// q is declared as a pointer to a char, and is uninitialized, doesnt point to an array of bytes.
// the code will not compile, if q is initialized to some string, the program will segfault as q is
// READ ONLY, we must declate q as a char array. q is also LOCAL to the function, and will be
// dropped when the function returns. we need to pass in an char array pointer with the same scope
// as where the function is called at least.
void duplicate(const char *p, char *q)
{
    strcpy(q, p);
}
// =================================================================================================
