#include <iostream>

bool isValid(char str[])
{
    bool result = true;
    bool usedAlphabet['z' - 'a' + 1];

    for(int i = 0; i <= 'z' - 'a'; i++)
    {
        usedAlphabet[i] = false;
    }

    for(int i = 0; str[i] != '\0'; i++)
    {
        if(true == usedAlphabet[str[i] - 'a'])
        {
            result = false;
            break;
        }

        if(str[i + 1] != str[i])
        {
            usedAlphabet[str[i] - 'a'] = true;
        }
    }

    return result;
}

int main()
{
    int N;
    int count = 0;
    char str[101];

    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        scanf("%s", &str);
        count += isValid(str)?1:0;
    }

    printf("%d", count);

    return 0;
}