import sys
sys.setrecursionlimit(10**6)

def get_sum(node):
    if sum[node] != 0:
        return sum[node]
    check[node] = True
    result = 1
    for child in tree[node]:
        if not check[child]:
            result += get_sum(child)
    sum[node] = result
    return result

def init(n):
    parents = [0] * (n + 1)
    check = [False] * (n + 1)
    sum = [0] * (n + 1)
    tree = [[] for _ in range(n + 1)]
    return parents, check, sum, tree

n, r, q = map(int, sys.stdin.readline().split())
parents, check, sum, tree = init(n)

for _ in range(n - 1):
    u, v = map(int, sys.stdin.readline().split())
    tree[u].append(v)
    tree[v].append(u)

sum[r] = get_sum(r)

for _ in range(q):
    u = int(sys.stdin.readline())
    sys.stdout.write(str(sum[u]) + "\n")
