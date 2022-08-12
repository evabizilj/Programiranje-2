
/*
Naivna iterativna rešitev naloge Problem nahrbtnika 2, ki tvori vse
podmnožice, vsako posebej preveri in sproti vzdržuje optimum.
*/

#include <stdio.h>
#include <stdlib.h>

/*
Vrne ceno optimalnega nahrbtnika prostornine vNah.
 * stPredmetov: število vseh predmetov
 * prostornine: prostornine vseh predmetov
 * cene: cene vseh predmetov
*/

int poisci(int stPredmetov, int* prostornine, int* cene, int vNah) {
    int najCena = 0;
    int stMnozic = 1 << stPredmetov;    // = (2 na stPredmetov)

    /*
        Tvorimo vsa števila od 0 do (stMnozic - 1).  Vsako število pretvorimo
        v dvojiški sistem; rezultat pretvorbe predstavlja eno od podmnožic.
        Na primer, če je stPredmetov == 5, potem število 13 (= 01101 po
        dvojiško) predstavlja podmnožico, ki vsebuje predmete z indeksi 1, 2
        in 4.
    */

    for (int m = 0;  m < stMnozic;  m++) {
        int mnozica = m;
        int i = 0;
        int cena = 0;
        int prostornina = 0;
        int stLihih = 0;

        /*
            Število <mnozica> pretvorimo v dvojiški sistem.  Med pretvorbo
            računamo skupno prostornino in ceno pripadajoče podmnožice in
            štejemo predmete z liho prostornino.
        */

        while (mnozica > 0) {
            if (mnozica % 2 == 1) {
                cena += cene[i];
                prostornina += prostornine[i];
                stLihih += prostornine[i] % 2;
            }
            i++;
            mnozica /= 2;
        }

        if (prostornina <= vNah && stLihih <= 1 && cena > najCena) {
            // podmnožica izpolnjuje pogoje in ima poleg tega še večjo
            // skupno ceno od doslej najdražje podmnožice
            najCena = cena;
        }
    }
    return najCena;
}

int main() {
    int vNah;
    scanf("%d", &vNah);

    int stPredmetov;
    scanf("%d", &stPredmetov);

    int* prostornine = malloc(stPredmetov * sizeof(int));
    for (int i = 0;  i < stPredmetov;  i++) {
        scanf("%d", &prostornine[i]);
    }

    int* cene = malloc(stPredmetov * sizeof(int));
    for (int i = 0;  i < stPredmetov;  i++) {
        scanf("%d", &cene[i]);
    }

    int najCena = poisci(stPredmetov, prostornine, cene, vNah);
    printf("%d\n", najCena);

    free(prostornine);
    free(cene);

    return 0;
}
