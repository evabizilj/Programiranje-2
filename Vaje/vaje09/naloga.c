#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Vozlisce Vozlisce;
struct Vozlisce {
    int podatek; // podatek, ki ga hrani vozlišče
    Vozlisce* naslednje; // kazalec na naslednje vozlišče (NULL, če ga ni)
};

/*
Če imamo Vozlisce* zacetek, potem dostopamo do podatka zacetek->podatek. 

Po vozliščih se lahko sprehodimo podobno kot s kazalci.
Dokler ni vozlišče enako NULL.
Naprej ne gremo z ++ ampak z npr. v = v->naslednje


Dostopanje do elementov v strukturah. 
Če imamo kazalec na strukturo, do elementov dostopamo z znakoma ->, če imamo samo strukturo, pa do elementa dostopamo s piko.

Kako vrnemo kazalec na vozlisce obogatenega seznama?
zacetno* vozlisce

Vedno vračamo zacetek, torej pointer na prvo vozlišče: return zacetek
Paziti moramo, ko dajemo novo vozlice na zacetek, takrat je zacetek novo vozlisce.

*/


/*
Vrne vsoto elementov povezanega seznama, na čigar 
začetno vozlišče kaže kazalec zacetek.
*/

int vsotaI(Vozlisce* zacetek) {
	Vozlisce *tmp = zacetek;
    int vsota = 0;
	while (tmp != NULL)
	{
		vsota += tmp->podatek;
		tmp = tmp->naslednje; // (*tmp).->naslednje
	}
	return vsota;
}

/* 
Sestopanje ("seštevanje od nazaj")
Vedno gremo do konca. Na koncu seštejemo trenutni element + rekurzivni klic naprej.
Ne začnemo seštevati dokler ne pridemo do NULL.
1. klic: vsota R, zacetek->podatek + podseznam velikosti 1
2. klic: vsota R, zacetek->podatek + podseznam velikosti 2
n. klic: režemo podsezname dokler ne pridemo do konca
Ko bomo na NULL vrnemo 0.
Nato seštevamo --> vrnemo spodnji klic: 
0 + 1
(0 + 1) + 9
(0 + 1 + 9) + 3

Imamo sklad vseh klicev.
Ko se s sklada poberajo prejšnji klici, se zadeva sešteva. 

Ideja:
Razdelimo problem na več delov (kot pri vsaki rekurziji).

To je seznam: (zacetek ->) 1->2->3->5->6->NULL
Lahko ga razdelimo na 1->[2->3->5->6->NULL]
Torej:
int v = zacetek->podatek + vsotaR(zacetek->naslednje)

Na tak način krčimo seznam dokler ne pridemo do NULL.
S tem, da pokličemo naslednji del rekurzije na vsotaR(zacetek->naslednje) izvedemo rekurzijo na "podseznamu" z začetkom, ki je za naslednika
naprej premaknjen.

Vrednosti se vračajo na rikverc.
Prej imamo samo na skladu neko vrednost + vračilo neke funkcije.

Šele v zadnjem primeru: 1->2->3->5->6->[NULL] imamo vse vrednosti na razpolago in se lahko vrne vsota.
Gremo od spodaj navzgor. 


*/

int vsotaR(Vozlisce* zacetek) {
	// vsota praznega seznama je 0
    if (zacetek == NULL)
	  return 0;
	//  vsoto nepraznega seznama izračunamo tako, da seštejemo prvi element
    // in vsoto seznama brez prvega elementa
	return zacetek->podatek + vsotaR(zacetek->naslednje);
}
// zacetek->podatek + naslednji klic naprej

/*
Pri rekurzivni rešitvi je potrebno razmisliti spet, kako bi problem razdelili na 
manjše probleme, na katere bomo aplicirali rekurzivno funkcijo.
• vstavimo vozlišče na začetek
• vstavimo vozlišče na sredino
• vstavimo vozlišče na konec

Podani element vstavi na ustrezno mesto v naraščajoče urejenem povezanem seznamu, 
na čigar začetno vozlišče kaže kazalec zacetek, in vrne kazalec na (morebitno novo) 
začetno vozlišče obogatenega seznama.

Z rekurzijo gremo do tam kjer je potrebno vstavljati in vrnemo vse skupaj od tam naprej. 
Rekurzija je tukaj bolj kot ne samo pretvorba for zanke v rekurzijo. 
Potrebno je poskrbeti, da se potem pri sestopanju elementi povežejo nazaj.

2 opciji
Vračamo začetek seznama
	1. vstavljanje na sredino
	2. vstavljanje na začetek

Ustaviti se moramo na enem elementu prej, ki ga bomo dodajali. 
Ne moremo sami nase pokazati; s prejšnjim elementom moramo pokazati na trenutni element.
Iz tmp npr. prevežemo na novo vozlišče. 

Vstavljanje na sredino seznama
Premakniti se moramo do nekega elementa, ki kaže na večji element. 
Ali bo tmp naslednje različen od n.
2 -> vstavljanje na sredino seznama
1 -> nul xxx
[veriga z manjšimi elementi] -> [tmp] -> [veriga z večjimi elementi]
[veriga z manjšimi elementi] -> [tmp] -> [novo] -> [veriga z večjimi elementi]
[veriga z manjšimi elementi] -> [tmp] -> [novo] -> [9 -> veriga z večjimi elementi]
Kreiramo node, kjer bo naš element novo kazal tam, kjer kaže trenutno tmp.
Tmp in novo	kažeta na neko verigo z večjimi elementi.
Npr. kažeta na 9.
S tmp pokažem na novo; tmp ne kaže več na 9 ampak na novo. 

Vstavljanje na začetek
1 - dodajanje na začetek
2
8 -> 9 -> null
2 -> 9 -> 9 -> null
prvi -> 2 -> 8 -> 9 -> null
prvi -> null

Pri vstavljanju moramo samo posodobiti obstoječi seznam in vrniti kazalec kakor nam je bil podan.
Razlika je pri dodajanju na 1. mesto. Takrat moramo vrniti kazalec na 1. (novi) element.

1 -> 5 -> 8 -> 10 ->  [30 -> null]
1 -> 5 -> 8 -> 10 -> [novo] ->  [30 -> null]
vozlišče 10.naslednje = rezultat seznama, ki ga vrne rekurzija
1 -> 5 -> 8 -> 10 -> [[novo] -> [30 -> null]]

Vedno moramo gledati na naslednjega, sicer se lahko premaknemo predaleč. In ker nimamo dvosmernega povezanega seznama, se ne moremo
pomakniti nazaj. 
		
*/

Vozlisce *createNode(int data, Vozlisce *next)
{
	Vozlisce *node = (Vozlisce *) malloc(sizeof(Vozlisce));
	node->podatek = data;
	node->naslednje = next;
	return node;
}

Vozlisce* vstaviUrejenoI(Vozlisce* zacetek, int element) {
    Vozlisce* novo = malloc(sizeof(Vozlisce));
    novo->podatek = element;

    if (zacetek == NULL || element <= zacetek->podatek) {
        // scenarij 1: vstavljanje na začetek seznama
        novo->naslednje = zacetek;
        zacetek = novo;   // novo vozlišče postane novi začetek seznama

    } else {
        // scenarij 2: dodajanje na nezačetno pozicijo

        // poiščemo vozlišče, ki bo po vstavljanju predhodnik novega vozlišča
        Vozlisce* v = zacetek;
        while (v->naslednje != NULL && v->naslednje->podatek < element) {
            v = v->naslednje;
        }

        // novo vozlišče vstavimo v seznam
        novo->naslednje = v->naslednje;
        v->naslednje = novo;
    }

    return zacetek;
}
	

/*
Vozlisce* vstaviUrejenoI(Vozlisce* zacetek, int element) {
    Vozlisce *n = malloc(sizeof(Vozlisce));
	n->podatek = element;

	if (zacetek == NULL || (element <= zacetek->podatek))
	{
		n->naslednje = zacetek;
		return n;
	}
	Vozlisce *z = zacetek;
	while (zacetek->naslednje != NULL && zacetek->naslednje->podatek < element)
		zacetek = zacetek->naslednje;
	n->naslednje = zacetek->naslednje;
	zacetek->naslednje = n;
    return z;
}
*/

/*
Krajšamo seznam z rekurzivni klici:
4 -> 5 -> 3 ->
Kličemo 1. element in vse naprej
Kličemo 2. element in vse naprej

Podobno naredimo pri vstavljanju.

Krajšamo seznam, s novim elementom pokažemo na ostanek; z prejšnjimi pa se s 
setopanjem vračamo.

4: pokaži mi na seznam, ki bo ga vrnila podrekurzija
7: pokaži mi na seznam,  ki bo ga vrnila podrekurzija
Trenutni element pokaži na to, kar nam bo vrnila rekurzija.
Shrani na sklad.
Pridemo do mesta, kjer imamo dejansko element. 
*/

Vozlisce* vstaviUrejenoR(Vozlisce* zacetek, int element) {
    if (zacetek == NULL || element <= zacetek->podatek) {
        /* seznam je prazen ali pa je novi element manjši ali enak prvemu
           elementu seznama ==> ustvarimo novo vozlišče in ga vstavimo na
           začetek seznama
		*/
        Vozlisce* novo = malloc(sizeof(Vozlisce));
        novo->podatek = element;
        novo->naslednje = zacetek;
        return novo;
    }

    /* Element je večji od prvega elementa seznama, zato ga vstavimo v rep.
       Rezultat rekurzivnega klica je kazalec na (morebitno novo) začetno
       vozlišče repa. To vozlišče mora biti naslednik začetnega
       vozlišče seznama.
	*/
    zacetek->naslednje = vstaviUrejenoR(zacetek->naslednje, element);
    return zacetek;
}


int main() {
    // koda za ro"cno testiranje (po "zelji)

    return 0;
}
