
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


int main(int argc, char* argv[]) {
    
    char vhod[21];
    scanf("%s", vhod);
    int dolzina;
    scanf("%d", &dolzina);
    char izhod[21];
    scanf("%s", izhod);


    
    FILE *in = fopen(vhod,"rb");
    FILE *out = fopen(izhod,"wb");
     
    unsigned char* vsebina = malloc(sizeof(unsigned char) * dolzina);
    fread(vsebina,sizeof(unsigned char),dolzina,in);

    for (int i = 0; i < dolzina; i++) {
        fprintf(out, "%02X\n", vsebina[i]);
    }

    fclose(in);
    fclose(out);

    return 0;
}