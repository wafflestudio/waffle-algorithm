#
# LeetCode
# ver.Python
#
# Created by GGlifer
#
# Open Source

"""
739. Daily Temperatures
"""

from typing import List


class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        A = [0] * len(T)
        st = []
        for i, t in enumerate(T):
            while st and T[st[-1]] < t:
                A[st[-1]] = i - st[-1]
                st.pop()
            st.append(i)
        return A


if __name__ == "__main__":
    solution = Solution()

    T = [73, 74, 75, 71, 69, 72, 76, 73]

    print(solution.dailyTemperatures(T))

