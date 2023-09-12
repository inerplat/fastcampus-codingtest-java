n, r, c = map(int, input().split())
count = 0

def solve(n, r, c):
    global count
    board_size = 1 << n
    mid = board_size // 2
    if n == 0:
        return
    if r < mid and c < mid:  # 좌상단
        solve(n - 1, r, c)
    elif r < mid and c >= mid:  # 우상단
        count += mid * mid
        solve(n - 1, r, c - mid)
    elif r >= mid and c < mid:  # 좌하단
        count += mid * mid * 2
        solve(n - 1, r - mid, c)
    else:  # 우하단
        count += mid * mid * 3
        solve(n - 1, r - mid, c - mid)

solve(n, r, c)
print(count)
