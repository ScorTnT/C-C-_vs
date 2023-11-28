/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20

typedef int element;
typedef struct StackList {
    element point[2];   // point[0] : row , point[1] : col
    int cnt;
    struct StackList* down;
} StackList;

StackList* push(StackList* S, int a, int b);
StackList* pop(StackList* S);
int empty(StackList* S);
void maze_print(int maze[MAX][MAX], int row, int col);
int maze_dfs(int maze[MAX][MAX], StackList* S, int visited[MAX][MAX], int row, int col);
void generateMaze(int maze[MAX][MAX], int row, int col);
int findExit(int maze[MAX][MAX], int row, int col);

int main() {
    int mazeInt[MAX][MAX];
    int row = MAX;
    int col = MAX;
    int foundExit = 0;
    int iterationCount = 0;

    while (!foundExit) {
        iterationCount++;
        generateMaze(mazeInt, row, col);

        StackList* Stack = (StackList*)malloc(sizeof(StackList));
        Stack->point[0] = 0;
        Stack->point[1] = 0;
        Stack->cnt = 0;
        Stack->down = NULL;

        int visited[MAX][MAX] = { 0 };

        printf("미로의 출구를 찾는 중...\n");
        foundExit = maze_dfs(mazeInt, Stack, visited, row, col);
        if (foundExit) {
            printf("미로의 출구를 찾았습니다!\n");
            printf("반복 횟수: %d\n", iterationCount);
        }
        else {
            printf("미로의 출구를 찾지 못했습니다. 다시 시도합니다.\n");
        }
        printf("\n");

        free(Stack);
    }

    return 0;
}

void generateMaze(int maze[MAX][MAX], int row, int col) {
    srand(time(NULL));

    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            if (r == 0 || c == 0 || r == row - 1 || c == col - 1)
                maze[r][c] = 0;  // 테두리는 벽으로 설정
            else
                maze[r][c] = rand() % 2;  // 난수를 사용해 0 또는 1로 미로 생성
        }
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
    if (empty(S)) {
        printf("Stack empty.\n");
        return S;
    }
    StackList* p = S->down;
    free(S);
    return p;
}

int empty(StackList* S) {
    return (S->cnt == 0);
}

int maze_dfs(int maze[MAX][MAX], StackList* S, int visited[MAX][MAX], int row, int col) {
    int r = S->point[0];
    int c = S->point[1];
    element fin[2];
    visited[r][c] = 1;

    if (r == row - 1 || c == col - 1) {
        fin[0] = r;
        fin[1] = c;
        return 1;  // 출구를 찾은 경우 종료
    }

    if (c > 0 && maze[r][c - 1] == 1 && visited[r][c - 1] == 0) {  // left
        S = push(S, r, c - 1);
        if (maze_dfs(maze, S, visited, row, col))
            return 1;
        S = pop(S);
    }
    if (c < col - 1 && maze[r][c + 1] == 1 && visited[r][c + 1] == 0) {  // right
        S = push(S, r, c + 1);
        if (maze_dfs(maze, S, visited, row, col))
            return 1;
        S = pop(S);
    }
    if (r > 0 && maze[r - 1][c] == 1 && visited[r - 1][c] == 0) {  // top
        S = push(S, r - 1, c);
        if (maze_dfs(maze, S, visited, row, col))
            return 1;
        S = pop(S);
    }
    if (r < row - 1 && maze[r + 1][c] == 1 && visited[r + 1][c] == 0) {  // bottom
        S = push(S, r + 1, c);
        if (maze_dfs(maze, S, visited, row, col))
            return 1;
        S = pop(S);
    }

    return 0;
}*/