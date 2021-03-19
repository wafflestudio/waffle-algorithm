#
# BOJ
# ver.Python
#
# Created by GGlifer
#
# Open Source

"""
2902 / KMP는 왜 KMP일까?
"""

from functools import reduce


print(reduce(lambda ans, x: ans+x[0], input().split('-'), ''))

