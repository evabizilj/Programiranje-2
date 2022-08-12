#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_DOLZINA_IZRAZA 1000

/*
Vrne true, ko izraz vsebuje odvečni par zunanjih oklepajev.

@param izraz - matematični izraz
@param length - dolžina izraza
*/

bool odvecniZunanjiOklepaji(char* izraz, int length)
{
    if (length < 2)
        return false;
    if (*izraz != '(' || izraz[length - 1] != ')')
        return false;
    
    // ravnovesje () znotraj "zunanjih" oklepajev
    int stOdprtih = 1;
    // (        (3 + 4)  * (4 + 8)      )
    for (int i = 1; i < length - 1; i++)
    {
        char znak = izraz[i];
        if (znak == '(')
            stOdprtih++;
        else if (znak == ')')
        {
            stOdprtih--;
            if (stOdprtih < 1)
            /*
             (             3 + 4) * (4 + 8        )
             [opozorilo]: obstaja del izraza, ki je izven oklepajev
             --> zunanji oklepaji niso odveč
            */
           return false;
        }
    }
    return true;
}

/*
Vrne indeks najbolj desnega, najšibkejšega operatorja izven oklepajev.
Če takega operatorja ni, vrne -1.
*/

int desniNajsibkejsiOperator(char* izraz, int length)
{
    int ixPlusMinus = -1;
    int ixKratDeljeno = -1;
    // ravnovesje oklepajev
    int balance = 0;
    // 3 + 4 * (5 + 2)
    for (int i = 0; i < length; i++)
    {
        char znak = izraz[i];
        balance += (znak == '(') ? 1 : 0;
        balance -= (znak == ')') ? 1 : 0;
        if (balance == 0)
        {
            if (znak == '+' || znak == '-')
                ixPlusMinus = i;
            if (znak == '*' || znak == '/')
                ixKratDeljeno = i;
        }

    }
    return (ixPlusMinus >= 0) ? ixPlusMinus : ixKratDeljeno;
}

/*
Izračuna aritmetični izraz in vrne rezultat.
((2 + 4) * (1 + 7))
*/

int izracunaj(char* izraz)
{   
    /*
        (    (2 + 4) * (1 + 7) + 8         )
        2 + 4) * (1 + 7
        a + 8
        izracunaj (2 + 4) * (1 + 7)
        izracunaj 8
    */

    // 1 - iterativno odstrani vse odvečne zunanje oklepaje
    int length = strlen(izraz);
    while (odvecniZunanjiOklepaji(izraz, length))
    {
        izraz[length - 1] = '\0';
        izraz++;
        length -= 2;
    }
    // printf("%s\n", izraz);


    // 2 - pridobi indeks najbolj desnega najšibkejšega operatorja
    int ixOperator = desniNajsibkejsiOperator(izraz, length);
    if (ixOperator == - 1)
        // takega operatorja ni v izrazu --> izraz je število
        return *izraz - '0';
        // '8' --> 56 - 48 = 8

    char operator = izraz[ixOperator];
    // printf("idx operatorja: %d\n", ixOperator);

    // 3.1 - izračunaj desni podizraz
    int valueRight = izracunaj(izraz + ixOperator + 1);

    // 3.2 - izračunaj levi podizraz
    //      2 * 3 + 6 * 2 --> 2 * 3 \0 6 * 2
    izraz[ixOperator] = '\0';
    int valueLeft = izracunaj(izraz);

    // izračunaj trenutni izraz
    switch (operator)
    {
        case '+':
            return valueLeft + valueRight;
        case '-':
            return valueLeft - valueRight;
        case '*':
            return valueLeft * valueRight;
        case '/':
            return valueLeft / valueRight;
    }
    return 0;
}

/*
Prebere izraz iz vhoda.
*/

void preberiIzraz(char* izraz)
{
    // 3 + 4 * (7         +2)
    char* beseda = (char *) malloc((MAX_DOLZINA_IZRAZA + 1) * sizeof(char));
    *izraz = '\0';

    // ctrl + D - zaključi stream
    while (scanf("%s", beseda) > 0)
        strcat(izraz, beseda);
    free(beseda);
}

int main()
{
    char* izraz = (char *) malloc((MAX_DOLZINA_IZRAZA + 1) * sizeof(char));
    preberiIzraz(izraz);
    // printf("'%s'\n", izraz);
    // scanf("%s", izraz);

    int rezultat = izracunaj(izraz);
    // printf("%d\n", rezultat);

    free(izraz);

    return 0;
}