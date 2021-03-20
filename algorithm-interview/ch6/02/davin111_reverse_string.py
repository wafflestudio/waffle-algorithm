"""
Reverse String
author: davin111
"""
from typing import List


class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        avg runtime (5 attempts): 188.8ms
        runtime beats: about 91%
        memory usage beats: 81%
        '풀이 2 - 파이썬다운 방식'과 동일
        """
        s.reverse()

    def reverse_string_bubble(self, s: List[str]) -> None:
        """
        avg runtime: Time Limit Exceeded
        bubble sort와 유사
        """
        list_len = len(s)
        for i in range(list_len - 1):
            for j in range(list_len - 1 - i):
                tmp = s[j + 1]
                s[j + 1] = s[j]
                s[j] = tmp
                # s[j], s[j + 1] = s[j + 1], s[j] 도 가능

    def reverse_string_two_pointers(self, s: List[str]) -> None:
        """
        풀이 1 - 투 포인터를 이용한 스왑
        runtime: 196ms
        """
        left, right = 0, len(s) - 1
        while left < right:
            s[left], s[right] = s[right], s[left]
            left += 1
            right -= 1


if __name__ == "__main__":
    import json

    try:
        s = json.loads(input())
    except json.JSONDecodeError:
        exit(1)

    if not isinstance(s, list):
        exit(1)

    solution = Solution()
    solution.reverseString(s)
    print(s)
