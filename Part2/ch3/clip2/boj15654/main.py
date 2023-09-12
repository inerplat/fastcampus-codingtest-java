def print_seq(target):
    print(" ".join(map(str, target)))

def perm(depth):
    if depth == m:
        print_seq(output)
        return

    for i in range(n):
        if not check[i]:
            check[i] = True
            output[depth] = numbers[i]
            perm(depth + 1)
            check[i] = False

n, m = map(int, input().split())
numbers = list(map(int, input().split()))
output = [0] * m
check = [False] * n

numbers.sort()
perm(0)
