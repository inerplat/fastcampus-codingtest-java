def print_seq(arr):
    print(" ".join(map(str, arr)))

def perm(arr, output, check, depth, n, m, start):
    if depth == m:
        print_seq(output)
        return

    for i in range(start, n):
        if not check[i]:
            check[i] = True
            output[depth] = arr[i]
            perm(arr, output, check, depth + 1, n, m, i + 1)
            check[i] = False

n, m = map(int, input().split())
numbers = list(map(int, input().split()))
numbers.sort()

perm(numbers, [0] * m, [False] * n, 0, n, m, 0)
