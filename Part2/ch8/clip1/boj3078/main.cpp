#include <iostream>
#include <queue>
#include <cstring>

int main()
{
    int N, K;
    char name[21];
    int countOfNameLength[21];
    std::queue<int> nameLengthQueue;

    scanf("%d %d", &N, &K);

    long long sumOfPair = 0;
    memset(countOfNameLength, 0, sizeof(countOfNameLength));
    
    for(int i = 1; i <= N; i++)
    {
        scanf(" %s", name);
        int nameLength = strlen(name);
        sumOfPair += countOfNameLength[nameLength]++;
        nameLengthQueue.push(nameLength);
    
        if(i > K)
        {
            countOfNameLength[nameLengthQueue.front()]--;
            nameLengthQueue.pop();
        }
    }

    printf("%lld", sumOfPair);

    return 0;
}