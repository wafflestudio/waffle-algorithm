#
# LeetCode
# ver.Python
#
# Created by GGlifer
#
# Open Source

"""
20. Valid Parentheses
"""


class Solution:
    def isValid(self, s: str) -> bool:
        pair = dict(zip(list(')]}'), list('([{')))
        st = []
        for b in s:
            if b in '([{':
                st.append(b)
            else:
                if not st:
                    return False
                elif st[-1] != pair[b]:
                    return False
                st.pop()
        return not st


if __name__ == "__main__":
    solution = Solution()

    s = "[([]])"

    print(solution.isValid(s))

