#include <stdio.h>
#include <stdlib.h>
#define g 10000

int main()
{
	int n, glm = 1000, size = 0, tmp, *t = (int*) malloc(glm * sizeof(int)), *e = (int*) malloc(glm * sizeof(int));
	unsigned char znak; 
	char name[110];

	scanf("%s", name);
	scanf("%d", &n);

	FILE* f1 = fopen(name, "rb");
	
	while ((fscanf(f1, "%c", &znak)) != EOF)
	{
		tmp = 0;
		for (i = 0; i < size; i++)
			if (znak == t[i])
			{
				tmp=1; 
				e[i]++;
			}
		if (tmp) 
			continue;
		
		t[size] = znak; 
		e[size] = 1; 
		size++;
		if (size >= glm)
		{
			glm += g;
			t = (int*) realloc(t, glm * sizeof(int));
			e = (int*) realloc(e, glm * sizeof(int));
		}
	}
	
	for (int i = 0; i < size; i++)
		for (int j = i + 1; j < size; j++)
			if (e[i] < e[j])
			{
				tmp = e[i];
				e[i] = e[j];
				e[j] = tmp;
				tmp = t[i];
				t[i] = t[j];
				t[j] = tmp;
			}
	printf("%d\n", e[n - 1]);

	return 0;
}

// gcc -std=c99 -pedantic -Wall -o c123 c.c -lm
// ./c123 < inp-en1