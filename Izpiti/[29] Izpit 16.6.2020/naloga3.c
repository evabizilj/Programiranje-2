#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int n; 
char stevilo[10000];
void izpisi(int* t, int dodanihStevil, char* buff, int ix, int ixStevil);

int main()
{
    scanf("%d", &n);
    int tab[n];
    for (int i=0; i<n; i++)
        scanf("%d", &tab[i]);
    char buff[10000];
    buff[0] = '{';
    printf("%s\n", "{}");
    izpisi(tab, 0, buff, 1, 0);
    return 0;
}

void izpisi(int* t, int dodanihStevil, char* buff, int ix, int ixStevil){
    if(dodanihStevil >= n){
       
        return;
    }
    if(ixStevil >= n) return;
    //ne dodam nobene stevilke
    izpisi(t,dodanihStevil, buff, ix, ixStevil+1);
    //dodam novo stevilo
    
    sprintf(stevilo, "%d", t[ixStevil]);
    int len = strlen(stevilo);
    for (int i = 0; i < len; i++)
        buff[ix+i] = stevilo[i];
    ix += len;
    //izpis
    buff[ix] = '}'; 
    buff[ix+1] = '\0'; 
    printf("%s\n", buff);
    buff[ix] = ','; 
    buff[ix+1] = ' ';
    izpisi(t,dodanihStevil+1, buff, ix+2, ixStevil+1);
        
}