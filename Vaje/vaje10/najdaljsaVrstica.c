#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000000 // v to vrstico beremo ("buffer")

/*
beremo lahko vrstice ali pa znake

**argv ... tabela nizov
char niz* = ...
char **tabelaNizov = **nizi; // kazalci na nize

char* fgets(char *str, int n, FILE* stream) --> vrača kazalec tipa char
s toka <stream> prebere vrstico dolžine <n> (vključno z \n) in jo shrani v string na katerega kaže <str>

char *strcpy(char* dest, const char* src)
   
*/

int main(int argc, char **argv)
{
    // ./najdajsa-vrstica vhodnaDatoteka.txt izhodnaDatoteka.txt
    // odpremo vhodno in izhodno datoteko
    FILE* source = fopen(argv[1], "rt");
    FILE* target = fopen(argv[2], "wt");

    // preberemo prvo vrstico
    char* vrstica = (char *) malloc((MAX_LINE_LENGTH + 1) * sizeof(char));
    int najDolzina = 0; // doslej največja dolžina vrstice
    char* najVrstica = NULL; // ne definiramo še konkretne vrednosti, kam bo spremenljivka kazala; doslej najdaljša vrstica (kazalec na začetek niza)

   // beremo vrstice, dokler ne prispemo do konca datoteke
    while (fgets(vrstica, MAX_LINE_LENGTH + 1, source) != NULL)
    {
        // dolžina trenutne vrstice
        int dolzina = strlen(vrstica);

        // vrstica je daljša od doslej najdaljše, zato posodobimo
        // spremenljivko <najDolzina>, skopiramo vrstico in postavimo
        // kazalec <najVrstica> na za"cetek kopije
        if (dolzina > najDolzina)
            najDolzina = dolzina;
            // če je vrstica == NULL, se ne zgodi nič
            free(najVrstica);
            najVrstica = (char *) malloc((dolzina + 1) * sizeof(char));
            strcpy(najVrstica, vrstica);
    }

    free(vrstica);

    // stdout
    fprintf(target, "%s", najVrstica);
    free(najVrstica);

    fclose(source);
    fclose(target);

    return 0;
}

/*

Delo z argumenti ukazne vrstice
int main(int argc, char *argv[])
{
	printf("ime programa:\n %s\n", argv[0]);
	printf("argumenti:\n");
	for(int i=1; i<argc; i++)
	{
		printf(" %s\n", argv[i]);
	} 
}

Delo z datotekami
Datoteke uporabljamo preko datotečnega kazalca, torej kazalca na strukturo FILE, v kateri so shranjeni podatki o datoteki.

//odpiranje datoteke
FILE* fp = fopen(ime, način);

//Odpiranje za branje:
FILE* fp = fopen("vhod.txt", "r");

//Branje iz standardnega vhoda
scanf("%d", &n); 

//Branje iz datoteke
fscanf(fp, "%d", &n);

//Odpiranje datoteke v katero bomo pisali
FILE* fp2 = fopen("izhod.txt", "w");

//Pisanje v datoteko
fprintf(fp2, "%d\n", n);

//Kako naredimo tabelo za 5  datotek
FILE ** arr = malloc(5*sizeof(FILE*);

//prvo dodamo v branje
*arr = fopen("vaja.txt", "r");

//Na koncu moramo vse odprte datoteke zapreti
fclose(fp)


Odpremo datoteko:
FILE* vhod = fopen(argv[1], "rt");
"rt" pomeni read text, če želimo vanjo pisati pa argumet zamenjamo z "w" write oziroma "wt" write text
Vanjo pišemo z 
fprintf()

t refers to the text mode. There is no difference between r and rt or w and wt since text mode is the default.

int fseek(FILE *stream, long int odmik, int sidrnaPozicija)
kjer je sidrnaPozicija lahko: SEEK_SET, SEEK_END, SEEK_CUR (začetek, konec, trenutna pozicija v datoteki)


char *fgets(*string, in dolzina, FILE *stream)
char *vrstica = (char *) malloc (SIZE * ...
fgets(vrstica, SIZE, file)
paziti je treba, ker size zajema tudi znak \n



Beremo vrstice po vrsti in si zapomnimo najdaljšo.
Na koncu, najdaljšo zapišemo v izhodno datoteko.
Namesto branja po znakih, lahko uporabimo branje po vrsticah  (fgets).

Zanima nas samo največja možna dolžina niza. 
Če to vemo, lahko naredimo vrstico dolžine največja možna dolžina + 1 in uporabimo fgets.


*/