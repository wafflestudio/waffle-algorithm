'''
5. longest palindrome substring
'''


class Solution:
    def longestPalindrome(self, s: str) -> str:
        def expand(left: int, right: int) -> str:
            while left >= 0 and right <= len(s) and s[left] == s[right - 1]:
                left -= 1
                right += 1
            return s[left + 1: right - 1]
        # 빠르게 전체 팰린드롬 검사, 1개 짜리인 경우 바로 리턴, 슬라이싱 이용해서 전체가 회문인 경우를 체크.
        if len(s) < 2 or  s == s[:: -1]:
            return s
        
        result = ''
        
        for i in range(len(s) - 1):
            result = max (result, 
                          expand(i, i + 1),
                          expand(i, i + 2),
                          key= len)
        return result
        