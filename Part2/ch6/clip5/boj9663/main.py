import sys

def solve(n, row, col_used, diag1_used, diag2_used):
    if row == n:
        return 1
    
    count = 0
    for col in range(n):
        if not col_used[col] and not diag1_used[row + col] and not diag2_used[row - col + n - 1]:
            col_used[col] = True
            diag1_used[row + col] = True
            diag2_used[row - col + n - 1] = True
            
            count += solve(n, row + 1, col_used, diag1_used, diag2_used)
            
            col_used[col] = False
            diag1_used[row + col] = False
            diag2_used[row - col + n - 1] = False
            
    return count

n = int(sys.stdin.readline())
col_used = [False] * n
diag1_used = [False] * (2 * n - 1)
diag2_used = [False] * (2 * n - 1)
print(solve(n, 0, col_used, diag1_used, diag2_used))
