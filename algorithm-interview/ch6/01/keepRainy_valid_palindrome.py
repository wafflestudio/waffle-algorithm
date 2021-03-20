#
# LeetCode
# ver.Python
#
# Created by GGlifer
#
# Open Source

"""
125. Valid Palindrome
"""

import re


class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()
        s = re.sub('[^a-z0-9]', '', s)
        return s == s[::-1]


if __name__ == "__main__":
    solution = Solution()

    s = "A man, a plan, a canal: Panama"

    print(solution.isPalindrome(s))

