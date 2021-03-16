"""
1. Two Sum
"""

class Solution:
	# 44, 14.6MB
	def twoSum(self, nums: List[int], target: int) -> List[int]:
		N = len(nums)
		l = list(zip(nums, range(N)))
		l.sort()
		i = 0
		j = N - 1
		while i < j:
			x = l[i][0] + l[j][0]
			if x == target:
				return [l[i][1], l[j][1]]
			elif x < target:
				i += 1
			else:
				j -= 1

	# 52ms, 14.3MB
	def twoSum2(self, nums: List[int], target: int) -> List[int]:
		N = len(nums)
		idx = list(range(N))
		idx.sort(key=lambda x: nums[x])
		i = 0
		j = N - 1
		while i < j:
			x = nums[idx[i]] + nums[idx[j]]
			if x == target:
				return [idx[i], idx[j]]
			elif x < target:
				i += 1
			else:
				j -= 1

	# 44ms, 14.4MB
	def twoSum_square(self, nums: List[int], target: int) -> List[int]:
		for i in range(len(nums)):
			for j in range(i):
				if nums[i] + nums[j] == target:
					return [i, j]
