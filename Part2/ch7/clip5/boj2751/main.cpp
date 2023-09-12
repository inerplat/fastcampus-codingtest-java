#include <iostream>

int number[1000000];
int buffer[1000000];

void sort(int beginIndex, int endIndex)
{
    int length = endIndex - beginIndex;
    if(length > 1)
    {
        sort(beginIndex, beginIndex + length / 2);
        sort(beginIndex + length / 2, endIndex);

        int firstIndex = beginIndex, secondIndex = beginIndex + length / 2;
        int bufferIndex = beginIndex;
    
        for(; firstIndex < beginIndex + length / 2 && secondIndex < endIndex; bufferIndex++)
        {
            if(number[firstIndex] < number[secondIndex])
            {
                buffer[bufferIndex] = number[firstIndex++];
            }
            else
            {
                buffer[bufferIndex] = number[secondIndex++];
            }
        }

        for(; firstIndex < beginIndex + length / 2; bufferIndex++, firstIndex++)
        {
            buffer[bufferIndex] = number[firstIndex];
        }

        for(; secondIndex < endIndex; bufferIndex++, secondIndex++)
        {
            buffer[bufferIndex] = number[secondIndex];
        }

        for(int i = beginIndex; i < endIndex; i++)
        {
            number[i] = buffer[i];
        }
    }

    return;
}

int main()
{
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        scanf("%d", &number[i]);
    }

    sort(0, N);

    for(int i = 0; i < N; i++)
    {
        printf("%d\n", number[i]);
    }

    return 0;
}