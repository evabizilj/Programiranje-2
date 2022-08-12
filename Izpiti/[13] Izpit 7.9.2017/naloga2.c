#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char intToChar(int n)
{
    return n + '0';
}

char charToInt(char c)
{
    return c - '0';
}

char* division(char* number, int divisor) 
{
    int numberLenght = strlen(number);
    char* answer = (char*) calloc(numberLenght, sizeof(char));
    char* answerPos = answer;

    int buff = 0;
    for (char* digit = number; *digit != 0; ++digit)
    {
        buff = buff * 10 + charToInt(*digit);

        if (buff >= divisor)
        {
            int div = buff / divisor;
            buff = buff % divisor;
            *answerPos = intToChar(div);
            ++answerPos;
        }
        else if (buff == 0)
        {
            *answerPos = '0';
            ++answerPos;
        }
    }
    return answer;
} 

int main() 
{ 
    char* n = (char*) calloc(1000000, sizeof(char));
    int k;
    scanf("%s %d", n, &k);
    printf("%s\n", division(n, k));
	return 0; 
} 
