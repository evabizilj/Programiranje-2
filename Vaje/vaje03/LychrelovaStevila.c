#include <stdio.h>
#include <stdbool.h>
#define MEJA 100000000000000000L

bool isPalindrom(long number);
long reverse(long number);
bool isLychrel(long number, int maxIterations);

int main() 
{
    int maxIteration, upperLimit, lowLimit;

    scanf("%d %d %d", &maxIteration, &lowLimit, &upperLimit);

    int count = 0;
    for (int number = lowLimit; number <= upperLimit; ++number) 
        if (isLychrel(number, maxIteration))
            count++;

    printf("%d\n", count);
    return 0;
}


bool isPalindrom(long number)
{
    return (number == reverse(number));
}

long reverse(long number)
{
    long reversed = 0;
    int digit = 0;
    while (number != 0)
    {
        digit = number % 10;
        reversed = reversed * 10 + digit;
        number /= 10;
    }
    return reversed;
}

bool isLychrel(long number, int maxIterations) 
{
    int i = 0;
    do {
        number = number + reverse(number);
        i++;
    } while (i < maxIterations && number <= MEJA && !isPalindrom(number));

    return !isPalindrom(number);
}