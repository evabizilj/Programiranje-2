#include <stdio.h>
#include <stdlib.h>


unsigned char* vrniRaster(char* fileName, int* sirina, int* visina)
{

   FILE *fileSlika = fopen(fileName, "rb");

   // preberi glavo datoteke (pomembni sta samo širina in višina)
   int nTemp = 10;
   char* temp = (char *) malloc((nTemp + 1) * sizeof(char));

   fgets(temp, nTemp, fileSlika);

   fscanf(fileSlika, "%d %d", sirina, visina);
   fgetc(fileSlika);

   fgets(temp, nTemp, fileSlika);
   free(temp); 

   int blokSize = 3 * *visina * *sirina;
   unsigned char* pike = (unsigned char*) malloc(blokSize * sizeof(unsigned char));
   fread(pike, sizeof(unsigned char), blokSize, fileSlika);
   fclose(fileSlika);

   return pike;
}

// Pretvori barvno sliko v sivinsko in jo vrne.
unsigned char* toGrayscale(unsigned char* barve, int sirina, int visina)
{
    
    unsigned char* sivine = (unsigned char *) malloc(visina * sirina * sizeof(unsigned char));
    int b = 0;
    int s = 0;
  
    // Sprehajamo se po vseh vrednosti pik (po 1 naprej), hkrati pa pišemo v 2. tabelo
    // i, j ... sprehajamo po številkah
    for (int i = 0; i < visina; i++)
    {
        for (int j = 0; j < sirina; j++)
        {
            // 30 * red + 59 * green + 11 * blue / 100
            sivine[s] = (30 * barve[b] + 59 * barve[b + 1] + 11 * barve[b + 2]) / 100;
            b += 3; // za tri naprej, ker ima vsaka pika 3 elemente
            s++; // sprehajamo po indeksih tabele
        }
    }
    return sivine;
}

// Zapiše blok <sivine> v pomnilniku v datoteko. 

void createPgmFile(char* fileName, unsigned char* sivine, int sirina, int visina)
{
    /*
    P6
    širina višina 
    255
    vsebina 
    */

   FILE* pgmFile = fopen(fileName, "wb");
   fprintf(pgmFile, "P5\n");
   fprintf(pgmFile, "%d %d\n", sirina, visina);
   fprintf(pgmFile, "255\n");
   fwrite(sivine, sizeof(unsigned char), visina * sirina, pgmFile);
   fclose(pgmFile);


}

int main(int argc, char** argv)
{
    // 1 - preberi datoteko <ppm>
    int sirina = 0;
    int visina = 0;

    unsigned char* barve = vrniRaster(argv[1], &sirina, &visina);

    // 2 - pretvori barve v sivine
    unsigned char* sivine = toGrayscale(barve, sirina, visina);

    // 3 - zapiši v datoteko <pgm>
    createPgmFile(argv[2], sivine, sirina, visina);
    free(sivine);

    return 0;
}