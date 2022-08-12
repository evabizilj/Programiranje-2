
/*
 * Va"sa re"sitev druge naloge --- datoteko dopolnite in jo oddajte na spletno u"cilnico!
 *
 * Your solution to task 2 --- complete the file and submit it to U"cilnica!
 *
 * V naslednjo vrstico vpi"site va"so vpisno "stevilko / Enter your student ID number in the next line:
 *
 */

#include "naloga2.h"
Vozlisce* ods (Vozlisce* osnova, int indeks, int trenutni);
Vozlisce* odstrani(Vozlisce* osnova, Vozlisce* indeksi) {
    int i=0;
    while(indeksi != NULL){
        int data = indeksi->podatek;
        osnova = ods(osnova, data-i, 0);
        indeksi=indeksi->naslednje;
        i+=1;
    }
    return osnova;
}

Vozlisce* ods (Vozlisce* osnova, int indeks, int trenutni){
    if(osnova == NULL) return NULL;
    if(indeks == trenutni){
        Vozlisce* tmp = osnova;
        osnova = osnova->naslednje;
        free(tmp);
        return osnova;
    }
    osnova->naslednje = ods(osnova->naslednje, indeks, trenutni+1);
    return osnova;
}



int main() 
{
  
}
