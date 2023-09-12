#include <iostream>
#include <vector>

struct edge_t
{
    int number;
    int length;
};

std::vector<edge_t> node[100001];
int result = 0;

int dfs(int number, int parentNumber)
{
    int maxLengthFromLeaf[2] = {0, 0};

    for(edge_t edge : node[number])
    {
        if(edge.number != parentNumber)
        {
            int temp = dfs(edge.number, number) + edge.length;
            
            if(temp > maxLengthFromLeaf[0])
            {
                maxLengthFromLeaf[1] = maxLengthFromLeaf[0];
                maxLengthFromLeaf[0] = temp;
            }
            else if(temp > maxLengthFromLeaf[1])
            {
                maxLengthFromLeaf[1] = temp;
            }
        }
    }

    if(maxLengthFromLeaf[0] + maxLengthFromLeaf[1] > result)
    {
        result = maxLengthFromLeaf[0] + maxLengthFromLeaf[1];
    }

    return maxLengthFromLeaf[0];
}

int main()
{
    int V;
    scanf("%d", &V);

    for(int i = 0; i < V; i++)
    {
        int nodeNumber, number, length;
        scanf("%d", &nodeNumber);
        for(;;)
        {
            scanf("%d", &number);
            if(-1 == number)
            {
                break;
            }
            else
            {
                scanf("%d", &length);

                node[nodeNumber].push_back({number, length});
            }
        }
    }

    dfs(1, 0);

    printf("%d", result);

    return 0;
}