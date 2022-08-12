#include <stdio.h>
#include <stdlib.h>

/*
Napišite program, ki prebere cela števila n, k in m in izpiše prvih m n-mestnih števil, 
pri katerih se sosednji števki razlikujeta za natanko k. Števila naj bodo izpisana v naraščajočem vrstnem redu.
Števila n, k in m so na vhodu ločena s po enim presledkom. 

7 3 20
   1414141
   1414147
   1414741
   1414747
   1474141
   1474147
   1474741
   1474747
   2525252
   2525258
   2525852
   2525858
   2585252
   2585258
   2585852
   2585858
   3030303
   3030363
   3030369
   3036303

*/

int n, k, m;
// metoda, ki bo generirala prave kombinacije --> velikosti 100
int num[100];

void output(int i) // indeks elementa, ki ga bomo določili 
{
    // ustavitveni pogoj (postavili smo že vsa števila do n)
    if (i == n) {
        for (int j = 0; j < n; j++)
            printf("%d", num[j]);
        printf("\n");
        m = m - 1; 
        return; 
    }

    // glavni del
    // na i-tem mestu katerakoli števka: za k razlikuje od prejšnje

    if (i == 0) {
        // na začetku je lahko na i-tem mestu katerakoli števka 1 - 9
        for (int j = 1; j <= 9; j++) {
            // števko dam na i-to mesto
            num[i] = j;
            // na vseh drugih mestih to naredim z rekurzivnim klicem --> problem zmanjšam
            output(i + 1);
            if (m == 0)
                return;
        }
    }
    
    // zgeneriram vse kombinacije števk od 0 - 9 
    else {
        // lahko je katerakoli števka
        for (int j = 0; j <= 9; j++) {
            // nastavim jo na i-to mesto 
            num[i] = j; // output (i + j) tukaj še ne morem napisati, še pogoj
            // if (abs([num[i - 1] - num[i]) == k)
            // števka na i-tem mestu je dovoljena samo, če se za k razlikuje od predhodnika
            // samo izmerim razdaljo med dvema številoma (ni pomembno katera smer)
            if ((num[i - 1] - num[i] == k) || (num[i] - num[i - 1] == k))
                output(i + 1);
            // kombinacije se ne smejo začeti z ničlo - da bo res n-mestno število
            if (m == 0)
                return;
        }
    }
}

int main() 
{
    scanf("%d", &n);
    scanf("%d", &k);
    scanf("%d", &m);
    output(0);

    return 0;
}