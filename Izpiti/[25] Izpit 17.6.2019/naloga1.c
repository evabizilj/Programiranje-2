
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {
 
    char* vhod = malloc(sizeof(char) * 21);
    char* izhod = malloc(sizeof(char) * 21);
    int n;
    scanf("%s", vhod);
    scanf("%d", &n);
    scanf("%s", izhod);
    FILE* in = fopen(vhod,"rb");
    FILE* out = fopen(izhod,"wb");

    unsigned char* pike = malloc(sizeof(unsigned char) * (3 * n));
    fread(pike, sizeof(unsigned char), 3 * n, in);

    unsigned char R;
    unsigned char G;
    unsigned char B;
    int ena = 0;
    int dva = 0;
    int tri = 0;
 
    for (int i = 0; i < n; i++) 
    {
        int indeks = i * 3;
        R = pike[indeks];
        G = pike[indeks + 1];
        B = pike[indeks + 2];

        if (R > 0 && G == 0 && B == 0) 
            ena++;

        else if (R == 0 && G > 0 && B == 0) 
            dva++;
        
        else if (R == 0 && G == 0 && B > 0) 
            tri++;
    }

    fprintf(out, "%d\n" ,ena);
    fprintf(out, "%d\n", dva);
    fprintf(out, "%d\n", tri);
  
    fclose(in);
    fclose(out);
    return 0;
}


