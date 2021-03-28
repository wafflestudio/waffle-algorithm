'''
교재 5번, 릿코드 49번

''.join()
defaultdict(list)
딕셔너리 값의 리스트를 얻고 싶을 때, values() 사용하기 
'''

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        
        anagrams = collections.defaultdict(list) # 리스트를 값으로 가지는 딕셔너리
        
        
        for w in strs:
            anagrams[''.join(sorted(w))].append(w)
        
        return anagrams.values() # 딕셔너리의 value list 리턴할때 .values()