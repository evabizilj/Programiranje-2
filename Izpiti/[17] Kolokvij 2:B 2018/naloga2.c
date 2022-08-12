#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

int nacini(int stSedezev, int stLjudi, int prejsnji, int trenutni)
{
    // false 
    if (stLjudi < 0 || stSedezev < 0 || (prejsnji == 1 && prejsnji == trenutni))
        return 0;
    
    // true
    if (stLjudi == 0 && stSedezev == 0)
        return 1;
    
    // 2 možnosti: osebo posedemo ali jo ne posedemo
    int da = nacini(stSedezev - 1, stLjudi - 1, trenutni, 1);
    int ne = nacini(stSedezev - 1, stLjudi, trenutni, 0);

    return da + ne;
}

int main()
{
    int stSedezev;
    int stLjudi;

    scanf("%d %d", &stSedezev, &stLjudi);

    printf("%d\n", nacini(stSedezev, stLjudi, 0, 0));

    return 0;
}