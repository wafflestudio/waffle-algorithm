#
# BOJ
# ver.Python
#
# Created by GGlifer
#
# Open Source

"""
1138 / 한 줄로 서기
"""

import sys


N = int(sys.stdin.readline())
A = [-1] + list(map(int, sys.stdin.readline().split()))

H = []
for i in range(N, 1-1, -1):
    H.insert(A[i], i)

print(' '.join(map(str, H)))

