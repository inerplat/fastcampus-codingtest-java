import sys

def divide(start, end):
    if start == end:
        return
    mid = (start + end) // 2
    divide(start, mid)
    divide(mid + 1, end)
    combine(start, end)

def combine(start, end):
    mid = (start + end) // 2
    left = start
    right = mid + 1
    new_idx = start

    while left <= mid and right <= end:
        if numbers[left] < numbers[right]:
            temp[new_idx] = numbers[left]
            left += 1
        else:
            temp[new_idx] = numbers[right]
            right += 1
        new_idx += 1

    while left <= mid:
        temp[new_idx] = numbers[left]
        left += 1
        new_idx += 1

    while right <= end:
        temp[new_idx] = numbers[right]
        right += 1
        new_idx += 1

    numbers[start:end + 1] = temp[start:end + 1]

n = int(sys.stdin.readline())
numbers = []
temp = [0] * n

for _ in range(n):
    numbers.append(int(sys.stdin.readline()))

divide(0, n - 1)

for num in numbers:
    sys.stdout.write(str(num) + '\n')
