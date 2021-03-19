#
# BOJ
# ver.Python
#
# Created by GGlifer
#
# Open Source

"""
1027 / 고층 건물
"""

import sys


N = int(sys.stdin.readline())
H = [int(e) for e in sys.stdin.readline().split()]

INC = [[-1.0 for _ in range(N)] for _ in range(N)]
for i in range(N):
    for j in range(i+1, N):
        INC[i][j] = INC[j][i] = (H[j]-H[i]) / (j-i)

ans = -1
for i in range(N):
    cnt = 0

    std = sys.maxsize
    for j in range(i-1, 0-1, -1):
        if INC[i][j] < std:
            cnt += 1
            std = INC[i][j]

    std = -sys.maxsize
    for j in range(i+1, N):
        if INC[i][j] > std:
            cnt += 1
            std = INC[i][j]

    ans = max(ans, cnt)

print(ans)

