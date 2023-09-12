#include <iostream>

char str[100];
bool numberInSequence[101];

int ascii2int(char* str, int length)
{
    int result = 0;

    if(1 == length)
    {
        result = str[0] - '0';
    }
    else
    {
        if('0' != str[0] && '\0' != str[0])
        {
            result = (str[0] - '0') * 10 + str[1] - '0';
        }
    }

    return result;
}

bool dfs(int index)
{
    if(1 == index)
    {
        return true;
    }
    else
    {
        for(int len = 1; len <= 2; len++)
        {
            int number = ascii2int(&str[index - len], len);
            if(false == numberInSequence[number])
            {
                numberInSequence[number] = true;

                if(dfs(index - len) == true)
                {
                    printf("%d ", number);
                    return true;
                }

                numberInSequence[number] = false;
            }
        }
    }

    return false;
}

int main()
{
    scanf("%s", &str[1]);
    str[0] = '\0';

    for(int i = 0; i <= 100; i++)
    {
        numberInSequence[i] = true;
    }

    int strLength = 1;
    for(int i = 1; i <= 50; i++)
    {
        numberInSequence[i] = false;

        strLength += (i >= 10?2:1);
        if('\0' == str[strLength])
        {
            break;
        }
    }

    dfs(strLength);

    return 0;
}