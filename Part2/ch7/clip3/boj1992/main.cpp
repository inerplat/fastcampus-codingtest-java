#include <iostream>

int N;
char board[64][65];

void compress(int r, int c, int length)
{
    bool same = true;
    for(int j = 0; j < length; j++)
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
        printf("%c", board[r][c]);
    }
    else
    {
        length /= 2;
        printf("(");
        compress(r, c, length);
        compress(r, c + length, length);
        compress(r + length, c, length);
        compress(r + length, c + length, length);
        printf(")");
    }

    return;
}

int main()
{
    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        scanf(" %s", &board[i][0]);
    }

    compress(0, 0, N);

    return 0;
}