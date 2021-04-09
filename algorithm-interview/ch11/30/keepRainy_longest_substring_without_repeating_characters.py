#
# LeetCode
# ver.Python
#
# Created by GGlifer
#
# Open Source

"""
3. Longest Substring Without Repeating Characters
"""


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        l, r = 0, 0
        cs = set()

        ret = 0
        while r < len(s):
            while s[r] in cs:
                cs.remove(s[l])
                l += 1
            cs.add(s[r])
            r += 1
            ret = max(ret, len(cs))

        return ret


if __name__ == "__main__":
    solution = Solution()

    s = "pwwkew"

    print(solution.lengthOfLongestSubstring(s))

