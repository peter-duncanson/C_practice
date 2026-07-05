#include <stdio.h>

void ex1() {
    //1 2 4 8 16 32 64 128
    int i = 1;
    while (i <= 128) {
        printf("%d ", i);
        i *= 2;
    }
}

void ex2() {
    // 9384 938 93 9 
    int i = 9384;
    do {
        printf("%d ", i);
        i /= 10;
    } while (i > 0);
}

void ex3() {
    // 5 4 3 2 
    int i, j;
    for (i = 5, j = i - 1; i > 0, j > 0; --i, j = i - 1)
        printf("%d ", i);
    //     printf("i = %d j = %d\n", i, j);
    // printf("i = %d j = %d\n", i, j);
}

void ex4() {
    // c is different
    // a
    for (int i = 0; i < 10; i++) {
        printf("%d ", i);
    }
    puts("\n");

    // b
    for (int i = 0; i < 10; ++i) {
        printf("%d ", i);
    }
    puts("\n");

    // c
    for (int i = 0; i++ < 10; ) {
        printf("%d ", i);
    }
    puts("\n");
}

void ex5() {
    // the do-while loop is distinct from the others, even though as written
    // the output will be the same. Just because it will always run at least
    // once regardless of the value of i
    int i = 0;
    while (i < 10) {
        printf("%d ", i);
        i++;
    }
    puts("\n");

    i = 0;
    for (; i < 10;) {
        printf("%d ", i);
        i++;
    }
    puts("\n");

    i = 0;
    do {
        printf("%d ", i);
        i++;
    } while (i < 10);
    puts("\n");
}

void ex6() {
    // ex1 translated into a for loop
    for (int i = 1; i <= 128; i *= 2) {
        printf("%d ", i);
    }
    puts("\n");
}

void ex7() {
    // ex2 translated into a for loop
    // 9384 938 93 9
    for (int i = 9384; i > 0; i /= 10) {
        printf("%d ", i);
    }
    puts("\n");
}

void ex8() {
    // 10 5 3 2 1 1 1 ....infinite
    // i will eventually get stuck as 1, since it can never reach 0
    // and break the loop because of the post incriment operator
    // int the printf statement
    for (int i = 10; i >= 1; i /= 2) {
        printf("%d ", i++);
    }
    puts("\n");
}

void ex9() {
    // ex8 translated to a while loop
    int i = 10;
    while(i) {
        printf("%d ", i++);
        i /= 2;
    }
}

void ex11() {
    // sum will be 2 + 4 + 6 + 8 = 20
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        if (i % 2) {
            continue;
        }
        sum += i;
    }
    printf("%d\n", sum);
}

void ex12() {
    // for (int d = 2; d < n; d++) {
    //     if (n % d == 0) {
    //         break;
    //     }
    // }
    // this loop is inefficient, we dont have to divide n by all numbers
    // between 2 and n-1 to determine if it is prime. we only need to check
    // divisors up to the square root of n.
    int i;
    int j;
    printf("Enter number for prime check: ");
    scanf("%d", &j);
    for (i = 2; (i * i) < j; i++) {
        if (j % i == 0) {
            printf("%d is divisible by %d\n", j, i);
            return;
        }
    }
    printf("%d is prime\n", j);
}

void ex13() {
    // rewrite the loop so the body is empty
    int i, j;
    // for (i = 0; j > 0; i++)
    //     j /=2;

    // this is equivalent but
    // for (i = 0; j > 0; i++, j /= 2);
    // this is also equivalent and probably better
    for (i = 0; j > 0; j /= 2, i++);
    // since it preserves the order of operations of the original
}

void ex14() {
    // find the error and fix it
    int n = 500;
    // if (n % 2 == 0);
    //     printf("n is even\n");
    // the problem with this is that the conditional is a null statement.
    // the semicolon creates an empty body after the condition
    // this will cause the message to always get printed, since the 
    // print statement is no longer bound to the conditional!
    // the fix:
    if (n % 2 == 0) {
        printf("n is even\n");
    }
}

int main() {
    return 0;
}

