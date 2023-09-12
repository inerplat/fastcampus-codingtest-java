import sys

n = int(sys.stdin.readline().rstrip())
cnt = 0

for _ in range(n):
    check = [False] * 26
    is_group_word = True
    word = sys.stdin.readline().rstrip()
    
    for j in range(len(word) - 1):
        now = word[j]
        next_ = word[j + 1]
        if now == next_:
            continue
        if check[ord(now) - ord('a')]:
            is_group_word = False
            break
        check[ord(now) - ord('a')] = True
        
    if check[ord(word[-1]) - ord('a')]:
        is_group_word = False
    if is_group_word:
        cnt += 1

sys.stdout.write(str(cnt) + '\n')
