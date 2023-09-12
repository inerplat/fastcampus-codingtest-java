import sys

def solve(end_index):
    if end_index == n:
        for i in range(n):
            print(numbers[i], end='')
        return True
    else:
        for i in range(1, 4):
            numbers[end_index] = i
            if not is_bad(end_index):
                if solve(end_index + 1):
                    return True
    return False

def is_bad(end_index):
    for i in range(1, (end_index + 1) // 2 + 1):
        is_same = True
        for j in range(i):
            if numbers[end_index - j] != numbers[end_index - i - j]:
                is_same = False
                break
        if is_same:
            return True
    return False

n = int(sys.stdin.readline())
numbers = [0] * 80
solve(0)
