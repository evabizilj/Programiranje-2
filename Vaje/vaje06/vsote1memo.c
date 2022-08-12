#include <stdio.h>
#include <stdlib.h>

#define SIZE 400

long **createTable(int size)
{
    long **memo = (long **) malloc(size * sizeof(long *));
    for (int i = 0; i < size; i++)
        memo[i] = (long *) calloc(size, sizeof(long)); 
    return memo;
}


long nacini(int ciljnaVsota, int k, long **memo)
{
    if (ciljnaVsota <= 0 || k <= 0) {
        return (ciljnaVsota == 0) ? 1 : 0;
    }

    if (memo[ciljnaVsota][k] > 0)
        return memo[ciljnaVsota][k]; 

    long vsebujeK = nacini(ciljnaVsota - k, k, memo); 
    long brezK = nacini(ciljnaVsota, k - 1, memo); 
  
    memo[ciljnaVsota][k] = vsebujeK + brezK;

    return memo[ciljnaVsota][k];
}

int main()
{
    int ciljnaVSota, k;
    scanf("%d %d", &ciljnaVSota, &k);

    long **memo = createTable(SIZE + 1); // SIZE + 1 (mesto v tabeli z indeksom 0 bo prazno --> enostavnejše)

    // tabelo memo pošlejemo funkciji načini (ta funkcija piše v to tabelo vrednosti in se jih podaja med posameznimi klici)
    // ta tabela bo narejena samo 1xkrat --> vsak izmed klicev načini si bo podajal samo reference na to tabelo
    long stNacinov = nacini(ciljnaVSota, k, memo);
    printf("%ld\n", stNacinov);

    // 3 - clean-up (tabela na heap --> free)
    for (int i = 0; i < SIZE + 1; i++)
        free(memo[i]); // vse tabele na 2. nivoju
    free(memo);

    return 0;
}