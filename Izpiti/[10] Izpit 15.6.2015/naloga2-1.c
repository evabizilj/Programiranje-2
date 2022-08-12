#include <stdio.h>
#include <stdlib.h>

int rnd(int n)
{
	return (75 * n) % 65537;
}

int function(int i, int j, int x)
{
	if (i == 0 && j == 0) 
		return rnd(1);
	else if (i == 0 && j > 0) 
		return rnd(function(x - 1, j - 1, x));
	return rnd(function(i - 1, j, x));
}

int main()
{
	int x, y, m, s, i, j, k, l, a, b, result = 0;
	scanf("%d %d %d %d", &x, &y, &m, &s);

	int **t1 = (int**) malloc(x * sizeof(int*));
	int *t2 = (int*) malloc(s * s * sizeof(int));
	
	for (i = 0; i < x; i++)
	{
		t1[i] = (int*) malloc(y * sizeof(int));
		for (j = 0; j < y; j++)
			t1[i][j] = function(i, j, x) % m;
	}

	for (i = 0; i < x - s + 1; i++)
	{
		for (j = 0; j < y - s + 1; j++)
		{
			a = 0;
			for (k = i; k < i + s; k++)
			{
				for (l = j; l < j + s; l++)
					t2[a++] = t1[k][l];
			}
			b = 0;
			for (k = 0; k < s * s; k++)
			{
				for (l = k + 1; l < s * s; l++)
				{
					if (t2[k] == t2[l])
					{ 
						b = 1; 
						break; 
					}
				}
				if(b) 
					break;
			}
			if(b) 
				continue;
			result++;
		}
	}
	printf("%d\n", result);
	return 0;
}

// gcc -std=c99 -pedantic -Wall -o asd asd.c -lm
// ./asd < input-1