#include <stdio.h>
#include <stdlib.h>
char MEMO[1001][1001];
void obrni(FILE* vhod, FILE* izhod){
    int vrstic = 0; int stolpcev = 0;
    char znak;
    while(fscanf(vhod, "%c", &znak) != EOF){
        if(znak == '\n'){
            MEMO[vrstic][stolpcev]='\0'; vrstic+=1; stolpcev=0;
        }else{
            MEMO[vrstic][stolpcev]=znak; stolpcev+=1;
        }
    }
    MEMO[vrstic][stolpcev]='\0';
    for(int i=vrstic; i>=0; i--){
        fprintf(izhod, "%s\n", MEMO[i]);
    }
    return;
}
int main(){
    FILE* fp = fopen("vhod.log", "r");
    FILE* fo = fopen("izhod.log", "w");
    obrni(fp,fo);
    fclose(fp); fclose(fo);
    return 0;
}