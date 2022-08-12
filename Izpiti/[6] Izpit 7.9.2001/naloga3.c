#include <stdio.h>
#include <math.h>

int main()
{
    int tocke[][] = {{10, 5},
                     {0, 10},
                     {3, 55},
                     {7, 9},
                     {0, 0};

    int crte[][] = {{0, 1},
                    {1, 2},
                    {1, 3},
                    {3, 3},
                    {1, 3}};
    
    int x1, y1, x2, y2;
    double dolzina = 0;

    for (int i = 0; i < 5; i++)
    {
        x1 = tocke[crte[i][0]][0];
        y1 = tocke[crte[i][0]][1];
        x2 = tocke[crte[i][1]][0];
        y2 = tocke[crte[i][1]][1];
        dolzina += sqrt((y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1));
    }
    return 0;
}