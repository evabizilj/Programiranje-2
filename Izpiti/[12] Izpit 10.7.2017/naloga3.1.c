
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int odmik = 0;
int dolzina = 0;

bool ujema(char trenuntiOklepaj, char prebraniOklepaj) {

    if (trenuntiOklepaj == '(') {

        if (prebraniOklepaj == ')') {
            return true;
        }
        return false;
    }
    else if (trenuntiOklepaj == '{') {
        
        if (prebraniOklepaj == '}') {
            return true;
        }
        return false;
    }
    else if (trenuntiOklepaj == '[') {
        
        if (prebraniOklepaj == ']') {
            return true;
        }
        return false;
    }

    return false;
}

bool istiTip(char trenuntiOklepaj, char prebraniOklepaj) {

    if (trenuntiOklepaj == '(' || trenuntiOklepaj == ')') {

        if (prebraniOklepaj == '(' || prebraniOklepaj == ')') {
            return true;
        }
        return false;
    }
    else if (trenuntiOklepaj == '{' || trenuntiOklepaj == '}') {
        
        if (prebraniOklepaj == '{' || prebraniOklepaj == '}') {
            return true;
        }
        return false;
    }
    else if (trenuntiOklepaj == '[' || trenuntiOklepaj == ']') {
        
        if (prebraniOklepaj == ']' || prebraniOklepaj == ']') {
            return true;
        }
        return false;
    }

    return false;
}

int oklepaji (char* niz, char trenutniOklepaj, int index) {

    int sum = 0;
    if (ujema(trenutniOklepaj,niz[index]))
    sum++;

    return sum; 

}


int main() {

    int n;
    scanf("%d", &n);

    char** nizi = malloc(sizeof(char*) * n);

    for (int i = 0; i < n; i++) {
        nizi[i] = malloc(sizeof(char) * 10000);
        scanf("%s", nizi[i]);
    }

    printf("%d\n", oklepaji(niz, "", 0));




    return 0;
}