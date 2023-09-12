def power(a, b):
    if b == 1:
        return a % c
    half = power(a, b // 2)
    if b % 2 == 0:
        return (half * half) % c
    else:
        return (((half * half) % c) * a) % c

a, b, c = map(int, input().split())
print(power(a, b))
