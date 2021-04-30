'''
itertools라는 라이브러리 있음
'''


class Solution:
    
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
        prev = []
        
        def dfs(nodes):
            if len(nodes) == 0 :
                res.append(prev[:])
                
            for e in nodes:
                next = nodes[:]
                next.remove(e)
                
                prev.append(e)
                dfs(next)
                prev.pop()
                
        dfs(nums)
        return res