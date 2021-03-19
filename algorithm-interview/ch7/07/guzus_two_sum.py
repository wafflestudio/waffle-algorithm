class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        new_nums = []
        for i in range(len(nums)):
            new_nums.append((nums[i], i))
        new_nums.sort()
        s = 0
        e = len(new_nums)-1
        while new_nums[s][0]+new_nums[e][0] != target:
            if new_nums[s][0]+new_nums[e][0] < target:
                s+=1
            else :
                e-=1
        return [new_nums[s][1], new_nums[e][1]]