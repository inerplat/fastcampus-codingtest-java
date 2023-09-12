check = [-1] * 101
input_str = input()
input_len = len(input_str)
if input_len > 9:
    n = 9 + (input_len - 9) // 2
else:
    n = input_len

for i in range(1, n + 1):
    check[i] = 0

answer = []

def solve(index):
    global answer
    if index >= input_len:
        print(" ".join(map(str, answer)))
        exit()

    target1 = int(input_str[index])
    if target1 <= n and check[target1] == 0:
        check[target1] = index + 1
        answer.append(target1)
        solve(index + 1)
        answer.pop()
        check[target1] = 0

    if index + 1 >= input_len:
        return

    target2 = int(input_str[index:index+2])
    if target2 <= n and check[target2] == 0:
        check[target2] = index + 1
        answer.append(target2)
        solve(index + 2)
        answer.pop()
        check[target2] = 0

solve(0)
