import sys

LEFT = 0
RIGHT = 1

def solve(index, end, total):
    global answer
    if index == end:
        if status == LEFT:
            prev = cnt.get(total, 0)
            cnt[total] = prev + 1
        elif status == RIGHT:
            answer += cnt.get(s - total, 0)
    else:
        solve(index + 1, end, total)
        solve(index + 1, end, total + numbers[index])

n, s = map(int, sys.stdin.readline().split())
numbers = list(map(int, sys.stdin.readline().split()))
answer = 0
cnt = {}

status = LEFT
solve(0, n // 2, 0)

status = RIGHT
solve(n // 2, n, 0)

if s == 0:
    answer -= 1

print(answer)
