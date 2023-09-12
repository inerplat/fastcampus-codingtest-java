#include <iostream>

int N, S;
int sequence[20];

int find_sequence(int startIndex, int sum)
{
    int result = 0;

    if(sum == S)
    {
        result += 1;
    }

    for(int i = startIndex; i < N; i++)
    {
        result += find_sequence(i + 1, sum + sequence[i]);
    }

    return result;
}

int main()
{

    scanf("%d %d", &N, &S);

    for(int i = 0; i < N; i++)
    {
        scanf("%d", &sequence[i]);
    }

    printf("%d", find_sequence(0, 0) - (S == 0 ? 1 : 0));

    return 0;
}