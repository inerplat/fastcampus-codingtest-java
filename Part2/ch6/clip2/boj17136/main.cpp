#include <iostream>

int board[11][11];
int paper[6] = {0, 5, 5, 5, 5, 5};

bool isValid(int y, int x, int size)
{
    for(int j = 0; j < size; j++)
    {
        for(int i = 0; i < size; i++)
        {
            if(0 == board[y + j][x + i])
            {
                return false;
            }
        }
    }

    return true;
}

void setBoard(int y, int x, int size, int value)
{
    for(int j = 0; j < size; j++)
    {
        for(int i = 0; i < size; i++)
        {
            board[y + j][x + i] = value;
        }
    }

    return;
}

int result = 26;

void dfs(int y, int x, int numberOfPaper)
{
    if(result > numberOfPaper)
    {
        for(int size = 1; size <= 5; size++)
        {
            if(paper[size] > 0 && isValid(y, x, size) == true)
            {
                paper[size]--;
                setBoard(y, x, size, 0);

                int j;
                for(j = y; j < 10; j++)
                {
                    for(int i = 0; i < 10; i++)
                    {
                        if(1 == board[j][i])
                        {
                            dfs(j, i, numberOfPaper + 1);
                            j = 11;
                            break;
                        }
                    }
                }

                if(10 == j)
                {
                    result = numberOfPaper + 1;
                }

                paper[size]++;
                setBoard(y, x, size, 1);
            }
        }
    }
            
    return;
}

int main()
{
    for(int j = 0; j < 10; j++)
    {
        for(int i = 0; i < 10; i++)
        {
            scanf("%d", &board[j][i]);
        }
    }

    for(int j = 0; j < 10; j++)
    {
        for(int i = 0; i < 10; i++)
        {
            if(1 == board[j][i])
            {
                dfs(j, i, 0);

                if(26 == result)
                {
                    result = -1;
                }
                printf("%d", result);
                return 0;
            }
        }
    }

    printf("0");
    return 0;
}