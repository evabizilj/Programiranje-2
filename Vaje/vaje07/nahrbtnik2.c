#include <stdio.h>
#include <stdlib.h>

int memo[1001][1001][2];

int najCena (int prostorninaNahrbtnika, int stPredmetov, int nobenNiLih, int *volumenPredmeta, int *cenaPredmeta)
{
    if (prostorninaNahrbtnika < 0)
        return -10000;

    if (prostorninaNahrbtnika == 0 || stPredmetov < 0)
        return 0; 


    if (memo[prostorninaNahrbtnika][stPredmetov][nobenNiLih])
        return memo[prostorninaNahrbtnika][stPredmetov][nobenNiLih];

    // primer 1
    int cena = najCena(prostorninaNahrbtnika, stPredmetov - 1, nobenNiLih, volumenPredmeta + 1, cenaPredmeta + 1);
    int niLih = (volumenPredmeta[0] % 2) == 0;
    int lahkoUporabim = nobenNiLih || niLih;
    // če je dovolj prostora bodisi ni lihe prostornine bodisi nismo še dodali lihega prej 

    if (volumenPredmeta[0] <= prostorninaNahrbtnika && lahkoUporabim)
    {
        // zdaj dodali liho ali pa ze prej dodali liho (nasledniki dobijo opozorili, da ne smejo več dati lihega predmeta)
        int cena2 = cenaPredmeta[0] + najCena(prostorninaNahrbtnika - volumenPredmeta[0], stPredmetov - 1, nobenNiLih && niLih, volumenPredmeta + 1, cenaPredmeta + 1);
        if (cena2 > cena)
            cena = cena2;
    }

    memo[prostorninaNahrbtnika][stPredmetov][nobenNiLih] = cena;
    return cena;
}

int main()
{
    int prostorninaNahrbtnika, stPredmetov;
    scanf("%d %d", &prostorninaNahrbtnika, &stPredmetov);

    int volumenPredmeta[stPredmetov];
    int cenaPredmeta[stPredmetov];

    for (int i = 0; i < stPredmetov; i++)
        scanf("%d", &volumenPredmeta[i]);

    for (int i = 0; i < stPredmetov; i++)
        scanf("%d", &cenaPredmeta[i]);

    printf("%d\n", najCena(prostorninaNahrbtnika, stPredmetov, 1, volumenPredmeta, cenaPredmeta));

    return 0;
}

/*
Tukaj moramo v funkcijo, ki jo kličemo rekurzivno dodati samo še 
preverjanje ali smo že dodali predmet z liho prostornino.
Če smo ga enkrat dodali, ne smemo dodati še enega predmeta z liho prostornino.
main ... enak
štetje elementov ... imamo določeno število lihih elementov
1 element ... boolean
popravi memoizacijo -> 3D tabela

int size = MAX_PROSTORNINA + 1;
int ***memo = (int ***) malloc(size * sizeof(int **));
for (int i = 0; i < size; i++) {
        memo[i] = (int **) malloc(2 * sizeof(int*));
        for (int j = 0; j < 2; j++)
            memo[i][j] = (int *) calloc(size, sizeof(int));
}

clean-up
for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 2; j++)
            free(memo[i][j]);
        free(memo[i]);
    }
free(memo);


        memoizacija: koliko elementov imamo pri določenem volumnu + dodati moramo (število lihih elementov)
        5:10, 2: 10
        5:0:10, 5:1:10

*/


