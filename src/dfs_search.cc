#include <stdio.h>
#include "func.h"

int Array[5][4] = {
    {0, 0, 1, 0},
    {0, 0, 0, 0},
    {0, 0, 1, 0},
    {0, 1, 0, 0},
    {0, 0, 0, 1},
};

int Book[5][4] = {};
int startx = 0, starty = 0, endx = 3, endy = 2;
int min = 1000000;
/*
 * @brief   Deep first search algorithm
 * @param   step: step number
 * find the short path from the start node to the end node
 */ 
void dfs(int x, int y, int step) {
    /* next step, right, down, left, up */
    int next[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    if (x == endx && y == endy) {
        if (step < min) {
            min = step;
        }
        return;
    }

    for (int i = 0; i < 4; i++) {
        int newx = x + next[i][0];
        int newy = y + next[i][1];
        if (newx < 0 || newy < 0 || newx >= 5 || newy >= 4) {
            continue;
        }
        if (Array[newx][newy] == 0 && Book[newx][newy] == 0) {
            Book[newx][newy] = 1;
            dfs(newx, newy, step + 1);
            Book[newx][newy] = 0;
        }
    }
    return;
}

int dfs_test() {
    int step = 0;
    Book[startx][starty] = 1;
    dfs(startx, starty, 0);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", Book[i][j]);
        }
        printf("\n");
    }
    printf("min: %d\n", min);
    return 0;
}