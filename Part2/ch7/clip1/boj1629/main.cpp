#include <iostream>

long long power(long long A, long long B, long long C)
{
    long long result = 0;

    if(1 == B)
    {
        result = A % C;
    }
    else
    {
        result = power(A, B / 2, C);
        result = (result * result) % C;

        if(B % 2 == 1)
        {
            result = (result * A) % C;
        }
    }

    return result;
}

int main()
{
    long long A, B, C;

    scanf("%lld %lld %lld", &A, &B, &C);

    printf("%lld", power(A, B, C));

    return 0;
}