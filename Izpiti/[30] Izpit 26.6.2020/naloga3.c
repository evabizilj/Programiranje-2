#include <stdio.h>
#include <stdbool.h>

bool resi() {
    char znak = getchar();

    if(znak == 'T') return true;
    if(znak == 'F') return false;
    if(znak == '!') return !resi();

    bool a = resi();
    bool b = resi();

    if(znak == '&') return a && b;
    if(znak == '|') return a || b;
}

int main() {
    puts(resi() ? "T" : "F");
}
