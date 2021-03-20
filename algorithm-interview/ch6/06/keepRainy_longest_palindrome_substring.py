#
# LeetCode
# ver.Python
#
# Created by GGlifer
#
# Open Source

"""
5. Longest Palindrome Substring
"""


class Solution:
    def longestPalindrome(self, s: str) -> str:
        ret = s[0]
        for i in range(1, len(s)-1):
            tmp = s[i]
            for j in range(1, min(i, len(s)-1-i)+1):
                if s[i-j] == s[i+j]:
                    tmp = s[i-j] + tmp + s[i+j]
                    if len(tmp) > len(ret):
                        ret = tmp
                else:
                    break
        for i in range(len(s)-1):
            if s[i] == s[i+1]:
                tmp = ''
                for j in range(min(i, len(s)-1-(i+1))+1):
                    if s[i-j] == s[i+1+j]:
                        tmp = s[i-j] + tmp + s[i+1+j]
                        if len(tmp) > len(ret):
                            ret = tmp
                    else:
                        break
        return ret


if __name__ == "__main__":
    solution = Solution()

    s = "babad"

    print(solution.longestPalindrome(s))

