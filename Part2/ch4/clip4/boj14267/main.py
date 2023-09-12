import sys
sys.setrecursionlimit(10**6) # 최대 재귀 깊이 변경

def next(node):
    for child in tree[node]:
        like[child] += like[node]
        next(child)

n, m = map(int, sys.stdin.readline().split())
parent = [0] * (n + 1)
like = [0] * (n + 1)
tree = [[] for _ in range(n + 1)]
p = sys.stdin.readline().split()

for i in range(1, n + 1):
    parent[i] = int(p[i - 1])
    if parent[i] != -1:
        tree[parent[i]].append(i)

for _ in range(m):
    employee, point = map(int, sys.stdin.readline().split())
    like[employee] += point

next(1)

sys.stdout.write(" ".join(map(str, like[1:])))
