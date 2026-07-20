// =============================================================================
// C Programming: A Modern Approach - K.N. King
// Chapter 8: Functions - Projects
// 06/09/26
// =============================================================================
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "functions.h"
// =============================================================================
// (1) Write a program that asks the user to enter a series of integers (which
// are then stored in an array), then sorts the integers by calling the function
// selection_sort(). When given an array with n elements, selection_sort() must
// do the following:
//
//      1. Search the array and find the largest element, then move it
//      to the last position in the array.
//      2. Call itself recursively to sort the n - 1 elements of the
//      array.
//
// =============================================================================

void selection_sort(int array[], int n)
{
    if (n == 1) return;

    int i, swap, max = 0;

    for (i = 1; i < n; i++)
        if (array[i] > array[max]) max = i;

    swap = array[max];
    array[max] = array[n - 1];
    array[n - 1] = swap;

    return selection_sort(array, n - 1);
}

// =============================================================================
// (2) Modify Programming Project 5 from Chapter 5 so that it uses a function to
// compute the amouint of income tax. When passed an amount of taxable income,
// the function will return the tax due.
// -> From Chapter 5:
//      In one state, single residents are subject to the following income tax:
//          
//          Income:             Amount of tax:
//          < 750               1% of income
//          750-2250            7.50   + 2% of amount over 750
//          2250-3750           37.50  + 3% of amount over 2250
//          3750-5250           82.50  + 4% of amount over 3750
//          5250-7000           142.50 + 5% of amount over 5250
//          > 7000              230    + 6% of amount over 7000
//
//      Write a program that asks the user to enter the amount of taxable
//      income, then displays the tax due.
// =============================================================================

float compute_tax(float income)
{
    if (income < 750.00) return (income * 0.01);
    if (income < 2250.00) return (7.50 + ((income - 750.00) * 0.02));
    if (income < 3750.00) return (37.50 + ((income - 2250.00) * 0.03));
    if (income < 5250.00) return (82.50 + ((income - 3750.00) * 0.04));
    if (income < 7000.00) return (142.50 + ((income - 5250.00) * 0.05));
    return (230.00 + ((income - 7000.00) * 0.06));
}

// =============================================================================
// (3) Modidy Programming Project 9 from Chapter 8 so that it includes the
// following functions:
//
// void generate_random_walk(char walk[10][10]);
// void print_array(char_walk[10][10]);
// 
// main first calls generate_random_walk, which initializes the array to contain
// '.' characters and then replaces some of these characters with the letters
// 'A' through 'Z' as described in the original project. main then calls
// print_array to display the array on the screen.
// -> From Chapter 8:
//          - Indexing randomly moves up, down, right, or left.
//          - If a spot is occupied, try to choose another, if trapped, exit.
// =============================================================================

void generate_random_walk(char walk[10][10])
{
    int i, j, direction;
    srand((unsigned) time(NULL));
    for (i = 0; i < 10; i++)
        for (j = 0; j < 10; j++)
            walk[i][j] = '.';
    i = 0;
    j = 0;
    direction = 0;
    walk[i][j] = 'A';

    for (char letter = 'B'; letter <= 'Z'; letter++)
    {
         try:
            if ((walk[i + 1][j + 1] != '.') &&
                (walk[i - 1][j - 1] != '.') && 
                (walk[i + 1][j - 1] != '.') && 
                (walk[i - 1][j + 1] != '.')) {
                break;
            }

            direction = rand() % 4;
            switch (direction) {
                case 0: // north
                    if (i > 0 && walk[i - 1][j] == '.') {
                        i -= 1;
                        walk[i][j] = letter;
                        break;
                    }
                    else {
                        goto try;
                    }
                case 1: // east
                    if (j < 9 && walk[i][j + 1] == '.') {
                        j += 1;
                        walk[i][j] = letter;
                        break;
                    }
                    else {
                        goto try;
                    }
                case 2: // south
                    if (i < 9 && walk[i + 1][j] == '.') {
                        i += 1;
                        walk[i][j] = letter;
                        break;
                    }
                    else {
                        goto try;
                    }
                case 3: // west
                    if (j > 0 && walk[i][j - 1] == '.') {
                        j -= 1;
                        walk[i][j] = letter;
                        break;
                    }
                    else {
                        goto try;
                    }
            };
    }
}
void print_array(char walk[10][10])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf(" %c", walk[i][j]);
        }
    puts("");
    }
}

// =============================================================================
// (4) Modify Programming Project 16 from Chapter 8 so that it incluces the
// following functions:
//
// void read_word(int counts[26]);
// bool equal_array(int counts1[26], int counts2[26]);
//
// main will call read_word twice, once for each of the two words entered by the
// user. As is reads a word, read_word will use the letters in the word to
// update the counts array, as described in the original project. (main will
// declare two arrays, once for each word. These arrays are usedto track how
// many times each letter occurs in the words.) main will then call equal_array,
// passing it the two arrays. equal_array will return ttrue if the elements in
// the two arrays are identical (indicating that the words are anagrams) and
// false otherwise.
// =============================================================================

void read_word(int counts[26])
{
    char c;
    while ((c = getchar()) != '\n')
    {
        c = toupper(c);
        counts[c - 65] += 1;
    }
}

bool equal_array(int first[26], int second[26])
{
    for (int i = 0; i < 26; i++)
    {
        if (first[i] != second[i]) return false;
    }
    return true;
}

// =============================================================================
// (5) Modiy Programming Project 17 from Chapter 8 so that it includes the
// following functions:
// 
// void create_magic_square(char magic_square[n][n], int n);
// void print_magic_square(char magic_square[n][n], int n);
// =============================================================================

void create_magic_square(int n, int magic_square[][n])
{
    int i = 0;
    int j = n / 2;
    int k;

    for (k = 1; k <= (n * n); k++)
    {
        magic_square[i][j] = k;
        i--;
        j++;

        if (k % n == 0)
        {
            i += 2;
            j--;
        }
        if (i < 0) i = n - 1;
        if (j == n) j = 0;
    }
}

void print_magic_square(int n, int magic_square[][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%2d ", magic_square[i][j]);
        }
    puts("");
    }
}

// =============================================================================
// (6) Write a function that computes the value of the following polynomial:
// 3x^2 + 2x^4 - 5x^3 - x^2 + 7x - 6
// Write a program that asks the user to enter a value for x, calls the function
// to compute the value of the polynomial, and then diaplays the value returned
// by the function.
// =============================================================================

int f(int x)
{
    int ans = (3 * (x * x));
    ans += (2 * (x * x * x * x));
    ans -= (5 * (x * x * x));
    ans -= (x * x);
    ans += (7 * x);
    return ans - 6;
}

// =============================================================================
// (7) The power function from section 9.6 can be made faster by having it
// calculate x^n in a different way. We first notice that if n is a power of 2,
// then x^n can be computed by squaring. For example, x^4 is the square of x^2,
// so x^4 can be computed using only two multiplications instead of three. As it
// happens, this technique can be used even when n is not a power of 2.
// If n is even, we use the formula 
// x^n = (x^(n / 2))^2.
// If n is odd, then 
// x^n = x * (x^(n - 1))
// Write a recursive function that computes x^n.
// =============================================================================

int power(int x, int n)
{
    if (n == 0) return 1;
    if (n == 1) return x;
    if (n & 1) return x * power(x, n - 1);
    return power(x * x, (n >> 1));
}

// =============================================================================
// (8) Write a program that simulates the game of craps, which is played with
// two dice. On the first roll, the player wins if the sum of the dice is 7 or
// 11. The player loses if the sum is 2, 3, or 12. Any other roll is called the
// "point" and the game continues. On each subsequent roll, the player wins if
// they roll the point again. The player loses by rolling 7. Any other roll is
// ignored and the game continues. At the end of each game, the program will ask
// the user whether or not to play again. When the user enters a response other
// than y or Y, the program will display the number of wins and losses then
// terminate.
int roll_dice(void);
bool play_game(void);
// =============================================================================
