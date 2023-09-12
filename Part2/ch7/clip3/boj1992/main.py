def compress(r, c, length):
    if is_same(r, c, length):
        print(board[r][c], end="")
        return
    mid = length // 2
    print("(", end="")
    compress(r, c, mid)
    compress(r, c + mid, mid)
    compress(r + mid, c, mid)
    compress(r + mid, c + mid, mid)
    print(")", end="")

def is_same(r, c, length):
    for i in range(length):
        for j in range(length):
            if board[r][c] != board[r + i][c + j]:
                return False
    return True

n = int(input())
board = []
for _ in range(n):
    row = list(map(int, input()))
    board.append(row)

compress(0, 0, n)
