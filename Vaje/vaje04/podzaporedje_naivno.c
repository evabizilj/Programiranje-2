
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAKS_DOLZINA 1000000

// tabele ne smemo ustvariti znotraj funkcije (sklad!)
int zaporedje[MAKS_DOLZINA];

int main() {
    int dolzina;
    scanf("%d", &dolzina);

    // doslej največja vsota 
    int najVsota = INT_MIN;

    // preberemo zaporedje v tabelo
    for (int i = 0;  i < dolzina;  i++) {
        scanf("%d", &zaporedje[i]);
    }

    // za vsako podzaporedje izračunamo vsoto in vzdr"zujemo dosedanji maksimum vsote

    for (int i = 0;  i < dolzina;  i++) {
        // izračunamo vsote podzaporedij t[i..i], t[i..i+1], ..., t[i..n-1]
        // in vsakokrat posodobimo dosedanji maksimum

        int vsota = 0;
        for (int j = i;  j < dolzina;  j++) {
            vsota += zaporedje[j];
            if (vsota > najVsota) {
                najVsota = vsota;
            }
        }
    }

    printf("%d\n", najVsota);
    return 0;
}
