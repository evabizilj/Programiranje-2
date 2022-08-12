
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"



Vozlisce* prepleti(Vozlisce** seznami, int n) {
    Vozlisce* start = NULL;;
    Vozlisce* dano = NULL;
   
    for (int j=0; j<10000; j++){
        for(int i=0; i<n; i++){
            Vozlisce* tmp = seznami[i];
           
            if(tmp != NULL){
                bool lahko = true;
                for(int k=0; k<j; k++){
                    if(tmp->naslednje == NULL){ lahko = false; break;}
                        tmp = tmp->naslednje;
                }
                if(lahko){
                    Vozlisce* novo = malloc (sizeof(Vozlisce));
                    novo->podatek = tmp->podatek;
                    novo->naslednje = NULL;
                    if(start == NULL){
                         start = novo;                        
                         dano = start;
                    }else{
                        start->naslednje = novo;
                        start = start->naslednje;
                    }
                }
            }
        }
    }
    return dano;
}

int main() {
    return 0;
}
