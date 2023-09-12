def print_seq(arr):
    print(" ".join(map(str, arr)))

def perm(arr, output, depth, n, m):
    if depth == m:
        print_seq(output)
        return

    for i in range(n):
        output[depth] = arr[i]
        perm(arr, output, depth + 1, n, m)

n, m = map(int, input().split())
numbers = list(map(int, input().split()))
numbers.sort()

perm(numbers, [0] * m, 0, n, m)
