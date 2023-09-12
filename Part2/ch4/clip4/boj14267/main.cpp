#include <iostream>
#include <vector>

std::vector<int> subordinate[100001];
int compliment[100001];
int sumOfCompliment[100001];

void update_compliment(int number, int sum)
{
    sum += compliment[number];

    sumOfCompliment[number] = sum;

    for(int subNumber : subordinate[number])
    {
        update_compliment(subNumber, sum);
    }
}

int main()
{
    int n, m;

    scanf("%d %d %*d", &n, &m);

    int i;
    for(int j = 2; j <= n; j++)
    {
        scanf("%d", &i);
        subordinate[i].push_back(j);
    }

    int number, c;
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &number, &c);
        compliment[number] += c;
    }

    update_compliment(1, 0);

    for(int i = 1; i <= n; i++)
    {
        printf("%d ", sumOfCompliment[i]);
    }

    return 0;
}