#include <iostream>
#include <string>

int main()
{
    std::string str, bomb;
    int bombSize;
    char input[1000001];

    std::cin >> input >> bomb;
    bombSize = bomb.size();

    for(int i = 0; input[i] != '\0'; i++)
    {
        str += input[i];

        if(str.size() >= bombSize && str.compare(str.size() - bombSize, bombSize, bomb) == 0)
        {
            str = str.erase(str.size() - bombSize, bombSize);
        }
    }

    if(str.empty() == true)
    {
        str = "FRULA";
    }

    std::cout << str;

    return 0;
}