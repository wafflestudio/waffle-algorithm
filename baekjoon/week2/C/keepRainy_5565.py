#
# BOJ
# ver.Python
#
# Created by GGlifer
#
# Open Source

"""
5565 / 영수증
"""

import sys


lst = []
for _ in range(10):
    lst.append(int(sys.stdin.readline()))

print(lst[0] - sum(lst[1:]))

