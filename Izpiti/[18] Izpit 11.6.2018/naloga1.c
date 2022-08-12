#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int stOseb;
    scanf("%d", &stOseb);

    int* visine = (int* ) malloc(stOseb * sizeof(int));
    for (int i = 0; i < stOseb; i++)
        scanf("%d", &visine[i]);
    
    int stNeskoncnoDalec = 0; 

    for (int i = stOseb - 1; i >= 0; i--)
    {
        int visina = visine[i];
        bool vidi = true;

        for (int j = i + 1; j < stOseb; j++)
        {
            if (visine[j] > visina)
            {
                vidi = false;
                break;
            }
        }
        if (vidi)
            stNeskoncnoDalec++;
    }

    printf("%d\n", stNeskoncnoDalec);
    free(visine);
    
    return 0;
}