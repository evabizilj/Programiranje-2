
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

int* skladnost(char* s, char* t, int* maks) {
    // popravite / dopolnite ...

    int dolzina = 0;
    int max = 0;
    char* tmp = s;

    while (*tmp != '\0') {
        dolzina++;
        tmp++;
    }

    int* tab = malloc(sizeof(int) * dolzina);

    for (int i = 0; i < dolzina; i++) {

        int counter = 0;
        char* tmpS = s;
        char* tmpT = t;
        int ind = 0;
        
        while (*tmpS != '\0' && ind != i) {
            ind++;
            tmpS++;
        }

        while (*tmpS != '\0' && *tmpT != '\0') {

            if (*tmpS != *tmpT) 
                break;
            counter++;
            tmpS++;
            tmpT++;
        }
        if (max < counter) 
            max = counter;
        tab[i] = counter;
    }

    *maks = max;

    return tab;
}

int main() {
    // koda za ro"cno testiranje (dopolnite po "zelji/potrebi)
    return 0;
}
