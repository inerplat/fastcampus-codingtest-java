#include <iostream>
#include <algorithm>

int N, M;
int inputNumber[8];
int number[8];

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
        int temp = 0;
        for(int i = 0; i < N; i++)
        {
            if(inputNumber[i] != 0)
            {
                number[depth] = inputNumber[i];

                temp = inputNumber[i];
                inputNumber[i] = 0;

                func(depth + 1);

                inputNumber[i] = temp;
            }
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