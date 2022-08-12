// the algorithm is not working properly
#include <stdio.h>
#include <stdlib.h>

int sum = 0;
void mtd(char *c, int index, int n, int m, int d)
{
	if (index == n)
	{
		int i, t = 0, r = 0;
		for (i = 0; i < n; i++)
		{
			if (i + 1 < n && c[i] > c[i + 1])
			{ 
				r++; 
				i++; 
			}
			if (r >= d)
			{ 
				t=1; 
				break; 
			}
		}
		if (t)
		{
			printf("%s\n", c);
			sum++;
		}
		return;
	}
	for (int i = 1; i <= m; i++)
	{
		c[index] = i + '0';
		mtd(c, index + 1, n, m, d);
	}
}

int main()
{
	int n, m, d; 
	scanf("%d %d %d", &n, &m, &d);
	char c[n + 1]; 
	c[n + 1] = '\0';
	mtd(c, 0, n, m, d);
	printf("%d\n", sum);
	return 0;
}
// gcc -std=c99 -pedantic -Wall -o prmt prmt.c -lm
// ./prmt < input-1