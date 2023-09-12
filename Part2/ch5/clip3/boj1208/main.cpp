#include <iostream>

int N, S;
int sequence[40];
int numberOfSequence[4000001];
bool leftSequence = true;
long long result = 0;

void find_sequence(int index, int endIndex, int sum)
{
    if(index == endIndex)
    {
        if(true == leftSequence)
        {
            numberOfSequence[sum + 2000000]++;
        }
        else
        {
            if(S - sum + 2000000 >= 0 && S - sum + 2000000 <= 4000000)
            {
                result += numberOfSequence[S - sum + 2000000];
            }
        }
    }
    else
    {
        find_sequence(index + 1, endIndex, sum);
        find_sequence(index + 1, endIndex, sum + sequence[index]);
    }

    return;
}

int main()
{
    scanf("%d %d", &N, &S);

    for(int i = 0; i < N; i++)
    {
        scanf("%d", &sequence[i]);
    }

    find_sequence(0, N / 2, 0);
    leftSequence = false;
    find_sequence(N / 2, N, 0);

    printf("%lld", result - (0==S?1:0));

    return 0;
}