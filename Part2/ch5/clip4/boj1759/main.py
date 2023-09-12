import sys

def is_vowel(c):
    return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u'

def generate(length, index, vowel_cnt):
    if length == l:
        if vowel_cnt >= 1 and l - vowel_cnt >= 2:
            print(''.join(password))
        return
    if index < c:
        password[length] = input[index]
        v = 1 if is_vowel(input[index]) else 0
        generate(length + 1, index + 1, vowel_cnt + v)
        password[length] = 0
        generate(length, index + 1, vowel_cnt)

l, c = map(int, sys.stdin.readline().split())
input = sys.stdin.readline().split()
password = [0] * l
input.sort()
generate(0, 0, 0)
