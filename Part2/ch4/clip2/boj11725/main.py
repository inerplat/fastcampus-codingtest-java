import sys
sys.setrecursionlimit(10**6) # 최대 재귀 깊이 변경

def find(node):
    check[node] = True
    for child in tree[node]:
        if not check[child]:
            parents[child] = node
            find(child)

n = int(sys.stdin.readline().split()[0])
tree = [[] for _ in range(n + 1)]
parents = [0] * (n + 1)
check = [False] * (n + 1)

for _ in range(n - 1):
    node1, node2 = map(int, sys.stdin.readline().split())
    tree[node1].append(node2)
    tree[node2].append(node1)

find(1)

sys.stdout.write(''.join([str(parents[i]) + '\n' for i in range(2, n + 1)]))