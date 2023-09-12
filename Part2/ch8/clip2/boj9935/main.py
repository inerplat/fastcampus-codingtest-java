import sys

def main():
    str_ = sys.stdin.readline().rstrip()
    bomb = sys.stdin.readline().rstrip()

    stack = []
    for ch in str_:
        stack.append(ch)
        if len(stack) < len(bomb):
            continue

        is_same = True
        for i in range(len(bomb)):
            if stack[-len(bomb) + i] != bomb[i]:
                is_same = False
                break
        if is_same:
            for _ in range(len(bomb)):
                stack.pop()

    result = ''.join(stack)
    if not result:
        sys.stdout.write("FRULA\n")
    else:
        sys.stdout.write(result + '\n')

if __name__ == "__main__":
    main()
