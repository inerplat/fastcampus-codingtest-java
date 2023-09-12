import sys

PLUS = 0
MINUS = 1
MUL = 2
DIV = 3

def solve(index, total):
    global max_val, min_val
    if index == n:
        max_val = max(max_val, total)
        min_val = min(min_val, total)
        return
    
    for i in range(4):
        if operators[i] > 0:
            operators[i] -= 1
            if i == PLUS:
                solve(index + 1, total + numbers[index])
            elif i == MINUS:
                solve(index + 1, total - numbers[index])
            elif i == MUL:
                solve(index + 1, total * numbers[index])
            elif i == DIV:
                solve(index + 1, int(total / numbers[index]))  # 정수 나눗셈
            operators[i] += 1

n = int(sys.stdin.readline())
numbers = list(map(int, sys.stdin.readline().split()))
operators = list(map(int, sys.stdin.readline().split()))

max_val = -sys.maxsize
min_val = sys.maxsize

solve(1, numbers[0])

print(max_val)
print(min_val)
