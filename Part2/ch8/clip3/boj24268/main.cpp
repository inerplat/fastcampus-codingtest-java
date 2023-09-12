#include <iostream>

int N, d;
bool usedNumber[10];
int number[10];

int make_number(int depth)
{
    int result = -1;

    if(depth == d)
    {
        result = 0;
        for(int i = 0; i < depth; i++)
        {
            result = result * d + number[i];
        }

        if(result <= N)
        {
            result = -1;
        }
    }
    else
    {
        for(int i = ((0 == depth)?1:0); i < d; i++)
        {
            if(false == usedNumber[i])
            {
                usedNumber[i] = true;

                number[depth] = i;
                result = make_number(depth + 1);
                if(result != -1)
                {
                    break;
                }

                usedNumber[i] = false;
            }
        }
    }

    return result;
}

int main()
{
    scanf("%d %d", &N, &d);

    printf("%d", make_number(0));

    return 0;
}