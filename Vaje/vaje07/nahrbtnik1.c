#include <stdio.h>
#include <stdlib.h>

#define MAX_PROSTORNINA 1000
int memo[1001][1001];

/*
Vrne ceno optimalnega nahrbtnika

@result: cene optimalnega nahrbtnika
    1. ustavitveni pogoj
    2. razbijanje problema na podprobleme
    3. združevanje rešitev
*/

int najCena(int prostorninaNahrbtnika, int stPredmetov, int* prostorninaPredmeta, int* cenaPredmeta)
{
    // cene ne moremo vedno izračunati, paziti moramo, da predmet gre v nahrbtnik
    if (prostorninaNahrbtnika < 0)
        return -10000;

    // preizkusimo vse predmete
    if (prostorninaNahrbtnika == 0 || stPredmetov < 0)
        return 0; // začnemo s ceno 0 (odvisno le ali bodo klici, ki so višje v hierarhiji dodajali kakšen element ali ne)

    // memoizacija (koliko elementov imamo pri določenem volumnu)
    if (memo[prostorninaNahrbtnika][stPredmetov])
        return memo[prostorninaNahrbtnika][stPredmetov]; // ena izmed vej je že izračunala to vrednost
    
    // primer 1: ne dodaj trenutnega predmeta v nahrbtnik, premaknemo se naprej 
    int cena1 = 0 + najCena(prostorninaNahrbtnika, stPredmetov - 1, prostorninaPredmeta, cenaPredmeta);
    
    // primer 2: dodaj trenutni predmet v nahrbtnik (cena predmeta + naj polnitev ostalih)
    int cena2 = cenaPredmeta[stPredmetov] + najCena(prostorninaNahrbtnika - prostorninaPredmeta[stPredmetov], stPredmetov - 1, prostorninaPredmeta, cenaPredmeta);
    
    if (cena1 > cena2)
        memo[prostorninaNahrbtnika][stPredmetov] = cena1;
    else
        memo[prostorninaNahrbtnika][stPredmetov] = cena2;

    // memoiziramo ... ko imamo izbrano najboljšo od obeh možnosti (hranimo za prihodnje sotrpine)
    return memo[prostorninaNahrbtnika][stPredmetov];
}

int main() 
{
    int prostorninaNahrbtnika, stPredmetov;
    scanf("%d %d", &prostorninaNahrbtnika, &stPredmetov);

    int* prostorninaPredmeta = (int *) malloc(stPredmetov * sizeof(int));
    int* cenaPredmeta = (int *) malloc(stPredmetov * sizeof(int));

    for (int i = 0; i < stPredmetov; i++)
        scanf("%d", &prostorninaPredmeta[i]);

    for (int i = 0; i < stPredmetov; i++)
        scanf("%d", &cenaPredmeta[i]);

    printf("%d\n", najCena(prostorninaNahrbtnika, stPredmetov, prostorninaPredmeta, cenaPredmeta));
    
    return 0;
}


/*

Imamo nahrbtnik, ki ima nek volumen (določa koliko stvari lahko damo v njega).
Imamo nabor stvari, ki bi jih radi vzeli s sabo.
Vsaka stvar ima svoj volumen in svojo ceno.
Želimo si napolniti nahrbtnik tako, da bodo stvari v njem imele največjo skupno ceno.

Zmanšujemo volumen in se pomikamo po posameznih predmetih.
Vsak korak:
    1. s trenutnim predmetom v nahrbtniku
    2. brez trenutnega predmeta v nahrbtniku

Če imamo metodo napolni, bo ta potrebovala:
prostornine predmetov, cene predmetov, trenutni element, prostornino nahrbtnika (in število vseh predmetov).

Klica:
- napolni (n, volumes, prices, ix + 1, vNah): tukaj nismo dodali predmeta v nahrbtnik, prostornina nahrbtnika ostaja
enaka, mi pa se pomaknemo na naslednji predmet
- cena[ix] + napolni(n, volumes, prices, ix + 1, vNah - volumes[ix]) ... iščemo ceno --> povečamo ceno in zmanjšamo volumen.

Pri prvem klicu nismo (v trenutnem koraku) niti povečali cene niti zmanjšali volumna.

Sprehodimo se po stvarah, imamo 2 možnosti:
- stvar damo v nahrbtnik (v njem je še dovolj prostora - ne sme preseči volumna le tega, skupna cena se poveča)
- stvar ne damo nahrbtnik

Rekurzija se konča, ko smo "poskusili" vse stvari torej smo z indeksom prišli do n-ja.

Ceno vrača rekurzija. 
Imamo drevo z dvema variantama: dodamo predmet, ne dodamo predmeta --> izberemo, kje je cena večja
(maksimum dveh cen)

Predstavljamo si lahko kot drevo. 
Cene imamo v eno in v drugo stran z predmetov ali brez (levo ali desno poddrevo).

Naša funkcija sešteva cene predmetov takrat ko se sprehajamo po stacku nazaj gor.
Predstavljamo si lahko, da gremo po drevesu od spodaj navzgor in vedno vzamemo tisto vejo,
ki ima večjo ceno.

V bistvu začnemo želeno vrednost dobivati, ko pridemo do konca drevesa in se premikamo nazaj gor
do prvotnega klica, ki dobljeno želeno vrednost returna v main.

V listih drevesa so "konci" rekurzije, pot od začetka do konca pa so različne
kombinacije predmetov.

Preveriti moramo vse možne kombinacije --> hitro se razveja --> uporaba memoizacije.
*/


