#
# BOJ
# ver.Python
#
# Created by GGlifer
#
# Open Source

"""
2167 / 2차원 배열의 합
"""

import sys
from copy import deepcopy


N, M = map(int, sys.stdin.readline().split())
A = [[0 for _ in range(M+1)] for _ in range(N+1)]
for i in range(1, N+1):
    A[i][1:] = list(map(int, sys.stdin.readline().split()))

dp = deepcopy(A)
for i in range(1, N+1):
    for j in range(1, M+1):
        dp[i][j] = A[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1]

T = int(sys.stdin.readline())
for _ in range(T):
    i, j, x, y = map(int, sys.stdin.readline().split())
    print(dp[x][y] - dp[x][j-1] - dp[i-1][y] + dp[i-1][j-1])

