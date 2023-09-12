#include <iostream>
#include <algorithm>

int L, C;
char character[15];
char password[16];

int isVowel(char ch)
{
    switch(ch)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        return 1;
    }

    return 0;
}

void make_password(int length, int index, int countOfVowels)
{
    if(length == L)
    {
        if(countOfVowels >= 1 && L - countOfVowels >= 2)
        {
            printf("%s\n", password);
        }
    }
    else
    {
        for(int i = index; i < C; i++)
        {
            password[length] = character[i];
            make_password(length + 1, i + 1, countOfVowels + isVowel(character[i]));
        }
    }

    return;
}

int main()
{
    scanf("%d %d", &L, &C);

    for(int i = 0; i < C; i++)
    {
        scanf(" %c", &character[i]);
    }

    std::sort(&character[0], &character[C]);

    make_password(0, 0, 0);

    return 0;
}