import sys
sys.setrecursionlimit(10**6)

def solve(i, last):
    if last <= 0:
        return 0
    if i == 1:
        return last
    if mem[i][last] == -1:
        mem[i][last] = solve(i - 1, last // 2) + solve(i, last - 1)
    return mem[i][last]

t = int(sys.stdin.readline())
for _ in range(t):
    n, m = map(int, sys.stdin.readline().split())
    mem = [[-1] * (m + 1) for _ in range(n + 1)]

    print(solve(n, m))
