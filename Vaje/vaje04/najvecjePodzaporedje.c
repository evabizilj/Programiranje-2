#include <stdio.h>
#include <limits.h>

int main() {
    int dolzinaZaporedja;
    scanf("%d", &dolzinaZaporedja);

    /* Spremenljivka <vsota> hrani tekočo vsoto, tj. vsoto členov od začetka zaporedja oziroma zadnjega preloma do trenutnega člena.
       Prelom se zgodi, ko tekoča vsota pade pod 0.  
       Takrat vemo, da trenutnega podzaporedja (= podzaporedja od začetka zaporedja oz. zadnjega preloma do trenutnega člena) nima 
       več smisla podaljševati, zato začnemo z novim podzaporedjem in tekočo vsoto postavimo na 0.
    */

    int vsota = 0;

    // doslej največja vsota
    int najVsota = INT_MIN;

    for (int i = 0; i < dolzinaZaporedja; i++)
    {
        int clen;
        scanf("%d", &clen);

        vsota += clen;

        if (vsota > najVsota)
            najVsota = vsota;

        // ni potrebno hraniti negativne vrednosti
        if (vsota < 0)
            // prelom
            vsota = 0;
    }

    printf("%d\n", najVsota);

    return 0;
    
}