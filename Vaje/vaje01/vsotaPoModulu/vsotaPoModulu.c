#include <stdio.h>

int main() {
    int a = 0;
    int b = 0;

    // char --> number
    a = getchar() - '0';
    getchar();
    b = getchar() - '0';
  
    int rezultat = (a + b) % 10;
    
    putchar(rezultat + '0');
    putchar('\n');
    
    return 0;
}
