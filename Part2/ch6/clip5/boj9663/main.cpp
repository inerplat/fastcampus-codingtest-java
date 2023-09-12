#include <iostream>

int N;
int queenPosition[14];

bool isValid(int y, int x)
{
    for(int i = 0; i < y; i++)
    {
        if(queenPosition[i] == x || y - i == abs(x - queenPosition[i]))
        {
            return false;
        }
    }

    return true;
}

int func(int y) {
    int count = 0;

	if (y == N)
    {
		count = 1;
    }
    else
    {
        for(int x = 0; x < N; x++)
        {
            if(isValid(y, x) == true)
            {
                queenPosition[y] = x;
                count += func(y + 1);
            }
        }
    }
    
	return count;
}

int main() {
	scanf("%d", &N);
	printf("%d", func(0));
	return 0;
}