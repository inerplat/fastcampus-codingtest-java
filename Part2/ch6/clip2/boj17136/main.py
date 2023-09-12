paper = [0, 5, 5, 5, 5, 5]
board = [[0] * 11 for _ in range(11)]
result = 26

def find_next(row, col):
    for r in range(row, 10):
        for c in range(10):
            if board[r][c] == 1:
                return r, c
    return -1, -1

def is_valid(row, col, size):
    if row + size > 10 or col + size > 10:
        return False
    for r in range(size):
        for c in range(size):
            if board[row + r][col + c] == 0:
                return False
    return True

def fill(row, col, size, color):
    for r in range(size):
        for c in range(size):
            board[row + r][col + c] = color

def solve(row, col, cnt):
    global result
    if result <= cnt:
        return
    r, c = find_next(row, col)
    if r == -1 and c == -1:
        result = cnt
        return

    for size in range(1, 6):
        if paper[size] == 0:
            continue
        if not is_valid(r, c, size):
            continue
        paper[size] -= 1
        fill(r, c, size, 0)
        solve(r, c, cnt + 1)
        fill(r, c, size, 1)
        paper[size] += 1

for i in range(10):
    row = list(map(int, input().split()))
    for j in range(10):
        board[i][j] = row[j]

solve(0, 0, 0)

if result == 26:
    print(-1)
else:
    print(result)
