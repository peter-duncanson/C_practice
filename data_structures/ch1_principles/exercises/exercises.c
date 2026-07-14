// =============================================================================
// Data Structures and Program Design
// Chapter 1: Programming Principles - Exercises
// 07/10/26
// =============================================================================
// (1) Rewite the following program so that is accomplishes the same result in a
// less tricky way.
//
// void does_something(int *first, int *second)
// {
//      *first = *second - *first;
//      *second = *second - *first;
//      *first = *second + *first;
// }

void does_something(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

// =============================================================================

// =============================================================================
// (2) Determine what each of the following functions does, rewrite each
// function with meaningful variable names, with better format, and without
// unnecessary variables and statements.
// -----------------------------------------------------------------------------
// (a) -------------------------------------------------------------------------
// #define MAXINT 10
// int calculate(int apple, int orange)
// { int peach, lemon;
// peach = 0; lemon = 0; if (apple < orange) {
// peach = orange; } else if (orange <= apple) {
// peach = apple; } else { peach = MAXINT; } lemon = MAXINT;
// } if (lemon != MAXINT) { return(peach); } }
//
// This function assigns a local int variable to the larger of two input ints
// the else case is impossible to reach, the function will always return
// the value of whichever is larger.

// This function returns the larger of two integers, or the first if equal.
int get_largest(int first, int second)
{
     return (second <= first) ? first : second;
}

// -----------------------------------------------------------------------------
// (b) -------------------------------------------------------------------------
// double figure(double vector1[], int n)
// { int loop1; double loop2; double loop3; int loop4;
// loop1 = 0; loop2 = vector1[loop1]; loop3 = 0.0;
// loop4 = loop1; for (loop4 = 0; loop4 < n; loop4 = loop4 + 1)
// { loop1 = loop1 + 1; loop2 = vector[loop1 - 1];
// loop3 = loop2 + loop3; } loop2 = loop1;
// loop2 = loop3 / loop2; return(loop2); }

// This function divides the sum of its elements by the last element
double weighted_average(double vec[], int n)
{
    double sum = 0.0;

    for (int i = 0; i < n; i++)
    {
        sum += vec[i];
    }

    return sum / vec[n - 1];
}

// -----------------------------------------------------------------------------
// (c) -------------------------------------------------------------------------
// void question(int *a17, int *stuff)
// { int another, yetanother, stillonemore;
// another = yetanother; stilloemore = *a17;
// yetanother = *stuff; another = stillonmore; *a17 = yetanother;
// stillonemore = yetanother;
// *stuff = another; another = yetanother; yetanother = *stuff }

// this function switches two numbers
void switch_numbers(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

// -----------------------------------------------------------------------------
// (d) -------------------------------------------------------------------------
// int mystery(int apple, int orange, int peach)
// { if (apple > orange) if (apple > peach) if
// (peach > orange) return(peach); else if (apple < orange)
// return(apple); else return(orange); else return(apple); else
// if (peach > apple) if (peach > orange) return orange; else
// return(peach); else return(apple); }

// This function returns the median of three integers
int median(int i, int j, int k)
{
    if (i <= j && j <= k) return j;
    if (i <= k && k <= j) return k;
    if (j <= i && i <= k) return i;
    if (j <= k && k <= i) return k;
    if (k <= i && i <= j) return i;
    return j;
}

// -----------------------------------------------------------------------------
// =============================================================================

// =============================================================================
// (3) The following statement is designed to check the relative sizes of three
// integers, which you may assume to be different from each other:

if (x < z) if (x < y) if (y < z) c = 1; else c = 2; else
if (y < z) c = 3; else c = 4; else if (x < y)
if (x < z) c = 5; else c = 6; else if (y < z) c = 7; else
if (z < x) if (z < y) c = 8; else c = 9; else c = 10;

// -----------------------------------------------------------------------------
// (a) -------------------------------------------------------------------------
// Rewrite the statement in a form that is easier to read
// -----------------------------------------------------------------------------

if (x < z) 
    if (x < y)    
        if (y < z) c = 1;
        else c = 2; 
    else if (y < z) c = 3;
    else c = 4;
else if (x < y)
    if (x < z) c = 5; 
    else c = 6; 
else if (y < z) c = 7;
else if (z < x)
    if (z < y) c = 8;
    else c = 9;
else c = 10;

// -----------------------------------------------------------------------------
// (b) -------------------------------------------------------------------------
// Since there are only six possible orderings for the three integers, only six
// of the ten cases can actually occur. Find those that can never occur, and
// eliminate the redundant checks.
// -----------------------------------------------------------------------------

if (x < z)                      // [y x z] or [x z y] or [x y z]
    if (x < y)                  // [x z y] or [x y z]
        if (y < z) c = 1;       // [x y z] *
        else c = 2;             // [x z y] *
    else if (y < z) c = 3;      // [y x z] *
//    else c = 4;                 // [x z y] <- redundant
else if (x < y) c = 6;                 // [z x y] <- only possible answer
    // if (x < z) c = 5;           // <- impossible
    // else c = 6;                 // [z y x] *
else if (y < z) c = 7;          // [y z x] *
else if (z < x) c = 8;                 // [z y x] <- only possible answer
    // if (z < y) c = 8;           // [z y x] *
    // else c = 9;                 // <- impossible
else c = 10;                    // <- all equal

// redundant checks eliminated:
if (x < z && x < y)
    if (y < z) c = 1;       // *[xyz]
    else c = 2;             // *[xzy]
else if (y < z && y < x)
    if (x > z) c = 3;       // *[yzx]
    else c = 4;             // *[yxz]
else if (z < x && z < y)
    if (x > y) c = 5;       // *[zyx]
    else c = 6;             // *[zxy]
else c = 10;

// -----------------------------------------------------------------------------
// (c) -------------------------------------------------------------------------
// Write a simpler, shorter statement that accomplishes the same result.
// -----------------------------------------------------------------------------
// =============================================================================

// gets the relative order of three numbers, prioritizes order xyz when equal.
// If all equal, will be same result as xyz.
if (x <= y && y <= z) c = 1;
else if (x <= z && z <= y) c = 2;
else if (y <= x && x <= x) c = 3;
else if (y <= z && z <= x) c = 4;
else if (z <= x && x <= y) c = 5;
else if (z <= y && y <= x) c = 5;

// =============================================================================
// (4) The following C function calculates the cube root of a real number (by
// the Newton approximation), using the fact that, if y is one approximation to
// the cube root of x, then
//
//                          z = (2y + (x / y^2)) / 3
//
// is a closer approximation.
//
doube fcn(double stuff)
{ double april, tim, tiny, shadow, tom, tam, square;
bool flag;
tim = stuff; tam = stuff; tiny = 0.00001;
if (stuff != 0) do { (shadow = tim + tim;
square = tim * tim;
tom = (shadow + stuff / square);
april = tom / 3;
if (april * april * april - tam > -tiny)
if (april * april * april - tam < -tiny) flag = true;
else flag = false; else flag = false;
if (flag == false) tim = april; else tim = tam; }
while (flag == false);
if (stuff == 0) return(stuff); else return(april); }
//
// -----------------------------------------------------------------------------
// (a) -------------------------------------------------------------------------
// Rewrite the function with meaningful variable names, without the extra
// variables that contribute nothing to the understanding, with a better layout,
// and without the redundant and useless statements.
// -----------------------------------------------------------------------------

double cube_root(double x)
{ 
    double z, y, limit, check;
    bool flag;

    y = x; 
    limit = 0.00001;

    if (x != 0) do
    {
        // Newton iteration
        z = ((y + y) + (x / (y * y))) / 3;

        // how close are we?
        check = z * z * z - x;

        // if close enough, get ready to break
        if (-limit < check && check < limit) flag = true;

        // if not, go again
        y = z;
    }
    while (flag == false);

    return (x == 0) ? x : y;
}

// -----------------------------------------------------------------------------
// (b) -------------------------------------------------------------------------
// Write a function for calculating the cube root directly from the mathemetical
// formula, by starting with the assignment of y = x then repeating
//
//                          y = (2 * y + x / (y * y)) / 3
//
// until fabs(y * y * y - x) = 0.0001.
// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
// (c) -------------------------------------------------------------------------
// Which of these tasks is easier?
// -----------------------------------------------------------------------------
// =============================================================================

// =============================================================================
// (5) The mean of a sequence of real numbers is their sum divided by the count
// of numers in the sequence. The (population) variance of the sequence is the
// mean of the squares of all numbers in the sequence, minus the square of the
// mean of the numbers of the sequence. The standard deviation is the square
// root of the variance. Write a well structured C function to calculate the
// standard deviation of a sequence of n numbers, where n is a constant and the
// numbers are in an array indexed from 0 to n - 1, where n is a parameter of
// the function. Write, then use subsidiary functions to calculate the mean and
// variance.
// =============================================================================

// =============================================================================
// (6) Design a program that will plot a given set of points on a graph. The
// input to the program will be a text file, each line of which contains two
// numbers that are the x and y coordinates of a point to be plotted. The
// program will use a routine to plot one such pair of coordinates. The details
// of the routine involve the specific method of plotting and cannot be written
// since they depend on the requirements of the plotting equipment, which we do
// not know. Before plotting the points the programs needs to know the maximum
// and minimum values of x and y that appear in its input file. The program
// should therefore use another routine called bounds that will read the whole
// file and determine these four maxima and minima. Afterward, another routine
// is used to draw and label the axes, then the file can be reset and the
// individual points plotted.
// -----------------------------------------------------------------------------
// (a) -------------------------------------------------------------------------
// Write the main program, not including the routines.
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// (b) -------------------------------------------------------------------------
// Write the bounds function
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// (c) -------------------------------------------------------------------------
// Write the header lines for the remaining functions together with appropriate
// documentation showing their purposes and their requirements.
// -----------------------------------------------------------------------------
// =============================================================================
