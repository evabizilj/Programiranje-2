#include <stdio.h>
#include <stdlib.h>

int main()
{
   int* temperature = (int *) malloc(1 * sizeof(int));
   int stPodatkov = 0;
   int temperatura = 0;

   while (temperatura != -9999)
   {
       int *tmp = (int* ) realloc(temperature, sizeof(int) * (stPodatkov + 1));
       temperature = tmp; 
       scanf("%d", &temperatura);
       temperature[stPodatkov] = temperatura;
       stPodatkov++;
   }

   int zacetek = -1;
   int trajanje = -1;
   int maxZacetek = 0;
   int maxTrajanje = 0;
   int dan = 0;

   for (int i = 0; i < stPodatkov && temperature[i] != -9999; i++)
   {
       if (temperature[i] >= 300)
       {
            if (zacetek == -1)
                zacetek = dan;
            trajanje++;
       }

       else
       {
            if (maxTrajanje < trajanje)
            {
                maxZacetek = zacetek;
                maxTrajanje = trajanje;
            }
            trajanje = 0;
            zacetek = -1;
       }
       dan++;
   }

   printf("%d %d\n", maxZacetek + 1, maxTrajanje);
}
