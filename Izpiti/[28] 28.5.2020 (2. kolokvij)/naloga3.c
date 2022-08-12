
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


int iskani;
int tabela[1000];
int tabela2[1000];
int st = 0;
int st2 = 0;

int index1 = 0;



bool rek(){
   
    
    int el = tabela[index1];
    index1+=1;
    int stOtork = tabela[index1];
    index1+=1;
   // printf("index je: %d\n", index1);
    if(el == iskani){
        tabela2[st2] = el;
        st2+=1;
        return true;
    }
    if(stOtork > 0){
       
        for(int i=1; i<=stOtork; i++){
               
                    bool froc = rek(index1+i*2);
               
                    if(froc){
                        tabela2[st2] = el;
                        st2+=1;
                        return true;
                    }
                
           
        }
        
    }
    return false;
}


int main() {
  
    scanf("%d", &iskani);
    
    int trenutni;
    while(scanf("%d", &trenutni)>0){
        tabela[st] = trenutni;
        st+=1;
        if(trenutni == iskani) break;
    }
   
    bool je = rek(0);
  
    for(int i=st2-1; i>=0; i--){
        printf("%d\n", tabela2[i]);
    }

    return 0;
}
