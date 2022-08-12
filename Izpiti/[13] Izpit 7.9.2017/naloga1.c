#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    int prejsnje;
    int trenutno;

    scanf("%d", &prejsnje);

    while (scanf("%d", &trenutno) != EOF)
    {
        if (prejsnje > 0 && trenutno < 0)
            printf("%d\n", prejsnje);
        else if (prejsnje < 0 && trenutno > 0)
            printf("%d\n", prejsnje);
        prejsnje = trenutno;
    }
    printf("%d\n", prejsnje);
    return 0;
}
