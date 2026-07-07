#include <stdio.h>
//==============================================================================
// (1) Modify the <repdigit.c> program in Section 8.1 so that it shows which
// digits (if any) were repeated.
void repeated_digit_display(void) {

    // create array to track which digits have been seen
    // in order to track specfic repeats, using:
    // 0 = not seen
    // 1 = seen once
    // 2 = seen more than once
    int i, seen_digits[10] = { 0 };

    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    while (n > 0) {
        i = n % 10;
        if (seen_digits[i]) {
            seen_digits[i] = 2;
        }
        else {
            seen_digits[i] = 1;
        }
        n /= 10;
    }

    printf("The repeated digits were:");
    for (i = 0; i < 10; i++) {
        if (seen_digits[i] == 2) {
            printf(" %d", i);
        }
    }
    puts("");
}
//==============================================================================

//==============================================================================
// (2) Modify the <repdigit.c> program in Section 8.1 so that it prints a table
// showing how many times each digit appears in the number.
void repeated_digit_table(void) {
    // Table will look something like this
    // Digit    Occurances
    // 0            X
    // 1            X
    // 2            X
    // 3            X
    // 4            X
    // 5            X
    // 6            X
    // 7            X
    // 8            X
    // 9            X
    
    // array will now just store amount of occurances
    int i, digit_counts[10] = { 0 };

    long n; // variable to store input
    
    printf("Enter a number: ");
    scanf("%ld", &n);

    while (n > 0) {
        i = n % 10;
        digit_counts[i] += 1;
        n /= 10;
    }
    puts("");

    printf("Digits\tOccurances\n======\t==========\n");
    for (i = 0; i < 10; i++) {
        printf("%3d\t%5d\n", i, digit_counts[i]);
    }
    puts("");
}
//==============================================================================

//==============================================================================
// (3) Modify the <repdigit.c> program of Section 8.1 so that the user can enter
// more than one number to be tested for repeated digits. The program should
// terminate when the user enters a number thats less than or equal to zero.
void repeated_digits_loop(void) {

    // just going to put the previous function in a loop
    // instead of manually clearing the array, ill just 
    // re-instantiate it each time the loop runs
    // I assume that is faster..
    while (1) {

        int i, digit_counts[10] = { 0 };

        long n;

        printf("Enter a number or 0 to end: ");
        scanf("%ld", &n);

        if (n <= 0) {
            puts("Thank you for playing!\n");
            break;
        }

        while (n > 0) {
            i = n % 10;
            digit_counts[i] += 1;
            n /= 10;
        }

        puts("");

        printf("Digits\tOccurances\n======\t==========\n");
        for (i = 0; i < 10; i++) {
            printf("%3d\t%5d\n", i, digit_counts[i]);
        }

        puts("");
    }
}
//==============================================================================

//==============================================================================
// (4) Modify the <reverse.c> program of Section 8.1 and use the expression
// (int) (sizeof(a) / sizeof(a[0])) (or a macro with this value) for the array
// length.
//==============================================================================
