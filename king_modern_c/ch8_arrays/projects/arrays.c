#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
void reverse_improved(void) {
     
    // previously, a macro called N was used to hold an integer constant for
    // the size of the array and was also used in the for loop. I see how this
    // could be useful if there was some way to pass in an arbitrary array as
    // a kind of argument, or parameter as was mentioned. Otherwise, it seems
    // to be excessive when a macro defining an integer constant could also be 
    // used to instantiate an array and reference its size.

    #define SIZE (int) (sizeof(a) / sizeof(a[0]))

    int i, a[10];

    printf("Enter %d numbers: ", SIZE);
    for (i = 0; i < SIZE; i++) {
        scanf("%d", &a[i]);
    }

    printf("In reverse order:");
    for (i = SIZE - 1; i >= 0; i--) {
        printf(" %d", a[i]);
    }
    puts("");
}
//==============================================================================

//==============================================================================
// (5) Modify the <interest.c> program of Section 8.1 so that it compounds
// interest *monthly* instead of *annually*. The form of the output shouldn't
// change; the balance should still be shown at annual intervals.
void monthly_interest(void) {
    
    // initial investment
    #define INITIAL 100.00

    // number of interest rates to be displayed as columns
    // depends on the size of the value array
    #define N_RATES (int) (sizeof(value) / sizeof(value[0]))

    // number of times compounded per year
    #define N_COMPOUNDED 12 

    // macro stores a factor of the exponential base 
    // let A = P * (1 + ((ALPHA) * R))^NT
    // where:
    // A = amount
    // P = initial amount
    // R = current rate
    // N = number of times compounded per year
    // T = number of years
    // ALPHA = scaled coefficient for rate
    #define ALPHA (float) 1 / (N_COMPOUNDED * 100)

    int i, j, base_rate, n_years, year;
    double value[5];

    printf("Enter interest rate: ");
    scanf("%d", &base_rate);
    printf("Enter number of years: ");
    scanf("%d", &n_years);

    printf("\nYears");
    for (i = 0; i < N_RATES; i++) {
        // print out each of the rates {base, base + 1, ... , base + 4}
        printf("%6d%%", base_rate + i);
        // each member of the array starts by storing the initial investment
        value[i] = INITIAL;
    }
    puts("");

    for (year = 1; year <= n_years; year++) {
        printf("%3d    ", year);
        // do the calcs for each rate
        for (i = 0; i < N_RATES; i++) {
            // compound
            for (j = 1; j <= N_COMPOUNDED; j++) {
                value[i] *= (1 + (ALPHA * (base_rate + i)));
            }
            printf("%7.2f", value[i]);
        }
        puts("");
    }
    puts("");
}
//==============================================================================

//==============================================================================
// (6) The prototypical Internet newbie is a fellow named B1FF, who has a unique
// way of writing messages. Heres a typical B1FF communiqué:
// H3Y DUD3, C 15 R1LLY C00L!!!!!!!!!!
// Write a 'B1FF filter' that reads a message entered by the user and translates
// it into B1FF-speak:
// Enter message: Hey dude, C is rilly cool
// In B1FF-speak: H3Y DUD3, C 15 R1LLY C00L!!!!!!!!!!
// Your program should convert the message to upper-case letters, substitute
// digits for certain letters, and then append 10 or so exclamation marks.
// Mapping: [A -> 4] [B -> 8] [E -> 3] [I -> 1] [O -> 0] [S -> 5] 
void leet_speek(void) {

    // exactly how many exclamation marks do we want to add?
    #define EXCITEMENT 10

    // create a buffer thats large enough to fit any reasonable short message
    char buffer[128];

    // store the length of the message
    int i, len = 0;

    // get the message and store it char by char
    printf("Enter message: ");
    while ((buffer[len] = getchar()) != '\n') {

        if ('a' <= buffer[len] && 'z' >= buffer[len]) {
            buffer[len] -= 32;
        }

        switch (buffer[len]) {
            case 'A':
                buffer[len] = '4';
                break;
            case 'B':
                buffer[len] = '8';
                break;
            case 'E':
                buffer[len] = '3';
                break;
            case 'I':
                buffer[len] = '1';
                break;
            case 'O':
                buffer[len] = '0';
                break;
            case 'S':
                buffer[len] = '5';
                break;
        };

        len++;
        
        if (len >= 118) {
            puts("Max message length reached.");
            break;
        }
    }

    for (i = 0; i <= EXCITEMENT; i++) {
        buffer[len + i] = '!';
    }

    printf("In B1FF-speak: ");
    for (i = 0; i < (len + EXCITEMENT); i++) {
        printf("%c", buffer[i]);
    }
    puts("");
}
//==============================================================================

//==============================================================================
// (7) Write a program that reads a 5x5 array of integers and then prints the
// row sums and the column sums
void marginals(void) {

    int i = 0;
    int a[5][5] = { { 0 } };
    int sum_rows[5] = { 0 };
    int sum_cols[5] = { 0 };

    // read everything in
    for (i = 0; i < 5; i++) {
        printf("Enter row %d: ", i + 1);
        scanf("%d %d %d %d %d", &a[i][0], &a[i][1], &a[i][2], &a[i][3], &a[i][4]);
    }

    // sum it all up
    for (i = 0; i < 5; i++) {
        sum_rows[i] += (a[i][0] + a[i][1] + a[i][2] + a[i][3] + a[i][4]);
        sum_cols[i] += (a[0][i] + a[1][i] + a[2][i] + a[3][i] + a[4][i]);
    }

    printf("Row totals: ");
    for (i = 0; i < 5; i++) {
        printf("%d ", sum_rows[i]);
    }

    puts("");

    printf("Column totals: ");
    for (i = 0; i < 5; i++) {
        printf("%d ", sum_cols[i]);
    }

    puts("");

}
//==============================================================================

//==============================================================================
// (8) Modify Programming Project 7 so that it prompts for five quiz grades for
// each of five students, then computes the total score and average score for
// each *student*, and the average score, high score, and low score for each
// *quiz*
void quiz_data(void) {
    
    int i, j, high_score, low_score = 0;


    int student_totals[5] = { 0 };
    float student_means[5] = { 0.0 };

    int quiz_low[5] = { 0 };
    int quiz_high[5] = { 0 };
    float quiz_mean[5] = { 0.0 };


    int a[5][5] = { { 0 } };

    // read everything in
    for (i = 0; i < 5; i++) {
        printf("Enter scores for student %d: ", i + 1);
        scanf("%d %d %d %d %d", &a[i][0], &a[i][1], &a[i][2], &a[i][3], &a[i][4]);
    }

    // -------- Debugging array ------------
    // int a[5][5] = {
    //     {15, 17, 26, 52, 70},
    //     {95, 92, 90, 99, 93},
    //     {70, 72, 81, 85, 90},
    //     {60, 64, 50, 70, 75},
    //     {87, 91, 89, 88, 95}
    // };
    // -------------------------------------

    // sum it all up
    for (i = 0; i < 5; i++) {

        high_score = low_score = a[0][i];

        int student_total = (a[i][0] + a[i][1] + a[i][2] + a[i][3] + a[i][4]);
        int quiz_total = (a[0][i] + a[1][i] + a[2][i] + a[3][i] + a[4][i]);

        student_totals[i] += student_total;
        student_means[i] += ((float) (student_total / 5.0));
        quiz_mean[i] += (float) (quiz_total / 5.0);

        for (j = 0; j < 5; j++) {

            if (a[j][i] >= high_score) {
                quiz_high[i] = high_score = a[j][i];
            }

            if (a[j][i] <= low_score) {
                quiz_low[i] = low_score = a[j][i];
            }
        }
    }

    printf("Student\t\tMean\t\tTotal\n");
    for (i = 0; i < 5; i++) {
        printf("%2d\t\t%4.1f\t\t%4d\n",
        i + 1, student_means[i], student_totals[i]);
    }

    puts("");

    printf("Quiz\t\tMean\t\tHigh\t\tLow\n");
    for (int i = 0; i < 5; i++) {
        printf("%2d\t\t%4.1f\t\t%3d\t\t%3d\n",
        i + 1, quiz_mean[i], quiz_high[i], quiz_low[i]);
    }
}
//==============================================================================

//==============================================================================
// (9) Write a program that generates a random walk across a 10x10 array. The
// array will contain characters (all '.' initially). The program must randomly
// 'walk' from element to element, always going up, down, left, or right by one
// element. The elements visited by the program will be labeled with the letters
// 'A' through 'Z', in the order visited.
void random_walk(void) {

    char a[10][10] = {
        { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' }
    };
    
    // 0 -> North
    // 1 -> East
    // 2 -> South
    // 3 -> West

    // random number generator seed
    srand((unsigned) time(NULL));

    // variables to track position
    unsigned int i, j, direction = 0;

    for (char letter = 'A'; letter <= 'Z'; letter++) {


        try:

            int stuck = 
                a[i + 1][j + 1] != '.' && 
                a[i - 1][j - 1] != '.' && 
                a[i + 1][j - 1] != '.' && 
                a[i - 1][j + 1] != '.';

            if (stuck) {
                break;
            }

            direction = rand() % 4;

            switch (direction) {
                case 0:
                    if (i > 0 && a[i - 1][j] == '.') {
                        i -= 1;
                        a[i][j] = letter;
                        break;
                    }
                    else {
                        goto try;
                    }
                case 1:
                    if (i < 9 && a[i][j + 1] == '.') {
                        j += 1;
                        a[i][j] = letter;
                        break;
                    }
                    else {
                        goto try;
                    }
                case 2:
                    if (i < 9 && a[i + 1][j] == '.') {
                        i += 1;
                        a[i][j] = letter;
                        break;
                    }
                    else {
                        goto try;
                    }
                case 3:
                    if (j > 0 && a[i][j - 1] == '.') {
                        j -= 1;
                        a[i][j] = letter;
                        break;
                    }
                    else {
                        goto try;
                    }
            };
    }
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf(" %c", a[i][j]);
        }
        puts("");
    }

}
//==============================================================================
