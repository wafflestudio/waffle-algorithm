'''
#1 Two Sum

'''


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        nums_map = {} # 딕셔너리 선언
        #only one for loop
        for i, num in enumerate(nums):
            if target - num in nums_map:
                return [nums_map[target - num], i]
            nums_map[num] = i


    def two_sum(self, nums: List[int], target: int) -> List[int]:
        nums_map = {} # 딕셔너리

        # i is index, num is value
        # make dictionary to swap key, value
        for i, num in enumerate(nums):
            nums_map[num] = i

        # traget - first num
        # find value using key
        # list.index()
        # 실행시간이 빨랐는데, 그 이유는 딕셔너리는 내부 구현이 해시 테이블이기 때문이다.
        for i, num in enumerate(nums):
            if target - num in nums_map and i != nums_map[target - num]:
                return nums.index(num), nums_map[target - num]
