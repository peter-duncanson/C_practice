#include <stdio.h>
#include <limits.h>

// Problem 2.1
// Determine the size, min and max value of the data types (64 bit machine)
// - char
// - unsigned char
// - short
// - int
// - unsigned int
// - unsigned long
void sizes() {
    printf("The size of a char is %d bits\n", CHAR_BIT);
    printf("The max value of a char is %d\n", SCHAR_MAX);
    printf("The min value of a char is %d\n", SCHAR_MIN);
    printf("The size of a unsigned char is %d bits\n", CHAR_BIT);
    printf("The max value of a unsigned char is %d\n", UCHAR_MAX);
    printf("The min value of a unsigned char is %d\n", 0);
    printf("The size of a short is %d bits\n", sizeof(short) * CHAR_BIT);
    printf("The max value of a short is %d\n", SHRT_MAX);
    printf("The min value of a short is %d\n", SHRT_MIN);
    printf("The size of a int is %d bits\n", sizeof(int) * CHAR_BIT);
    printf("The max value of a int is %d\n", INT_MAX);
    printf("The min value of a int is %d\n", INT_MIN);
    printf("The size of a unsigned int is %d bits\n", sizeof(int) * CHAR_BIT);
    printf("The max value of a unsigned int is %ud\n", UINT_MAX);
    printf("The min value of a unsigned int is %d\n", 0);
    printf("The size of a long is %d bits\n", sizeof(long) * CHAR_BIT);
    printf("The max value of a long is %ld\n", LONG_MAX);
    printf("The min value of a long is %ld\n", LONG_MIN);
}

// Problem 2.2
// Write logical expressions to test whether a given char variable c is
// - lower case
// - upper case
// - digit
// - white space (space, tab, newline)
void test_char(char c) {
    if (97 <= c && c <= 122) {
        printf("%c is a lowercase letter\n", c);
    }
    else if (65 <= c && c <= 90) {
        printf("%c is an uppercase letter\n", c);
    }
    else if (7 <= c && c <= 13 || c == 32) {
        printf("c a whitespace\n");
    }
    else {
        printf("%c is something else\n", c);
    }
}

// Problem 2.3
// Consider int val = 0xCAFE;
// Write expressions using bitwise operations that do the following
// - test if at least three of the last four bits are on
// - reverse the byte order (0xFECA)
// - rotate fourbits (0xECAF)
void bit_ops() {
// 0000
// 0001
// 0010
// 0011
// 0100
// 0101
// 0110
// 0111
// 1000 8
// 1001 9
// 1010 A
// 1011 B
// 1100 C
// 1101 D
// 1110 E
// 1111 F
    // val = 1100 1010 1111 1110
    int val = 0xCAFE;

    int last_four_on = (val & 0x001) > 0b0111;
    printf("last 4 on: %d\n", last_four_on);

    int rev_bytes = ((val & 0x00FF) << 8) | ((val & 0xFF00) >> 8);
    // val = 1100 1010 1111 1110
    //  -> = 1111 1110 1100 1010
    printf("reversed bytes (should be FECA): %X\n", rev_bytes);

    int fourbits = val << 3 | val >> 1;
    printf("fourbits (should be ECAF): %X\n", fourbits);
}

int main() {
    bit_ops();
    return 0;
}
