#
# BOJ
# ver.Python
#
# Created by GGlifer
#
# Open Source

"""
9012 / 괄호
"""

import sys


T = int(sys.stdin.readline().strip())
for _ in range(T):
    PS = sys.stdin.readline().strip()

    stack = []
    isVPS = True
    for p in PS:
        if p == '(':
            stack.append(p)
        else:
            if not stack:
                isVPS = False
                break
            stack.pop()
    if stack:
        isVPS = False

    print("YES" if isVPS else "NO")

