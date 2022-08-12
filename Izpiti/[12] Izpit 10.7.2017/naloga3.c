#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

// 100%
struct Stack
{
    int data;
    struct Stack *next;
};

typedef struct Stack s;
s *top = NULL, *new;

void push(int data)
{
    new = (s *)malloc(sizeof(s));
    new->data = data;
    new->next = NULL;
    
    if (!top)
        top = new;
    else
    {
        new->next = top;
        top = new;
    }
}

void pop()
{
    s *temp = top;
    top = top->next;
    free(temp);
}


int isBalanced(char* s) {
    int i = 0,j = 0;
    char c[strlen(s) - 1];


   for (i = 0; i <= strlen(s) - 1; i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i]=='[')
            c[j++] = s[i];
        else
        {
            if (s[i] == ')' && c[--j] == '(')
            ;
            else
            {
                if (s[i] == '}' && c[--j] == '{')
                ;
                else
                {
                    if (s[i]==']'&&c[--j]=='[')
                    ;
                    else
                        return 0;

                        }
                }
        }
    }
    if (j == 0)
        return 1;
    return 0;
}

int main() 
{
    int n; 
    int sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        char* s = (char *)malloc(1000 * sizeof(char));
        scanf("%s", s);
        sum += isBalanced(s);
    }
    printf("%d\n", sum);
    return 0;
}

