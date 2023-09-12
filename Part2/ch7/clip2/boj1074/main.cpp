#include <iostream>
#include <cmath>

int func(int N, int r, int c)
{
    int boardLength = pow(2, N);

    if (r >= boardLength || (r >= 0 && c >= boardLength))
    {
        return boardLength * boardLength;
    }
    else if(0 == N || r < 0 || (r < boardLength && c < 0))
    {
        return 0;
    }

    int result = 0;

    result += func(N - 1, r, c);
    result += func(N - 1, r, c - boardLength / 2);
    result += func(N - 1, r - boardLength / 2, c);
    result += func(N - 1, r - boardLength / 2, c - boardLength / 2);

    return result;
}

int main()
{
    int N, r, c;

    scanf("%d %d %d", &N, &r, &c);

    printf("%d", func(N, r, c));

    return 0;
}