import sys

def find_permutation(depth):
    if depth == d:
        result = 0
        for i in range(depth):
            result *= d
            result += number[i]
        return result

    start = 0
    if depth == 0:
        start = 1
    for i in range(start, d):
        if not used_number[i]:
            used_number[i] = True
            number[depth] = i
            num = find_permutation(depth + 1)
            if num > n:
                return num
            used_number[i] = False
    return -1

n, d = map(int, sys.stdin.readline().split())
used_number = [False] * d
number = [0] * d

result = find_permutation(0)
sys.stdout.write(str(result) + '\n')
