#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>


void izpisiGeslo(char* geslo, int dolzina, int i, int stCrk, int stZnakov)
{
    // pridemo do i-te dolžine
    if (i == dolzina)
    {
        // pogoj je, da je vsota črk enaka vsoti znakov
        if (stCrk == stZnakov)
            printf("%s\n", geslo);
        return;
    }

    // geslo je lahko sestavljeno iz znakov
    for (int c = 'a'; c <= 'z'; c++)
    {
        geslo[i] = c;
        izpisiGeslo(geslo, dolzina, i + 1, stCrk, stZnakov + 1);
    }

    // geslo je lahko sestavljeno iz števk
    for (int s = '0'; s <= '9'; s++)
    {
        geslo[i] = s;
        izpisiGeslo(geslo, dolzina, i + 1, stCrk + 1, stZnakov);
    }
}

int main()
{
    char* geslo;

    // sprehodimo se po dolžini gesla (za vsako dolžino izpišemo vsa možna gesla)
    for (int dolzina = 8; dolzina <= 20; dolzina++)
    {
        geslo = (char *) malloc(dolzina * sizeof(char));
        izpisiGeslo(geslo, dolzina, 0, 0, 0);
    }

    return 0;
}