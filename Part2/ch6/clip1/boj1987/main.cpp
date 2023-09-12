#include <iostream>

int R, C;
char board[22][22];
int visited[22][22];
int maxLength = 0;

struct
{
    int r;
    int c;
} direction[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void dfs(int r, int c, int length, int route)
{
    if(maxLength < length)
    {
        maxLength = length;
    }

    visited[r][c] = route;

    for(int i = 0; i < 4; i++)
    {
        int nextR = r + direction[i].r, nextC = c + direction[i].c;

        if(((route & (1 << board[nextR][nextC])) == 0)
        && (visited[nextR][nextC] != (route | (1 << board[nextR][nextC]))))
        {
            dfs(nextR, nextC, length + 1, route | (1 << board[nextR][nextC]));
        }
    }

    return;
}

int main()
{
    scanf("%d %d" ,&R ,&C);

    for(int j = 1; j <= R; j++)
    {
        getchar();
        for(int i = 1; i <= C; i++)
        {
            board[j][i] = getchar() - 'A' + 1;
        }
    }

    dfs(1, 1, 1, 1 | (1 << board[1][1]));

    printf("%d", maxLength);

    return 0;
}