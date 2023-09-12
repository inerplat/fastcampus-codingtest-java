import sys

class Egg:
    def __init__(self, durability, weight):
        self.durability = durability
        self.weight = weight

    def fight(self, other):
        self.durability -= other.weight
        other.durability -= self.weight

    def restore(self, other):
        self.durability += other.weight
        other.durability += self.weight

def solve(pick):
    global answer
    if pick == n:
        count = sum(1 for egg in eggs if egg.durability <= 0)
        answer = max(answer, count)
        return
    
    if eggs[pick].durability > 0:
        target_exists = False
        for target in range(n):
            if target == pick:
                continue
            if eggs[target].durability > 0:
                target_exists = True
                eggs[pick].fight(eggs[target])
                solve(pick + 1)
                eggs[pick].restore(eggs[target])
        if not target_exists:
            solve(pick + 1)
    else:
        solve(pick + 1)

n = int(sys.stdin.readline())
eggs = []
for _ in range(n):
    durability, weight = map(int, sys.stdin.readline().split())
    eggs.append(Egg(durability, weight))

answer = 0
solve(0)
print(answer)
