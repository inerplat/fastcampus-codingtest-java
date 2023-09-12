#include <iostream>

int n, m;

long long numberOfLotto[11][2001];

long long func(int depth, int maxNumber)
{
    if(maxNumber <= 0)
    {
        return 0;
    }
    else
    {
        if(-1 == numberOfLotto[depth][maxNumber])
        {
            numberOfLotto[depth][maxNumber] = func(depth - 1, maxNumber / 2) + func(depth, maxNumber - 1);
        }
    }

    return numberOfLotto[depth][maxNumber];
}

int main()
{
    for(int i = 1; i <= 2000; i++)
    {
        numberOfLotto[1][i] = i;
    }

    for(int j = 2; j <= 10; j++)
    {
        for(int i = 1; i <= 2000; i++)
        {
            numberOfLotto[j][i] = -1;
        }
    }

    int T;
    scanf("%d", &T);

    for(int t = 0; t < T; t++)
    {
        scanf("%d %d", &n, &m);

        printf("%lld\n", func(n, m));
    }

    return 0;
}