
/*
Iterativna rešitev

Ta rešitev izhaja iz rešitve vsote1memo.c.  
Namesto da bi memoizacijsko tabelo polnili glede na potek rekurzivne funkcije, 
jo sistematično polnimo po vrsticah in stolpcih.  
Ker v splošnem velja nacini(v, s) = nacini(v - s, s) + nacini(v, s - 1),
velja tudi
MEMO[v][s] = MEMO[v - s][s] + MEMO[v][s - 1]
Po tej formuli (oziroma po njeni različici, ki upošteva, da je 
MEMO[v - s][s] = MEMO[v - s][v - s], kadar je v - s < s) računamo
vrednosti v memoizacijski tabeli.

*/

#include <stdio.h>
#include <stdlib.h>

#define MIN(x, y) (((x) < (y)) ? (x) : (y))

void napolni(long** din, int ciljnaVsota, int najSumand) {
    din[0][0] = 1;
    for (int i = 1;  i <= ciljnaVsota;  i++) {
        din[i][0] = 0;
        int meja = MIN(i, najSumand);
        for (int j = 1;  j <= meja;  j++) {
            din[i][j] = din[i - j][MIN(j, i - j)] + din[i][j - 1];
        }
    }
}

/*
Vrne število načinov, da število <ciljnaVsota> zapišemo kot vsoto, v
kateri je največji sumand enak kvečjemu <najvecjiSumand>.
*/

int main() {
    int ciljnaVsota, najSumand;
    scanf("%d%d", &ciljnaVsota, &najSumand);

    // inicializiramo memoizacijsko tabelo
    long** din = malloc((ciljnaVsota + 1) * sizeof(long*));
    for (int i = 0;  i <= ciljnaVsota;  i++) {
        din[i] = malloc((najSumand + 1) * sizeof(long));
    }

    // sistematično (po vrsticah in stolpcih) napolnimo memoizacijsko tabelo
    napolni(din, ciljnaVsota, najSumand);

    // iskani element je v desnem spodnjem kotu
    printf("%ld\n", din[ciljnaVsota][najSumand]);

    // počistimo alocirani prostor
    for (int i = 0;  i <= ciljnaVsota;  i++) {
        free(din[i]);
    }
    free(din);
    return 0;
}
