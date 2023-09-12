#include <iostream>

int N;
char sequence[81];

bool isBad(int endIndex)
{
    for(int j = 1; j <= (endIndex + 1) / 2; j++)
    {
        bool same = true;
        for(int i = 0; i < j; i++)
        {
            if(sequence[endIndex - i] != sequence[endIndex - j - i])
            {
                same = false;
            }
        }
        
        if(true == same)
        {
            return true;
        }
    }

    return false;
}

bool func(int endIndex)
{
    if(endIndex == N)
    {
        printf("%s", sequence);
        return true;
    }
    else
    {
        for(char number = '1'; number <= '3'; number++)
        {
            sequence[endIndex] = number;

            if(isBad(endIndex) == false)
            {
                if(func(endIndex + 1) == true)
                {
                    return true;
                }
            }
        }
    }

    return false;
}

int main()
{
    scanf("%d", &N);

    func(0);

    return 0;
}