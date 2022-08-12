#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
MEMO[ix][zeDodaliLiho][vNah]: že izračunana vrednost funkcije
poisci(..., ix, zeDodaliLiho, vNah) oziroma 0, če te vrednosti še nismo
izračunali
*/

int MEMO[1001][2][1001];

/*
Vrne ceno optimalnega nahrbtnika s (preostalo) prostornino vNah, pri čemer
lahko vanj dodajamo predmete z indeksi od vključno ix naprej (predmete z
nižjimi indeksi smo obravnavali na prejšnjih nivojih rekurzije), poleg
tega pa moramo upoštevati tudi parameter zeDodaliLiho.  
Če ima taparameter vrednost true, potem smo v nahrbtnik že dodali predmet z liho
prostornino (in takega predmeta ne smemo več dodati), sicer pa ga še
nismo (zato tak predmet še lahko dodamo).
 
 * stPredmetov: število vseh predmetov
 * prostornine: prostornine vseh predmetov
 * cene: cene vseh predmetov
 * ix: indeks trenutno obravnavanega predmeta
 * zeDodaliLiho: true natanko v primeru, če nahrbtnik že vsebuje predmet z
                 liho prostornino
 * vNah: preostala prostornina v nahrbtniku

*/

int poisci(int stPredmetov, int* prostornine, int* cene, int ix, bool zeDodaliLiho, int vNah) {
    // nimamo več predmetov, ki bi jih še lahko dodali v nahrbtnik, zato
    // cena takega nahrbtnika (oz. množice predmetov) znaša 0
    if (ix == stPredmetov) {
        return 0;
    }

    // če smo vrednost funkcije poisci(..., ix, zeDodaliLiho, vNah) že
    // izračunali, jo kar vrnemo
    if (MEMO[ix][zeDodaliLiho][vNah] > 0) {
        return MEMO[ix][zeDodaliLiho][vNah];
    }

    // možnost 1: predmeta z indeksom ix ne dodamo v nahrbtnik
    int najCena = poisci(stPredmetov, prostornine, cene, ix + 1, zeDodaliLiho, vNah);

    bool lihaProstornina = (prostornine[ix] % 2 == 1);

    /*
        možnost 2: predmet z indeksom ix dodamo v nahrbtnik, če sta
        izpolnjena sledeča pogoja:
        -- v nahrbtniku je dovolj prostora za ta predmet
        -- predmet ima sodo prostornino ali pa nahrbtnik še ne vsebuje
           predmeta z liho prostornino
    */

    if (prostornine[ix] <= vNah && (!lihaProstornina || !zeDodaliLiho)) {
        // možnost 2: predmet z indeksom ix dodamo v nahrbtnik
        int c = cene[ix] + poisci(stPredmetov, prostornine, cene, ix + 1,
                                  zeDodaliLiho || lihaProstornina, vNah - prostornine[ix]);

        // izberemo boljšo izmed obeh možnosti
        if (c > najCena) {
            najCena = c;
        }
    }

    // memoiziramo
    MEMO[ix][zeDodaliLiho][vNah] = najCena;

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

    int najCena = poisci(stPredmetov, prostornine, cene, 0, false, vNah);
    printf("%d\n", najCena);

    free(prostornine);
    free(cene);

    return 0;
}