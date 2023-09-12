import sys

def solve(index, total):
    global answer
    if index == len(numbers):
        return
    if total + numbers[index] == s:
        answer += 1

    solve(index + 1, total)
    solve(index + 1, total + numbers[index])

n, s = map(int, sys.stdin.readline().split())
numbers = list(map(int, sys.stdin.readline().split()))
answer = 0

solve(0, 0)
print(answer)
