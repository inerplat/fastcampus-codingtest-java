import sys

class Node:
    def __init__(self, node, dist):
        self.node = node
        self.dist = dist

def find_max_depth_leaf(node, depth):
    global max_depth, max_depth_leaf
    if depth > max_depth:
        max_depth = depth
        max_depth_leaf = node
    for next_node in tree[node]:
        if visited[next_node.node] == 1:
            continue
        visited[next_node.node] = 1
        find_max_depth_leaf(next_node.node, depth + next_node.dist)

v = int(sys.stdin.readline().rstrip())
tree = [[] for _ in range(v + 1)]
visited = [0] * (v + 1)

for _ in range(v):
    inputs = list(map(int, sys.stdin.readline().split()))
    node = inputs[0]
    for i in range(1, len(inputs) - 1, 2):
        next_node = inputs[i]
        dist = inputs[i + 1]
        tree[node].append(Node(next_node, dist))
        tree[next_node].append(Node(node, dist))

# 1차 탐색: 임의의 노드에서 가장 먼 노드를 찾는다.
max_depth = 0
visited[1] = 1
find_max_depth_leaf(1, 0)

# 2차 탐색: 가장 먼 노드에서 다시 가장 먼 노드를 찾는다.
visited = [0] * (v + 1)
max_depth = 0
visited[max_depth_leaf] = 1
find_max_depth_leaf(max_depth_leaf, 0)

sys.stdout.write(str(max_depth) + '\n')
