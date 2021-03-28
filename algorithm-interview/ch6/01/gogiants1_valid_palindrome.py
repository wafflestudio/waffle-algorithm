"""
125. valid palindrome
처음에 palindrome이라는 단어만 보고, dp문제인 줄 착각.
"""


class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()
        s = re.sub('[^a-z0-9]', '', s)
        
        return s == s[:: -1]