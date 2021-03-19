class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        mul = 1
        for num in nums:
            mul *= num
                
        if mul == 0:
            mul2 = 1
            for i in range(len(nums)):
                if i != nums.index(0):
                    mul2 *= nums[i]
            res = [0] * len(nums)
            res[nums.index(0)] = mul2
            return res
        
        res = [mul // x for x in nums]
        return res