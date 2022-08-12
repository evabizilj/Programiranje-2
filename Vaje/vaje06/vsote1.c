/*
Program, ki prebere števili n in k in izpiše, na koliko načinov lahko število n zapišemo 
kot vsoto števil med 1 in vključno k. 

Vsota nenegativnih števil, pri katerih je največji sumand enak kvečjemu <k>.
@result: število načinov
@vsota: n
@maxStevilo: k

*/

#include <stdio.h>

// brez memoizacije (neucinkovita rekurzivna rešitev)
long nacini1(int vsota, int maxStevilo)
{
    /*
        vrednost vrnemo takrat, ko smo v listih --> celotno drevo se mora sešteti kot je treba
        ciljna vsota enaka 0 (člene sešteli točno v ciljno vsoto) --> našli 1 primer
    */

    // našli resitev
    if (vsota == 0)
        return 1;
    
    // nismo našli rešitve (in je v tej veji tudi ne bomo)
    if (vsota < 0 || maxStevilo <= 0)
        return 0;
        
    // 2 - razbitje problemov na podprobleme (vejanje)
    
    // 2.1 - število načinov, kjer bomo v tem koraku vključili k oz. največji sumand
    // če smo k vključili, zmanjšamo ciljno vsoto za naslednje primere ter pošljemo še 1xkrat k (npr. 7: k uporabljen 3x)
    long vsebujeK = nacini1(vsota - maxStevilo, maxStevilo); 
  
    // 2.2 - število načinov, kjer k-ja oz. največjega sumanda v tem koraku ne uporabimo
    // k zmanjšamo, ker nima smisla poskušati z enim in istim, če ga ne bomo uporabjali (npr. namesto 5 uporabimo 4)
    long brezK = nacini1(vsota, maxStevilo - 1); 

    // 3 - sestavimo rešitev
    return (vsebujeK + brezK);
}

// uporaba memoizacije
// MEMO[v][s] = že izračunana vrednost funkcije nacini(v, s)
// oz. 0, če vrednosti funkcije pri teh parametrih še nismo izračunali
long memo[500][500]; // pripravimo tabelo --> shranimo vrednosti, ki smo jih že izračunali (da ne računamo ene stvari večkrat)
long nacini2(int vsota, int maxStevilo)
{
    if (vsota == 0)
        return 1;

    if (vsota < 0 || maxStevilo <= 0)
        return 0;
    
    // preverimo, ali smo vrednost funkcije nacini(ciljnaVsota, najvecjiSumand) že izračunali; če smo jo, jo kar uporabimo
    if (memo[vsota][maxStevilo] != 0)
        return memo[vsota][maxStevilo]; // to izračunala že neka druga veja

    // problema nismo rešili (še vedno 0 --> nismo še nič izračunali) --> izvajamo kot, da nimamo memoizacije
    else
    {
        // shranimo za klice (sosedne veje; levo oz. desno)
        // pravkar izračunano vrednost funkcije nacini(ciljnaVsota, najvecjiSumand) shranimo v memoizacijsko tabelo, da nam je ne bo treba
        // še enkrat računati
        memo[vsota][maxStevilo] = nacini2(vsota - maxStevilo, maxStevilo) + nacini2(vsota, maxStevilo - 1);
        return memo[vsota][maxStevilo];
    }
}

int main()
{
    int vsota, maxStevilo;
    scanf("%d %d", &vsota, &maxStevilo);
    printf("%ld %ld\n", nacini1(vsota, maxStevilo), nacini2(vsota, maxStevilo));
}

/*

Na vsakem nivoju rekurzije obravnavamo 2 možnosti:
(1) maxStevilo dodamo v vsoto; v tem primeru ga dodamo v tabelo
(2) maxStevila ne dodamo v vsoto


Pomembne stvari
    - ustavitveni pogoj, ki ga ponavadi ne napišemo čisto na začetku
    - kako razbijamo problem na podprobleme
    - kako združimo in kaj vrnemo
    - spet 1. - naredimo ustavitveni pogoj

Delovanje rekurzije
Rekurzija se razveja v drevo vseh možnosti:
Recimo, za vsota = 7 in k = 5

Na 1. nivoju imamo 2 možnosti vejitve:
- nacini(2, 5): uporabimo 5 enkrat, sedaj moramo sestaviti še seštevek za 2
- nacini(7, 4): 7 nismo uporabili (in je ne bomo), še vedno iščemo seštevek za 7 in poskusimo z uporabo k = 4.
Vsaka izmed teh klicev gre potem spet na 2 dela.

MEMOIZACIJA
Zakaj so timeoutali nacini1.
Npr. število 7.
Narišemo, kako se razvija drevo (na vrhu imamo 100 in želimo sešteti števila do 20).
Imamo veliko možnosti, kako pridelamo število 7. Velikokrat se srečamo s podproblemom, ki smo ga že rešili.
Rešitev je memoizacija (memoizacija vrednosti).
Hranimo jih v eni tabeli, ki nam pove za kakšno vsoto in pri kakšnem največjem k-ju smo to že izračunali.

Ni zadosti npr. število 100 ali številka 7, ampak nas bo zanimala številka 7 pri k = 4, k = 3 ... za vse možnosti potrebujemo rešitve -->
potrebujemo 2D tabelo.

Potrebujemo tabelo, kjer bomo hranili vse možnosti.
Shranimo vrednosti, ki smo jih že izračunai, da jih ne računamo še enkrat.
Mesto v tabeli z indeksom 1 bo prazno.

Pridemo do npr. vozlišča 7,5.
Imamo levo (vsebujeK) in desno stran (neVsebujeK). Dobimo rešitev za L in D. In nato rešitev zapišemo
v tabelo.
(8, 4)
Na mesto 8 zapišemo rešitev.
Ko bo neka druga opcija prišla do tega vozlišča, bo pogledala, če je na tem mestu, kaj večjega od 0.
Če je kaj večjega od 0, potem je ena izmed prejšnjih vozlišč, že izračunala vrednost.
Ne moremo pisati samo npr. za 7, ker imamo lahko več k-jev (z najvišjo vrednostjo členov npr. 5, 4).
Shranimo za vsak par, ne samo za vsoto:
npr. 7 lahko sestavimo na več načinov; množica vseh števil, ki jih imamo na voljo
*/
