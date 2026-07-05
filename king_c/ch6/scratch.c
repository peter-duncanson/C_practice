#include <stdio.h>

int main() {
    int i = 20;
    while (i > 10) {
        --i;
        printf("%d\n", i);
    }
    printf("%d\n", i);
    // int i;
    // int j = 33;
    // for (i = 2; i < j && j % i != 0; i++);
    // if (i < j) {
    //     printf("%d is divisible by %d\n", j, i);
    // }
    return 0;
}
