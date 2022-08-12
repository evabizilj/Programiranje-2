#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        printf("[Napaka]: argumenti programa ... \n");
        return 1;
    }

    // 1 - preberi datoteko
    // odpri vhodno datoteko (r = branje, b = dvojiška datoteka)
    FILE *fileSlika = fopen(argv[1], "rb");
    // int atoi(const char *niz) ... pretvori niz v celoštevilsko vrednost
    int vrstica = atoi(argv[2]); // atoi pretvori niz v število, npr. "123" -> 123
    int stolpec = atoi(argv[3]);


    /*
    preberi glavo datoteke (pomembni sta samo visina in sirina)
    */

   int nTemp = 10;
   char* temp = (char *) malloc((nTemp + 1) * sizeof(char));
   // char* fgets(char *str, int n, FILE* stream)

   // 1. vrstica
   fgets(temp, nTemp, fileSlika);

   // 2. vrstica
   // sirina visina
   int sirina = 0;
   int visina = 0;
   fscanf(fileSlika, "%d%d", &sirina, &visina);
   // se '\n'
   fgetc(fileSlika);

   // 3. vrstica
   fgets(temp, nTemp, fileSlika);
   free(temp);

   // 2 - preberi podatke o slikovnih pikah v tabelo 'pike'
   // preberi podatke o slikovnih pikah v tabelo <pike>;
   // vsaka pika zaseda 3 bajte (rdeča, zelena, modra)
   unsigned char* pike = (unsigned char*) malloc(3 * visina * sirina * sizeof(unsigned char));
   // size_t fread(void* ptr, size_t velikost, size_t #elementov, FILE* stream)
   // pointer na blok pomnilnika, velikost enega elementa, stevilo elementov, stream 
   fread(pike, sizeof(unsigned char), 3 * visina * sirina, fileSlika);
   fclose(fileSlika);

   // 3 - izlušči barvne komponente pike na podanih koordinatah
   int indeks = 3 * (sirina * vrstica + stolpec);
   int red = pike[indeks];
   int green = pike[indeks + 1];
   int blue = pike[indeks + 2];
   printf("%d %d %d\n", red, green, blue);
   free(pike);
}

/*
Prebrati moramo vrednost ene pike in jo zapisati v ciljno datoteko.

Uporaba fseek, da se neposredno pomaknemo na pravo mesto
int fseek (*stream, odmik, od-kje)
kjer je od-kje lahko: SEEK_SET, SEEK_CUR, SEEK_END


sestava datoteke slika01.ppm:
iz glave in bitne tabele pik
Glava pa je sestavljena iz:
P6         (magic number) in pove tip datoteke, lahko je P6, P5 črnobela, P3 ...
druga vrstica drži podatek o širini in višini slike

Preberemo kot text z fgets
Tretja vrstica predstavlja maksimalno vrednost za barvo (v našem primeru 255).
Če bi imeli 16 bitov za vsako komponento barve, bi bilo na tem mestu 65 ...
V naslednji vrstici pa sledi zaporedje visina * sirina * 3 podatkov o posamezni barvi pike. 

glava (najdaljša vrstica) predpostavljamo, da ne bo daljša od 10 + 1
za podatke o slikah, pa lahko izračunamo: višina * širina * 3

P6: preberemo in zavržemo

FILE* vhod = fopen(argv[1], "rb"); paziti moramo na 'rb', da je b za binarno datoteko
fgets(.....); preberemo prvo vrstico, nek string, ki ga ne potrebujemo 
fscanf(vhod, "%d%d", &sirina, &visina); preberemo visino in sirino
fgetc(vhod); preberemo newline po visini in sirini
fgets(...); preberemo še en nepomemben string

preberemo sliko:
fread(slika, sizeof(unsigned char), 3 * visina * sirina, vhod)
za binarno je potrebno dati 'rb'

p6 ni ime slike, ime preberemo iz ukazne vrstice
int main(int argc, char** argv){}
iz argv[] dobimo ven ime slike

Torej, 1. in 3. vrstica v datoteki sta nepomebni. Prebrati jih je potrebno, da se pomaknemo naprej. 

Prebrana slika izgleda kot enodimenzionalna tabela velikost vrstice * stolpci * 3.
malloc(3 * visina * sirina * sizeof(unsigned char))

Število nivojev barv
unsigned char* slika = malloc(3 * visina * sirina * sizeof(char));

Ko preberemo sliko, moramo samo še indekse pripadajočega piksla izračunati.
in spisati slika[indeksR],  slika[indeksG],  slika[indeksB].

argv je po definiciji string --> potrebujemo int 
int vrstica = atoi(argv[2]);
atoi() pretvori string v int


*/