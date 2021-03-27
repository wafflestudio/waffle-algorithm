from typing import List


# brute force
class Solution_0:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            for j in range(len(nums)):
                if nums[i] + nums[j] == target and i != j:
                    return [i, j]


class Solution_1:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i, n in enumerate(nums):
            complement = target - n

            if complement in nums[i + 1:]:
                return [nums.index(n), nums[i + 1:].index(complement) + (i + 1)]


class Solution_2:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        nums_d = {}
        for i, num in enumerate(nums):
            nums_d[num] = i
        for i, num in enumerate(nums):
            if target - num in nums_d and i != nums_d[target - num]:
                return [nums.index(num), nums_d[target - num]]


class Solution_3:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        nums_d = {}
        for i, num in enumerate(nums):
            nums_d[num] = i
            if target - num in nums_d and i != nums_d[target - num]:
                return [nums_d[target - num], i]


class Solution_4:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        left, right = 0, len(nums) - 1
        # nums 가 정렬되어있지 않은 상태에서는 불가능 ; nums.sort() 하더라도 기존의 인덱스를 찾을 수 없다.
        while left != right:
            if nums[left] + nums[right] < target:
                left += 1
            elif nums[left] + nums[right] > target:
                right -= 1
            else:
                return [left, right]


if __name__ == "__main__":
    solution = Solution_4()

    nums = [2, 7, 11, 15]
    target = 9

    print(solution.twoSum(nums, target))
