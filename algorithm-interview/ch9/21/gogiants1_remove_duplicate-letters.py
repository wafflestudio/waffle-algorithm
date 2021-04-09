"""
316. 중복 문자 제거
"""
class Solution:
    def removeDuplicateLetters(self, s):
        # 예시 bcabc, s의 길이 n
        result = ''
        while s:
            
            # map(s.rindex, set(s)) -> set(s)의 각 원소가 마지막으로 등장하는 인덱스 찾기
            # set(s)의 원소{'a', 'b', 'c']에 대해서 rindex 함수 실행
            # 그중 제일 먼저 나오는 인덱스를 i로 저장
            i = min(map(s.rindex, set(s))) # set(s) -> O(n), s.rindex -> O(n) 따라서 O(n^2)
            c = min(s[:i+1]) 
            # 마지막으로 등장하는 문자가 아닌 것들 + 마지막으로 등장하는 하나의 문자 중 알파벳 순으로 제일 작은 것 선택 (사전순으로 결과 저장하기 위해서)
            # O(n/상수)
            result += c # 결과에 저장
            s = s[s.index(c):].replace(c, '') # 이후에 나오는 중복되는 문자 제거
        return result
        """
        최악의 경우 O(n^3)? s = 'abcdef'와 같이 이미 정렬된 상태이고, 중복 없는 경우.
        분할 상환 분석? 
        """
    
    def removeDuplicateLetters(self, s: str) -> str:
        # 집합으로 정렬
        # |s| =: n, |set(s)| =: m
        # O(nmlogm) * ?? 분석 못하곘음
        for char in sorted(set(s)): 
            suffix = s[s.index(char): ]
            #전체 집합과 접미사 집합이 일치할 때 분리 진행
            if set(s) == set(suffix):
                return char + self.removeDuplicateLetters(suffix.replace(char, ''))
        return ''


