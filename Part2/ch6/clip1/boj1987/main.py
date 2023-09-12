import sys

def solve(row, col):
    result = 0
    for i in range(4):
        nr, nc = row + dr[i], col + dc[i]
        if is_out_of_bound(nr, nc, r, c):
            continue
        
        next_char = board[nr][nc]
        route = 1 << next_char
        if visited[nr][nc] == (visited[row][col] | route):
            continue
        if check[next_char]:
            continue
        
        visited[nr][nc] = visited[row][col] | route
        check[next_char] = True
        result = max(result, solve(nr, nc))
        check[next_char] = False
    return result + 1

def is_out_of_bound(row, col, bound_r, bound_c):
    return row < 0 or row >= bound_r or col < 0 or col >= bound_c

r, c = map(int, sys.stdin.readline().split())
board = []
for _ in range(r):
    line = sys.stdin.readline().strip()
    board.append([ord(ch) - ord('A') for ch in line])

dr = [-1, 0, 1, 0]
dc = [0, 1, 0, -1]

visited = [[0] * c for _ in range(r)]
check = [False] * 26
check[board[0][0]] = True
visited[0][0] = 1 << (board[0][0])
print(solve(0, 0))
