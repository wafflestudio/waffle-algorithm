"""
325. reverse string
"""

class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        투 포인터 풀이.
        13번째 라인의 다중할당을 활용하는 점을 기억하기.
        """
        left , right = 0, len(s) -1
        while left < right:
            s[left] , s[right] =  s[right] ,s[left] 
            left+=1
            right-=1

    def reverse_py(self, s: List[str]) -> None:
        """
        파이썬 다운 코드.
        """
        s.reverse()