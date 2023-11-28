/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20

int mazeInt[MAX][MAX];
int row = MAX, col = MAX;
int temp = 0;
void maze_make(int maze[MAX][MAX]) {
    srand(time(NULL));

    for (int k = 0; k < MAX; k++) {
        for (int i = 0; i < MAX; i++) {
            maze[k][i] = rand() % 2;
        }
    }

    int rowTmp = 0, colTmp = 0;
    while (maze[0][colTmp] == 0 && colTmp < col) colTmp++;
    if (colTmp == col) {
        while (maze[rowTmp][0] == 0 && rowTmp < row + 1) rowTmp++;
        maze[rowTmp][colTmp] = 1;
    }
    else {
        maze[colTmp][0] = 1;
    }

    rowTmp = row - 1, colTmp = col - 1;
    while (maze[rowTmp][colTmp] == 0 && colTmp >= 0) colTmp--;
    if (colTmp < 0) {
        while (maze[rowTmp][colTmp] == 0 && rowTmp >= 0) rowTmp--;
        maze[rowTmp][colTmp] = 1;
    }
    else {
        maze[rowTmp][colTmp] = 1;
    }
}

void maze_print(int maze[MAX][MAX]) {
    for (int r = 0; r < row + 1; r++) {
        for (int c = 0; c < col; c++) {
            printf("%2d", maze[r][c]);
        }
        printf("\n");
    }
}

int maze_dfs(int maze[MAX][MAX], int start_row, int start_col, int visited[MAX][MAX]) {
    int r = start_row, c = start_col;
    visited[r][c] = 1;

    if (r == row - 1 && c == col - 1) {
        printf("Exit found! row :%d,col:%d\n", r + 1, c + 1);
        return 1;
    }

    if (c > 0 && maze[r][c - 1] == 1 && visited[r][c - 1] == 0) { // left
        return maze_dfs(maze, r + 1, c - 1, visited);
    }
    if (c < col - 1 && maze[r][c + 1] == 1 && visited[r][c + 1] == 0) { // right
        return maze_dfs(maze, r + 1, c + 1, visited);
    }
    if (r > 0 && maze[r - 1][c] == 1 && visited[r - 1][c] == 0) { // top
        return maze_dfs(maze, r, c, visited);
    }
    if (r < row && maze[r + 1][c] == 1 && visited[r + 1][c] == 0) { // bottom
        return maze_dfs(maze, r + 2, c, visited);
    }

    return 0;
}

int main() {
    maze_make(mazeInt);
    int start_row = 0, start_col = 0;
    while (maze_dfs(mazeInt, start_row, start_col, mazeInt) == 0) {
        temp++;
        printf("no exist path to maze\n");
        srand(time(NULL));
        maze_make(mazeInt);
        printf("temp: %d\n", temp);
    }
    maze_print(mazeInt);

    return 0;
}*/