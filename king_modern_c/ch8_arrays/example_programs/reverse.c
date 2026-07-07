//==============================================================================
// Reverses a series of numbers
// C Programming: A Modern Approach 2nd Edition - K.N. King
// Page 164
//==============================================================================
#include <stdio.h>

#define N 10

int main(void) {

    int a[N], i;

    printf("Enter %d numbers: ", N);
    for (i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    printf("In reverse order:");
    for (i = N - 1; i >= 0; i--) {
        printf(" %d", a[i]);
    }
    puts("");

    return 0;
}
