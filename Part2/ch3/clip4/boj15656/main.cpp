#include <iostream>
#include <algorithm>

int N, M;
int inputNumber[7];
int number[7];

void func(int depth)
{
    if(depth == M)
    {
        for(int i = 0; i < M; i++)
        {
            printf("%d ", number[i]);
        }
        printf("\n");
    }
    else
    {
        for(int i = 0; i < N; i++)
        {
            number[depth] = inputNumber[i];

            func(depth + 1);
        }
    }

    return;
}

int main()
{
    scanf("%d %d", &N, &M);

    for(int i = 0; i < N; i++)
    {
        scanf("%d", &inputNumber[i]);
    }

    std::sort(&inputNumber[0], &inputNumber[N]);

    func(0);

    return 0;
}