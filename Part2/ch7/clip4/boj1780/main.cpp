#include <iostream>

int board[2187][2187];
int countOfPaper[3] = {0, 0, 0};

void dfs(int r, int c, int length)
{
    bool same = true;
    for(int j = 0; true == same && j < length; j++)
    {
        for(int i = 0; i < length; i++)
        {
            if(board[r][c] != board[r + j][c + i])
            {
                same = false;
                break;
            }
        }
    }

    if(true == same)
    {
        countOfPaper[board[r][c]]++;
    }
    else
    {
        for(int j = 0; j < length; j += length / 3)
        {
            for(int i = 0; i < length; i += length / 3)
            {
                dfs(r + j, c + i, length / 3);
            }
        }
    }

    return;
}

int main()
{
    int N;
    scanf("%d", &N);

    for(int j = 0; j < N; j++)
    {
        for(int i = 0; i < N; i++)
        {
            scanf("%d", &board[j][i]);
            board[j][i]++;
        }
    }

    dfs(0, 0, N);

    printf("%d\n%d\n%d", countOfPaper[0], countOfPaper[1], countOfPaper[2]);


    return 0;
}