#
# LeetCode
# ver.Python
#
# Created by GGlifer
#
# Open Source

"""
316. Remove Duplicate Letters
"""

from collections import Counter


class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        counter = Counter(s)
        seen = set()
        st = []

        for c in s:
            counter[c] -= 1
            if c in seen:
                continue

            while st and st[-1] > c and counter[st[-1]] > 0:
                seen.remove(st.pop())
            st.append(c)
            seen.add(c)
        return ''.join(st)


if __name__ == "__main__":
    solution = Solution()

    s = "zbcdacdz"

    print(solution.removeDuplicateLetters(s))

