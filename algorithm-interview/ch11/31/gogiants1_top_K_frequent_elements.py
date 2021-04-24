'''
347.
Runtime: 84 ms, faster than 99.74% of Python3 online submissions for Top K Frequent Elements.
Memory Usage: 18.8 MB, less than 28.81% of Python3 online submissions for Top K Frequent Elements.
'''


class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        
        result =[]
        cnt = collections.Counter(nums) # |nums| =: n 일떄,  O(n)
        sorted_count = sorted(cnt.items(), key=lambda x: (-x[1], x[0])) # 정렬(팀 소트) -> O( (n/c)log(n/c)). 단, c는 상수.
        
        # O(k)
        for i, v in enumerate(sorted_count): 
            if i <= k - 1:
                result.append(v[0])
        
        return result

        # 따라서 전체 시간 복잡도 : O(nlogn) 예상.