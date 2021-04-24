#	29284KB, 72ms

def sol(n: int, k: int):
    list = [ i  for i in range(1, n + 1)]
    res = []
    index = k - 1
    while list:
        res.append(str(list.pop(index)))
        if len(list) == 0:
            break
        index = index + k - 1 if index + k - 1 <= len(list) - 1 else (index + k - 1) % len(list)

    return ', '.join(res)




N, K = map(int, input().split())

print('<'+sol(N,K)+'>')
