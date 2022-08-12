#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int main() 
{
    int n;
    scanf("%d ", &n);

    bool prvaCrka = false;

    char ch = getchar();

    // prvi znak
    if (isalpha(ch))
    {
        ch = toupper(ch);
        prvaCrka = false;
    }

    while (ch != '\n')
    {
        if (isalpha(ch))
        {
            if (prvaCrka)
            {
                prvaCrka = false;
                ch = toupper(ch);
            }
        }
        if (!isalpha(ch))
            prvaCrka = true;
        
        putchar(ch);
        ch = getchar();
    }   

    printf("\n");
    return 0;
}
