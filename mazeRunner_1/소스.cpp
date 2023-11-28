#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#define MAX 20

typedef int element;
typedef struct StackList {
    element point[2];   //point[0] : row , point[1] : col
    int cnt;
    struct StackList* down;
}StackList;
StackList* push(StackList* S, int a, int b);
StackList* pop(StackList* S);
int empty(StackList* S);
void maze_print(int maze[MAX][MAX]);
int row = 0, col = 0;
int maze_dfs(int maze[MAX][MAX], StackList* S, int visited[MAX][MAX]);
int main() {

    FILE* fp = fopen("maze.txt", "r");
    if (fp == NULL) {
        printf("error maze file");
        return 0;
    }

    int mazeInt[MAX][MAX];
    char bf;
    while ((bf = fgetc(fp)) != EOF) {
        if (bf == '\n') {
            row++;
            col = 0;
        }
        else {
            mazeInt[row][col] = bf - '0';
            col++;
        }
    }
    fclose(fp);
    maze_print(mazeInt);

    int rowTmp = 0, colTmp = 0;
    while (mazeInt[0][colTmp] == 0 && colTmp < col) colTmp++;
    if (colTmp == col) {
        while (mazeInt[rowTmp][0] == 0 && rowTmp < row + 1) rowTmp++;
        colTmp = 0;
    }
    else
    {
        rowTmp = 0;
    }
    StackList* Stack = (StackList*)malloc(sizeof(StackList));
    Stack->point[0] = rowTmp + 1;
    Stack->point[1] = colTmp;
    Stack->cnt = 0;
    Stack->down = NULL;

    int visited[MAX][MAX] = { 0 };
    maze_dfs(mazeInt, Stack, visited);
    return 0;
}
void maze_print(int maze[MAX][MAX])
{
    for (int r = 0; r < row + 1; r++) {
        for (int c = 0; c < col; c++) {
            printf("%d", maze[r][c]);
        }
        printf("\n");
    }
}
StackList* push(StackList* S, int a, int b) {
    StackList* p = (StackList*)malloc(sizeof(StackList));
    p->cnt = S->cnt + 1;
    p->point[0] = a;
    p->point[1] = b;
    p->down = S;
    return p;
}
StackList* pop(StackList* S) {
    if (empty(S) == 1) {
        printf("Stack empty.\n");
        return S;
    }
    StackList* p = S->down;
    free(S);
    return p;
}
int empty(StackList* S) {
    if (S->cnt == 0) return 1;
    return 0;
}
int maze_dfs(int maze[MAX][MAX], StackList* S, int visited[MAX][MAX]) {
    int r = S->point[0] - 1;
    int c = S->point[1];
    element fin[2];
    visited[r][c] = 1;

    if (r == row || c == col - 1) {
        fin[0] = r + 1;
        fin[1] = c + 1;
        printf("Exit found! row :%d,col:%d\n", fin[0], fin[1]);
        StackList* seq = (StackList*)malloc(sizeof(StackList));
        seq->cnt = 1;
        seq->down = NULL;
        while (S != NULL) {
            seq = push(seq, S->point[0], S->point[1]);
            printf("(%d, %d)\n", S->point[0], S->point[1] + 1);
            S = S->down;
        }
        int temp = 1;
        int k = seq->cnt;
        while (temp != k) {
            short y = (seq->point[0]-1);
            short x = (seq->point[1]);
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
            printf("@");
            getchar();
            seq = seq->down;
            temp++;
        }
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {1,20 });
        return 0;
    }

    if (c > 0 && maze[r][c - 1] == 1 && visited[r][c - 1] == 0) { // left
        S = push(S, r + 1, c - 1);
        maze_dfs(maze, S, visited);
        S = pop(S);
    }
    if (c < col - 1 && maze[r][c + 1] == 1 && visited[r][c + 1] == 0) { // right
        S = push(S, r + 1, c + 1);
        maze_dfs(maze, S, visited);
        S = pop(S);
    }
    if (r > 0 && maze[r - 1][c] == 1 && visited[r - 1][c] == 0) { // top
        S = push(S, r, c);
        maze_dfs(maze, S, visited);
        S = pop(S);
    }
    if (r < row && maze[r + 1][c] == 1 && visited[r + 1][c] == 0) { // bottom
        S = push(S, r + 2, c);
        maze_dfs(maze, S, visited);
        S = pop(S);
    }
    return 0;
}