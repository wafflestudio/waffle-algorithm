'''
람다 함수를 사용했다는 점 기억하기. 
다만 람다 함수는 특정 경우에서만 간편하며, map이나 다른 복잡한 로직과 섞이면 더 어려워진다.
대부분은 가독성이 더 좋은 리스트 컴프리핸션 사용
sort(*, key=None, reverse=False)
sorted(key = lambda x: ( 첫번째 키 , 두번째 키 (후순위) )
'''

class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        digits ,letters = [], []
        for  log in logs:
            if log.split()[1].isdigit():
                digits.append(log)
            else:
                letters.append(log)
                
        letters.sort(key=lambda x: (x.split()[1:], x.split()[0]))
        
        return letters + digits