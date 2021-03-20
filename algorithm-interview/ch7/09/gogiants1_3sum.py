'''
# 15

'''


class Solution:
    def threeSum(self, nums): 
        nums, res, n =sorted(nums), [], len(nums)
        for i in range(n-2):
            if nums[i] > 0: #pruning
                break
            if i and nums[i] == nums[i-1]: #remove duplicate
                continue
            hi = n - 1
            lo = bisect.bisect_left(nums, - nums[i] - nums[hi], i + 1, hi) - 1 #binary search
            lo += (lo == i)
            while lo < hi:
                sum = nums[i] + nums[lo] + nums[hi]
                if sum == 0:
                    res += (nums[i], nums[lo], nums[hi]),
                    while lo < hi and nums[lo] == nums[lo+1]: #remove duplicate
                        lo += 1 
                    while lo < hi and nums[hi] == nums[hi-1]: #remove duplicate
                        hi -= 1
                lo += sum <= 0 
                hi -= sum >= 0
        return res

    def three_sum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if len(nums) < 3:
            return []
        nums.sort()
        res = set()
        for i, v in enumerate(nums[:-2]):
            if i >= 1 and v == nums[i-1]:
                continue
            d = {}
            for x in nums[i+1:]:
                if x not in d:
                    d[-v-x] = 1
                else:
                    res.add((v, -v-x, x))
        return [*map(list, res)]
