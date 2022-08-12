
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char** argv) {
    char* name = argv[1];
    int n = atoi(argv[2]);
    int k = atoi(argv[3]);
    int vrstice = 1;
    int besede = 1;
    FILE* in = fopen(name, "r");
   // bool delaj = true;
    char znak;
    char* beseda = malloc(1001*sizeof(char));
    while(fscanf(in, "%c", &znak) >0){
        if(znak==' ') besede+=1;
      //  printf("vrstice je: %d, n je: %d\t besede je %d in k je %d\n", vrstice, n, besede, k);
        if(vrstice == n && besede == k){
            //preberem besedo in koncam
            
            if(znak == ' '){
                //printf("tukaj:::");
               fscanf(in, "%s", beseda); 
            }else{
                int st = 0;
                beseda[st] = znak;
                st+=1;
                while(fscanf(in, "%c", &znak) >0){
                  //  printf("znak je: %c\n", znak);
                    if(znak == ' ' || znak =='\n') break;
                    beseda[st] = znak;
                    st+=1;
                }
                beseda[st] = '\0';
            }
            break;
        }
        if(znak == '\n'){ vrstice+=1; besede=1;}
    }
    printf("%s\n", beseda);


    free(beseda);
    fclose(in);
    return 0;
}
