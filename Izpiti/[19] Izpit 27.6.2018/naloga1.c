#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main()
{
    char ch;
    int n;
    // preberemo še presledek
    scanf("%d ", &n);

    int razdalje = 0;
    int stPlusov = 0;
    int* plusi = (int* ) malloc(stPlusov * sizeof(int));
    int j = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%c", &ch);
        if (ch == '+')
        {
            stPlusov++;
            plusi[j] = i;
            j++;
            int* tmp = (int* ) realloc(plusi, sizeof(int) * (stPlusov));
            plusi = tmp;
        }
    }

    for (int i = 0; i < stPlusov - 1; i++)
        razdalje += plusi[i + 1] - plusi[i];
       // printf("%d - %d = %d\n", plusi[i + 1], plusi[i], razdalje);

    printf("%d\n", razdalje / (stPlusov - 1));
    
    return 0;
}