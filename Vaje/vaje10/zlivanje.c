#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

/*
Imamo n datotek/trakov. Vse datoteke moramo zliti v 1 sam urejen trak. 
*/

/*
Vrne indeks minimuma brez upoštevanja elementa -1.
*/

int indeksMinimuma(int* t, int n)
{
    int iMin = -1;
    for (int i = 0; i < n; i++)
    {
        if (t[i] >= 0 && (iMin < 0 || t[i] < t[iMin]))
            iMin = i;
    }
    return iMin;
}

// N vhodov izpiše na izhod
void mergeSort(FILE** vhodi, int n, FILE* izhod)
{
    // 1 - število vhodnih datotek, pri katerih smo že prišli do konca (uporabili vsa števila iz tistega traku)
    int stKoncanih = 0;
    
    /*
        2 - blok[i] trenutni element iz i-te vhodne datoteke oz. -1, če smo pri tej datoteki že prispeli
        do konca
        tabela v kateri hranimo delovne verzije trenutnega elementa iz vsakega traku; iskali bomo minimalni
        element
        [45, -1, 80, -1, -1, 32] ... 6 trakov; na 2., 4. in 5. traku so bili elementi manjši od 32 - 3 aktivni trakovi
    */

    int* blok = (int* ) malloc(n * sizeof(int));
   
    /* 
        2.1 - blok napolnimo z začetnimi elementi iz trakov (prve elemente vseh datotek prepišemo v tabelo <blok>)
        datoteka je prazna --> -1 (kot da bi porabili vse elemente traku)
        inicializacija tabele blok z prvimi elementi vsakega traku (datoteke)
    */
    for (int i = 0; i < n; i++)
    {
        // int fscanf(FILE* stream, "format", ...) ... vrne število elementov, ki jih ustrezno prebere
        // vedno ko naredimo fscanf, se avtomatsko premakne kazalec na file za 1 naprej
        // preberemo prvi element vsake datoteke
        if (fscanf(vhodi[i], "%d", &blok[i]) < 0)
        {
            blok[i] = -1;
            stKoncanih++;
        }
    }

    while(stKoncanih < n)
    {
        // 3 - poiščemo najmanjši element v tabeli <blok> (oz. njegov indeks) --> zapiši ga na izhod
        int iMin = indeksMinimuma(blok, n);
        fprintf(izhod, "%d\n", blok[iMin]);

        // 3.1 - izpisani element nadomestimo z naslednjim elementom na traku (v pripadajoči datoteki[i])
        // če smo izpisali zadnji element na traku --> - 1 (trak se je zaključil)
        if (fscanf(vhodi[iMin], "%d", &blok[iMin]) < 0)
        {
            blok[iMin] = -1;
            stKoncanih++;
        }
    }
    free(blok);
}


// vrača tabelo kazalcev na datoteke --> prebere iz vhoda in vrne vse odprte datoteke v tabeli
FILE** openFiles(int n, char* mode)
{
    char* fileName = (char* ) malloc((MAX_NAME_LENGTH + 1) * sizeof(char));
    FILE** files = (FILE** ) malloc(n * sizeof(FILE *)); // hranimo kazalce na FILE
    for (int i = 0; i < n; i++)
    {
        scanf("%s", fileName);
        // mode: r, w, a,  ..+, ...b, ...t
        // na i-to mesto zapiše kazalec, ki kaže na odprto datoteko
        files[i] = fopen(fileName, mode); 
    }

    free(fileName);
    return files;
}

void closeFiles(FILE **files, int n)
{
    for (int i = 0; i < n; i++)
        fclose(files[i]);
    
    free(files);
}

int main() 
{
    int stDatotek;
    scanf("%d", &stDatotek);

    // 1 - odpremo vse datoteke/trakove--> tabela kazalcev na datoteke
    FILE** vhodi = openFiles(stDatotek, "r");

    // odpremo ciljni trak, za pisanje -- vrne tabelo dolžine 1 in tisti kaže na datoteko
    FILE** izhodi = openFiles(1, "w"); 

    // 2 - zlij datoteke v eno datoteko
    // 1 sam izhod: izhod[0] ali *izhodi
    mergeSort(vhodi, stDatotek, *izhodi);

    // 3 - zapremo vse datoteke
    closeFiles(vhodi, stDatotek);
    closeFiles(izhodi, 1);

    return 0;
}

/* 

Kako naredimo poljubno št spremenljivk tipa FILE? Hranimo v tabelo. FILE **

Začasna tabela, ki hrani trenutni element iz vsakega traku. Nato bomo poiskali minimum ter ga zapisali.
Odpremo vseh n datotek --> pomožna tabela, ki hrani trenutno aktiven element iz vsake datoteke.
Sproti pišemo na izhodno datoteko. Element, ki ga uporabimo, ustrezno prenesemo na tabelo na traku.

SLIKA
Imamo 3 trakove/datoteke.
Definiramo neko tabelo, kjer bomo imeli element iz vsakega traku (najmanjšega).
V tej tabeli bomo morali poiskati indeks minimuma (na katero mesto potem prepisati podatek na novo tabelo).
Npr. na izhod smo prepisali
1 3 4 5 6
Ko smo porabili 1, smo naložili 10 (ta čaka). Ko smo porabili 4 in 5, čaka 7. 
...
Premikamo se toliko časa, dokler traku ni konec. 

V <blok> so najprej neke random vrednosti. 
V zanki preberemo na i-ti vhod iz prve datoteke, druge datoteke ... 

Pri drugi nalogi imamo števila v posameznih datotekah urejena po vrsti.
Torej najmanjše število je eno izmed prvih števil v datotekah:
Ideja:
    - v tabelo preberemo prva števila
    - izberite najmanjšega izmed njih
    - nadomestite ga z naslednjim številom iz datoteke
    - v tabeli moramo označiti, ko smo pršli do konca datoteke

V tabeli moramo označiti, ko smo pršli do konca datoteke.

Pri malloc potrebujemo + 1.
Tukaj potrebujemo prostor za zaključni znak na koncu vrstice.

Pri tej nalogi moramo implementirati algoritem zlivanja. Iščemo rešitev s časovno zahtevnostjo O(n),
če je n število števil. 
Branje vseh elementov v tabelo in urejanje te tabele ne bo pravi pristop, ker se da hitreje. 
Datoteke so že urejene, torej rabimo na vsakem koraku le poiskati minimum od prvih elementov vseh 
datotek, ga prepisati v izhodno datoteko in se v datoteki, kjer smo vzeli element, 
premakniti na naslednjega. 

*/ 

// ./zlivanje < test01.in
/*
./zlivanje
  2
  a.txt
  b.txt
  izhod.txt
*/

/*

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

/*
Vrne indeks minimuma brez upoštevanja elementa -1. 
*/
/*

int indeksMinimuma(int* t, int n)
{
    int iMin = -1;
    for (int i = 0; i < n; i++)
    {
        if (t[i] >= 0 && (iMin < 0 || t[i] < t[iMin]))
            iMin = i;
    }
    return iMin;
}

void mergeSort(FILE** vhodi, int n, FILE* izhod)
{
    int stKoncanih = 0;
    int* tabela = (int *) malloc(n * sizeof(int));
   
    // prve elemente vseh datotek prepišemo v tabelo; -1: datoteka je prazna
    for (int i = 0; i < n; i++)
    {
        if (fscanf(vhodi[i], "%d", &tabela[i]) < 0)
        {
            tabela[i] = -1;
            stKoncanih++;
        }
    }
    // tabela: [45, -1, 80]

    while (stKoncanih < n)
    {
        int iMin = indeksMinimuma(tabela, n);
        fprintf(izhod, "%d\n", tabela[iMin]);
    
        // izpisani element nadomestimo z naslednjim elementom v pripadajoči datoteki
        if (fscanf(vhodi[iMin], "%d", &tabela[iMin]) < 0)
        {
            tabela[iMin] = -1;
            stKoncanih++;
        }

    }

    free(tabela);
}

void closeFiles(FILE** files, int n)
{
    for (int i = 0; i < n; i++)
        fclose(files[i]);
    free(files);
}

FILE** openFiles(int n, char* mode)
{
    char* fileName = (char *) malloc((MAX_NAME_LENGTH + 1) * sizeof(char));
    FILE** files = (FILE**) malloc(n * sizeof(FILE*));
    for (int i = 0; i < n; i++)
    {
        scanf("%s", fileName);
        files[i] = fopen(fileName, mode);
    }

    free(fileName);
    return files;
}

int main()
{
    int stDatotek;
    scanf("%d", &stDatotek);

    // odpremo vse datoteke
    FILE** vhodi = openFiles(stDatotek, "rt");
    FILE** izhod = openFiles(1, "wt");

    // zlij datoteke v eno datoteko
    mergeSort(vhodi, stDatotek, izhod[0]);

    // zapremo vse datoteke
    closeFiles(vhodi, stDatotek);
    closeFiles(izhod, 1);

    return 0;
}


*/