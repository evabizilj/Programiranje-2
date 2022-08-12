#include <stdio.h>
int divisors(int n);

int main() 
{
    int n;
    scanf("%d", &n);

    int second = divisors(n);

    if (n == divisors(second) && n != second)
        printf("%d\n", divisors(n));
    else
        printf("NIMA\n");
}

int divisors(int n) 
{
    int sum = 0;
    for (int i = 1; i < n / 2 + 1; ++i)
        if (n % i == 0)
            sum += i;
    return sum;
}

