def is_same(r, c, length):
    for i in range(length):
        for j in range(length):
            if board[r][c] != board[r + i][c + j]:
                return False
    return True

def cut(r, c, length):
    if is_same(r, c, length):
        color = board[r][c] + 1
        paper[color] += 1
        return

    next_size = length // 3
    for i in range(3):
        for j in range(3):
            cut(r + next_size * i, c + next_size * j, next_size)

n = int(input())
board = []
paper = [0, 0, 0]

for _ in range(n):
    row = list(map(int, input().split()))
    board.append(row)

cut(0, 0, n)

for i in range(3):
    print(paper[i])
