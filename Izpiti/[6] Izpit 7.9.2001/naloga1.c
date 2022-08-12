#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <ctype.h>

int main()
{
    char znak;
    int* pojavitve = (int* ) calloc(26, sizeof(int));

    while ((znak = getchar()) != EOF)
    {
        if (znak != '\n')
        {
            if (isalpha(znak))
                pojavitve[tolower(znak) - 'a']++;
        }
        else
        {
            for (int i = 0; i < 26; i++)
            {
                if (pojavitve[i] != 0)
                    printf("%c: %d\n", 'a' + i, pojavitve[i]);
                pojavitve[i] = 0;
            }
        }
    }

    free(pojavitve);
    return 0;
}
