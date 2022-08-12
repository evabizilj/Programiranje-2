
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Oseba Oseba;

struct Oseba {
    char* ime;
    int starost;
};

void uredi(Oseba** osebe, int n);

bool primerjaj (char* oseba1, char* oseba2) 
{

    //printf("%s %s\n", oseba1, oseba2);
    char* ime1 = oseba1;
    char* ime2 = oseba2;

    while (*ime1 != '\0' || *ime2 != '\0') 
    {
        //printf("%c %c\n", *ime1, *ime2);
        if (*ime1 == *ime2) 
        {
            ime1++;
            ime2++;
        }
        else if (*ime1 > *ime2) 
            return true;
        
        else if (*ime1  < *ime2) 
            return false;
    }

    return false;
}


void uredi(Oseba** osebe, int n) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n - 1; j++) 
        {
            if (primerjaj(osebe[j]->ime,osebe[j + 1]->ime)) 
            {

                Oseba* tmp = osebe[j];
                osebe[j] = osebe[j + 1];
                osebe[j + 1] = tmp;

            }

        }
    }
}

int main()
{
    return 0;
}
