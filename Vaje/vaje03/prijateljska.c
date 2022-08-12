#include <stdio.h>
#include <math.h>

// Vrne vsoto pravih deliteljev podanega števila.
/*
Delitelji so simetrični okrog korena. Če je število <a> delitelj števila <stevilo>, potem
je njegov delitelj tudi število b = stevilo / a. 
Ko odkrijemo, da je <a> delitelj podanega števila, k vsoti prištejemo tako <a> kot <b>, 
moramo pa paziti, da istega delitelja ne prištejemo dvakrat (to bi se nam lahko zgodilo pri
majhnih številih in popolnih kvadratih).
*/

int vsotaPravihDeliteljev(int stevilo) 
{
    // šstevilo 1 nima pravih deliteljev
    if (stevilo <= 1) 
        return 0;
    int meja = (int) ceil(sqrt(stevilo));
    int vsota = 1;
    for (int a = 2;  a <= meja;  a++) {
        if (stevilo % a == 0) {
            int b = stevilo / a;
            if (b > a) 
                vsota += a + b;
            else if (b == a) 
                vsota += a;  
        }
    }
    return vsota;
}

int main() 
{
    int n;
    scanf("%d", &n);

    // edini kandidat za prijatelja števila <n> je vsota pravih deliteljev tega števila
    
    int kandidat = vsotaPravihDeliteljev(n);

    // preverimo, ali je <kandidat> res prijatelj šstevila <n>
    if (kandidat != n && vsotaPravihDeliteljev(kandidat) == n) 
        printf("%d\n", kandidat);
    else 
        printf("NIMA\n");
    return 0;
}
