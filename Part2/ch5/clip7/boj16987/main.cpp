#include <iostream>

int N;
int S[8], W[8];

int result = 0;

void dfs(int index)
{
    if(index == N)
    {
        int count = 0;
        for(int i = 0; i < N; i++)
        {
            if(S[i] <= 0)
            {
                count++;
            }
        }

        if(result < count)
        {
            result = count;
        }
    }
    else
    {
        if(S[index] > 0)
        {
            bool collision = false;

            for(int i = 0; i < N; i++)
            {
                if(i != index && S[i] > 0)
                {
                    collision = true;
                    S[index] -= W[i];
                    S[i] -= W[index];

                    dfs(index + 1);

                    S[index] += W[i];
                    S[i] += W[index];
                }
            }
        
            if(false == collision)
            {
                dfs(index + 1);
            }
        }
        else
        {
            dfs(index + 1);
        }
    }
}

int main()
{
    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        scanf("%d %d", &S[i], &W[i]);
    }

    dfs(0);

    printf("%d", result);

    return 0;
}