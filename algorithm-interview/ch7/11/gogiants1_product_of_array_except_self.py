'''
#238
The unary ~ (invert) operator yields the bitwise inversion of its integer argument. 
The bitwise inversion of x is defined as -(x+1). It only applies to integral numbers.

'''


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        '''
        Runtime: 336 ms
        Memory Usage: 21 MB
        '''
        out= []
        p = 1
        # 왼 곱
        for i in range(0, len(nums)): # O(n)
            out.append(p)
            p *= nums[i]
        p = 1
        for i in range(len(nums) -1, -1, - 1): # O(n)
            out[i] = out[i] * p
            p *= nums[i]
            
        return out

    def productExceptSelf(self, nums: List[int]) -> List[int]:
        '''
        Runtime: 244 ms
        Memory Usage: 21.2 MB
        '''


        res = [1]*len(nums) # space complexity: O(n)
        lprod = 1
        rprod = 1
        for i in range(len(nums)): # time complexity: O(n)
            res[i] *= lprod # 현재 인덱스 이전의 곱을 res[i]에 곱함 (자신의 곱은 제외됨)
            lprod *= nums[i] # res[i] 저장 후 다음 계산을 위해 lprod에 해당 인덱스를 곱함
            res[~i] *= rprod # ~ 연산자 사용을 통해서 현재 인덱스의 반대편 인덱스를 얻어냄. (~ 0 => -1, ~ 1 => -2), 오른쪽부터 시작한 곱셈
            rprod *= nums[~i] 
        return res
    