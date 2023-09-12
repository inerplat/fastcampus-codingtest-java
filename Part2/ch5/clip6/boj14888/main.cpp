#include <iostream>

int N;
int A[11];
int countOfOperator[4];

typedef enum
{
    MIN_RESULT,
    MAX_RESULT
} compare_type_t;

int calculate(int index, compare_type_t compareType)
{
    int result = compareType == MAX_RESULT?-1000000000:1000000000;

    if(index == 0)
    {
        result = A[0];
    }
    else
    {
        int temp;

        for(int i = 0; i < 4; i++)
        {
            if(countOfOperator[i] > 0)
            {
                countOfOperator[i]--;

                switch(i)
                {
                case 0:
                    temp = calculate(index - 1, compareType) + A[index];
                    break;
                case 1:
                    temp = calculate(index - 1, compareType) - A[index];
                    break;
                case 2:
                    temp = calculate(index - 1, compareType) * A[index];
                    break;
                case 3:
                    temp = calculate(index - 1, compareType) / A[index];
                    break;
                }

                if(MAX_RESULT == compareType)
                {
                    if(result < temp)
                    {
                        result = temp;
                    }
                }
                else
                {
                    if(result > temp)
                    {
                        result = temp;
                    }
                }
    
                countOfOperator[i]++;
            }
        }
    }

    return result;
}

int main()
{
    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    for(int i = 0; i < 4; i++)
    {
        scanf("%d", &countOfOperator[i]);
    }

    printf("%d\n%d", calculate(N - 1, MAX_RESULT), calculate(N - 1, MIN_RESULT));

    return 0;
}