"""
Valid Palindrome
author: davin111
"""


class Solution:
    def isPalindrome(self, s: str) -> bool:
        """
        avg runtime (5 attempts): 69.6ms
        runtime beats: about 18%
        memory usage beats: 65%
        '풀이 4 - C 구현'과 유사한 부분 가짐
        """
        length = len(s)
        marker = 0
        for former in s:
            if not former.isalnum():
                continue
            for j in range(marker, length):
                latter = s[-1 - j]
                if latter.isalnum():
                    if former.lower() == latter.lower():
                        marker = j + 1
                        break
                    else:
                        return False
                marker = j + 1
        return True

    def is_palindrome_deque(self, s: str) -> bool:
        """
        풀이 2 - 데크 자료형을 이용한 최적화
        runtime: 44ms
        """
        import collections
        from typing import Deque

        strs: Deque = collections.deque()

        for char in s:
            if char.isalnum():
                strs.append(char.lower())

        while len(strs) > 1:
            if strs.popleft() != strs.pop():
                return False

        return True

    def is_palindrome_regex(self, s: str) -> bool:
        """
        풀이 3 - 슬라이싱 사용
        runtime: 36ms
        """
        import re

        s = s.lower()
        s = re.sub('[^a-z0-9]', '', s)
        return s == s[::-1]


if __name__ == "__main__":
    solution = Solution()
    print(str(solution.isPalindrome(input())).lower())

"""
wrong test cases on first submission
",,,,,,,,,,,,acva" - alnum 조건이 있는 palindrome이므로, 단순히 중간 기준 X
"""
