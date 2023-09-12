#include <iostream>
#include <vector>

std::vector<int> tree[100001];
int sum[100001];
bool check[100001];

int getSum(int nodeNumber)
{
    if(sum[nodeNumber] != 0)
    {
        return sum[nodeNumber];
    }

    check[nodeNumber] = true;
    sum[nodeNumber] = 1;

    for(int child : tree[nodeNumber])
    {
        if(false == check[child])
        {
            sum[nodeNumber] += getSum(child);
        }
    }

    return sum[nodeNumber];
}

int main()
{
    int N, R, Q, U, V;
    scanf("%d %d %d", &N, &R, &Q);
    for(int i = 0; i < N - 1; i++)
    {
        scanf("%d %d", &U, &V);
        tree[U].push_back(V);
        tree[V].push_back(U);
    }

    getSum(R);

    for(int i = 0; i < Q; i++)
    {
        scanf("%d", &U);
        printf("%d\n", sum[U]);
    }

    return 0;
}