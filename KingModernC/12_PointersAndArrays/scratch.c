#include <stdio.h>
#include <stdbool.h>

#define N 10

bool search(const int *a, int n, int key);
double inner_product(const double *a, const double *b, int n);
int *find_middle(int *a, int n);
int find_largest(int *a, int n);
void find_two_largest(const int *a, int n, int *largest, int *second_largest);

int main(void)
{
    // *p++ = *(p++) -> Value of espression is *p (value), incriment p (address) later
    // (*p)++        -> Value of expression is *p (value), incriment *p (value) later
    // *++p = *(++p) -> Incriment p (address), value is *p (value) one address more
    // ++*p = ++(*p) -> Incriment *p (value), *p (value) + 1 to value pointed by p

    // for an array a:
    // const int a[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    // const int a[10] = { 2, 9, 9, 6, 5, 4, 3, 2, 1, 8 };
    // we can use a for loop like this
    // for (int *p = a; p < a + 10; p++) 
    // {
    //     printf("%d\n", *p);
    // }

    // pointer addition is communative
    // the compiler treats i[a] as *(i + a) which is the same as *(a + i)
    // for (int i = 0; i < 10; i++)
    //     printf("%d ", i[a]);
    // puts("");
   
    // int l;
    // int s;
    // find_two_largest(a, 10, &l, &s);
    // printf("Largest = %d\nSecond largest = %d\n", l, s);


    // double id_matrix[N][N];
    // int i = 0;
    //
    // for (double *aptr = &id_matrix[0][0]; aptr < &id_matrix[0][0] + N * N; aptr++)
    // {
    //     if (aptr == id_matrix[i] + i)
    //     {
    //         *aptr = 1.0;
    //         i++;
    //     }
    //     else 
    //     {
    //         *aptr = 0.0;
    //     }
    // }
    //
    //
    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < N; j++)
    //     {
    //         printf(" %lf ", id_matrix[i][j]);
    //     }
    //     puts("");
    // }
        


    return 0;
}

bool search(const int *a, int n, int key)
{
    for (const int *p = a; p < a + n; p++)
    {
        if (*p == key) return true;
    }
    return false;
}

double inner_product(const double *a, const double *b, int n)
{
    const double *ptr_a;
    const double *ptr_b = b;
    double ans;

    for (ptr_a = a; ptr_a < a + n; ptr_a++)
    {
        ans += *ptr_a * *ptr_b++;
    }
    return ans;
}

int *find_middle(int *a, int n)
{
     return a + n / 2;
}

int find_largest(int *a, int n)
{
    int *p, largest = *a;

    for (p = a + 1; p < a + n; p++)
    {
        if (*p > largest)
            largest = *p;
    }
    return largest;
}

void find_two_largest(const int *a, int n, int *largest, int *second_largest)
{
    int i = 1;
    *largest = *a;
    *second_largest = *a;

    while (i < n)
    {
        if (*(a + i) > *largest)
        {
            *second_largest = *largest;
            *largest = *(a + i);

        }
        else if (*(a + i) > *second_largest && *(a + i) != *largest)
        {
            *second_largest = *(a + i);
        }
        i++;
    }
}
