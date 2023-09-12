#include <iostream>

int N;
int W[10][10];
int result = 10000000;

void tsp(int number, int visited, int sum)
{
    if(sum < result)
    {
        if(visited == (1 << N) - 1)
        {
            if(W[number][0] > 0 && result > sum + W[number][0])
            {
                result = sum + W[number][0];
            }
        }
        else
        {
            for(int i = 0; i < N; i++)
            {
                if(W[number][i] > 0 && (visited & (1 << i)) == 0)
                {
                    tsp(i, visited | (1 << i), sum + W[number][i]);
                }
            }
        }
    }

    return;
}

int main()
{
    scanf("%d", &N);

    for(int j = 0; j < N; j++)
    {
        for(int i = 0; i < N; i++)
        {
            scanf("%d", &W[j][i]);
        }
    }

    tsp(0, 1, 0);
    printf("%d", result);

    return 0;
}