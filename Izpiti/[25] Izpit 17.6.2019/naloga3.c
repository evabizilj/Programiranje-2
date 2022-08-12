#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Cell Cell;
struct Cell
{
    bool left;
    bool up;
    bool right;
    bool down;
};

Cell readCell()
{
    char* x = (char*) malloc(5 * sizeof(char));
    scanf("%s", x);
    Cell c = {x[0] == '1', x[1] == '1', x[2] == '1', x[3] == '1'};
    return c;
}

void printCell(Cell c)
{
    printf("%d%d%d%d", c.left, c.up, c.right, c.down);
}

char* solve(Cell** tab, int h, int w, char* path)
{
    int x = 0;
    int y = 0;
    for (char* c = path; *c != 0; ++c)
    {
        Cell pos = tab[y][x];
        switch (*c)
        {
        case '0':
            if (x == 0 || pos.left)
                return NULL;
            x -= 1;
            break;
        case '1':
            if (y == 0 || pos.up)
                return NULL;
            y -= 1;
            break;
        case '2':
            if (x == w - 1 || pos.right)
                return NULL;
            x += 1;
            break;
        case '3':
            if (y == h - 1 || pos.down)
                return NULL;
            y += 1;
            break;
        }
    }
    if (x == w - 1 && y == h - 1)
        return path;

    int pathLen = strlen(path);
    char* newPath = (char*) calloc(pathLen + 1, sizeof(char));
    strcpy(newPath, path);
    
    for (int i = 0; i < 4; ++i)
    {
        int lastStep = path[pathLen - 1] - '0';
        if (lastStep == (i + 2) % 4)
            continue;
        newPath[pathLen] = i + '0';
        // printf("Trying path %s\n", newPath);
        char* solution = solve(tab, h, w, newPath);
        if (solution != NULL)
            return solution;
    }
    return NULL;
}

int main()
{
    int n, m;
    scanf("%d %d", &m, &n);
    Cell** tab = (Cell**) malloc(m * sizeof(Cell*));
    for (int i = 0; i < m; ++i)
        tab[i] = (Cell*) malloc(n * sizeof(Cell));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            tab[i][j] = readCell();
    char* path = calloc(1, sizeof(char));
    char* solution = solve(tab, m, n, path);
    printf("%s\n", solution);
    return 0;
}