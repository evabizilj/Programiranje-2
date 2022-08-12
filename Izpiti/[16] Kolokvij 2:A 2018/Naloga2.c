#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int nacini(int* stevila, int stStevil, int stIndeksov, int vsota, int trenutnaVsota, int trenutniIndeks, int steviloVkljucenih)
{
    // robni pogoj (false)
    if (trenutnaVsota > vsota || steviloVkljucenih > stIndeksov || trenutniIndeks > stStevil)
        return 0;
    
    // robni pogoj (true)
    if (trenutnaVsota == vsota && steviloVkljucenih == stIndeksov)
        return 1;

    // element lahko vključimo ali pa ne
    int vkljuci = nacini(stevila, stStevil, stIndeksov, vsota, trenutnaVsota + stevila[trenutniIndeks], trenutniIndeks + 1, steviloVkljucenih + 1);
    int neVkljuci = nacini(stevila, stStevil, stIndeksov, vsota, trenutnaVsota, trenutniIndeks + 1, steviloVkljucenih);

    return vkljuci + neVkljuci;
}

int main()
{
    int stStevil;
    int stIndeksov;
    int vsota; 

    scanf("%d %d %d", &stStevil, &stIndeksov, &vsota);
    int* stevila = (int* ) malloc(stStevil * sizeof(int));

    for (int i = 0; i < stStevil; i++)
        scanf("%d", &stevila[i]);

    printf("%d\n", nacini(stevila, stStevil, stIndeksov, vsota, 0, 0, 0));

    return 0;
}

