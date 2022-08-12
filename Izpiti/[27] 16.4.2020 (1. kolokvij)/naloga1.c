#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*
V prvi vrstici vhoda je podano celo število n, v drugi pa zaporedje n celih števil, ločenih s po enim presledkom. 
Naj d označuje indeks prvega člena zaporedja, ki ni strogo večji od povprečja vseh predhodnih členov. Če je vsak člen večji od povprečja vseh svojih predhodnikov, naj bo d “ n. Napišite program, ki za podani vhod izpiše vrednost d.
Za potrebe te naloge naj bo povprečje nič števil enako 0.
*/

int main() {
    int n; 
    scanf("%d", &n);

    int average = 0;
    int sum = 0;

    for (int i = 1; i <= n; i++) {
        int clen; 
        scanf("%d", &clen);

        if (clen >= average) {
            printf("%d\n", i - 1);
            return 0;
        }

        sum += clen;
        average = sum / i;
       // printf("sum:%d, average: %d\n", sum, average);
    }

    printf("%d\n", n);

    return 0;
}

/*
8
1 2 7 4 6 4 8 3
sum:1, average: 1
sum:3, average: 1
sum:10, average: 3
sum:14, average: 3
sum:20, average: 4
5
*/