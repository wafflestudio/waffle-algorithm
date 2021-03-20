

class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        #pythonic way
        return sum(sorted(nums)[::2])


    def arrayPairSum2(self, nums: List[int]) -> int:
        # sorting
        nums.sort()
        sum = 0
        
        for i in range(0, len(nums) , 2):
            sum += nums[i]
        return sum