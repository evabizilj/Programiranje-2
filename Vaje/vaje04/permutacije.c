#include <stdio.h>
#include <stdbool.h>

/*
Nikoli ne definiramo tabele na skladu (znotraj programa).
Če jo definiramo globalno, izven kode, na vrhu --> tabela ni na skladu 

Ena sama zanka je dovolj, in sicer:
    • naredimo tabelo prisotnosti, kjer nam vsako mesto predstavlja neko število
    • preberemo števila in si označujemo ustrezno mesto v tabeli
    • po branju preverimo ali so bila prebrana vsa števila
*/

#define MAX_VELIKOST_STEVILA 1000000
// prisotnosti[i] == true <==> število i je prisotno v zaporedju
bool prisotnosti[MAX_VELIKOST_STEVILA];

int main() {
    int stClenov;
    scanf("%d", &stClenov);

    // bool *prisotnosti = (bool *) malloc(MAX_VELIKOST_STEVILA * sizeof(bool);
    // bool *prisotnosti = (bool *) calloc(sizeof(bool), MAX_VELIKOST_STEVILA);

    bool jePermutacija = true;

    // sprehodimo se po zaporedju in napolnimo tabelo <prisotnosti>
    for (int i = 0; i < stClenov; i++) // n
    {
        int clen;
        scanf("%d", &clen);
        if (clen < 0 || clen > MAX_VELIKOST_STEVILA)
        {
            // vemo, da zaporedje ne more biti permutacija
            jePermutacija = false;
            break;
        }
        // kam damo clen
        prisotnosti[clen] = true;
    }
    
    // preverimo ali so bila prebrana vsa števila
    /* zaporedje je še vedno lahko permutacija;
       če obstajajo vsa števila od 0 do stClenov - 1, potem je zaporedje dejansko permutacija
    */
    if (jePermutacija)
    {

        for (int i = 0; i < stClenov; i++)
        {
            if (!prisotnosti[i])
            {
                jePermutacija = false;
                break;
            }   
        }
    }
    printf("%s\n", jePermutacija ? "DA" : "NE");
    // free(prisotnosti);

    return 0;
}
