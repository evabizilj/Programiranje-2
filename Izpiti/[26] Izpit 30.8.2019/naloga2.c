
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main() 
{
    int n;
    scanf("%d ", &n);
    char* vhod = (char* ) malloc(n * sizeof(char));

    int max = 0;
    int trenutno = 0;

    for (int i = 0; i < n; i++) 
    {
        scanf("%c", &vhod[i]);
        if (vhod[i] == 'G') 
        {
            trenutno++;
            if (trenutno > max) 
                max = trenutno;
        }
        else if (vhod[i] == 'D') 
            trenutno--;
    }

    char pravokotnik[max][n];

    for (int i = 0; i < max; i++) 
    {
        for (int j = 0; j < n; j++) 
            pravokotnik[i][j] = '.'; 
    }

    int vrstica = max - 1;
    for (int i = 0; i < n; i++) 
    {
        char trenutna = vhod[i];
        if (trenutna == 'G') 
        {
            pravokotnik[vrstica][i] = '/';
            vrstica--;
        }
        else if (trenutna == 'D') 
        {
            vrstica++;
            pravokotnik[vrstica][i] = '\\';
        }
    }

    for (int i = 0; i < max; i++) 
    {
        for (int j = 0; j < n; j++) 
            printf("%c", pravokotnik[i][j]);
        printf("\n");
    }

    return 0;
}
