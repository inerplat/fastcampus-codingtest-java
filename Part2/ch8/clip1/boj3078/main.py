import sys
from collections import deque

n, k = map(int, sys.stdin.readline().split())
students = [len(sys.stdin.readline().rstrip()) for _ in range(n)]

friends = [0] * 21
queue = deque()
sum_ = 0

for i in range(n):
    next_ = students[i]
    sum_ += friends[next_]
    
    queue.append(next_)
    friends[next_] += 1
    if len(queue) > k:
        out = queue.popleft()
        friends[out] -= 1

sys.stdout.write(str(sum_) + '\n')
