import sys

def travel(start, node, total_cost, count):
    global answer
    if count == n and start == node:
        answer = min(answer, total_cost)
        return
    for i in range(n):
        if w[node][i] != 0 and not visited[i]:
            visited[i] = True
            travel(start, i, total_cost + w[node][i], count + 1)
            visited[i] = False

n = int(sys.stdin.readline())
w = []
for _ in range(n):
    w.append(list(map(int, sys.stdin.readline().split())))

visited = [False] * n
answer = float('inf')
travel(0, 0, 0, 0)

print(answer)
