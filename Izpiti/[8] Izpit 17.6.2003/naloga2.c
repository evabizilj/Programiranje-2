#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void sort(int* tabela, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (tabela[i] > tabela[j])
            {
                int tmp = tabela[i];
                tabela[i] = tabela[j];
                tabela[j] = tmp;
            }
        }
    }
}

int main()
{
    int n; 
    scanf("%d", &n);

    if (n == 2)
    {
        printf("%d\n", -1);
        return 0;
    }

    int* tabela = (int* ) malloc(100 * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &tabela[i]);
    
    sort(tabela, n);

    printf("%d\n", tabela[1]);


    free(tabela);
    return 0;

}