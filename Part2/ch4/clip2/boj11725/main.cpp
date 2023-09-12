#include <iostream>
#include <vector>

std::vector<int> connectedNode[100001];
int parentNode[100001];

void search_child(int number)
{
    for(int nextNode : connectedNode[number])
    {
        if(parentNode[nextNode] == 0)
        {
            parentNode[nextNode] = number;

            search_child(nextNode);
        }
    }

    return;
}

int main()
{
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N - 1; i++)
    {
        int node[2];
        scanf("%d %d", &node[0], &node[1]);

        connectedNode[node[0]].push_back(node[1]);
        connectedNode[node[1]].push_back(node[0]);
    }

    search_child(1);

    for(int i = 2; i <= N; i++)
    {
        printf("%d\n", parentNode[i]);
    }

    return 0;
}