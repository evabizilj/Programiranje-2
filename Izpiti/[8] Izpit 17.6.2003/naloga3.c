#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char** argv)
{
    FILE* vhod = fopen(argv[1], "rt");

    int* pojavitve = (int* ) calloc(100, sizeof(int));

    char znak;
    char znakec;

    while (fscanf(vhod, "%c", &znak) == 1)
    {
        if (isalpha(znak))
            pojavitve[tolower(znak) - 'a']++;
    }

    for (int i = 0; i < 100; i++)
    {
        if (pojavitve[i] != 0)
            printf("%c = %d \n", i + 'a', pojavitve[i]);
    }

    return 0;

}