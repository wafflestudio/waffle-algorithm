import sys
import collections

n = int(sys.stdin.readline())
nodes = list(map(int, sys.stdin.readline().split()))
rem = int(sys.stdin.readline())


def make_tree(node):
    t = []
    for _ in range(len(node) + 1):
        t.append([])
    for i, v in enumerate(node):
        t[v].append(i)  # 부모 노드에 child 설정
    # res = [sorted(a) for a in t]
    return t


def remove(tree, rem):
    if tree[-1][0] == rem:
        return None
    queue = collections.deque(tree[-1])
    while queue:
        v = queue.popleft()
        if v == rem:
            tmp_queue = collections.deque([v])
            while tmp_queue:
                vv = tmp_queue.popleft()
                if len(tree[vv]) > 0:
                    tmp_queue.extend(tree[vv])
                tree[vv].clear()
        else:
            if len(tree[v]) > 0:
                if rem in tree[v]:
                    queue.extend(tree[v])
                    tree[v].remove(rem)
                else:
                    queue.extend(tree[v])
    return tree

def bfs(tree):
    if tree is None:
        return 0
    cnt = 0
    queue = collections.deque(tree[-1])
    while queue:
        v = queue.popleft()
        if len(tree[v])>0:
            queue.extend(tree[v])
        else:
            cnt += 1
    return cnt

tree = make_tree(nodes)
removed_tree = remove(tree, rem)
print(bfs(removed_tree))