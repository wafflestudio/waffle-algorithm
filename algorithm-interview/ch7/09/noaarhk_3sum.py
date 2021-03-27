from typing import List


# 합으로 0을 만들 수 있는 세개의 엘리먼트 출력
class Solution_0:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        results = []
        nums.sort()
        for i in range(len(nums) - 2):
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            for j in range(i + 1, len(nums) - 1):
                if j > i + 1 and nums[j] == nums[j - 1]:
                    continue

                for k in range(j + 1, len(nums)):
                    if k > j + 1 and nums[k] == nums[k - 1]:
                        continue

                    sum = nums[i] + nums[j] + nums[k]
                    if sum == 0:
                        results.append([nums[i], nums[j], nums[k]])
        return results


# wrong answer
class Solution_1:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        results = []
        nums.sort()
        print(nums)
        left, right = 0, len(nums) - 1
        for i in range(len(nums) - 1):
            left = i + 1
            comp = 0 - nums[i]
            if nums[left] + nums[right] < comp:
                left += 1
            elif nums[left] + nums[right] > comp:
                right -= 1
            else:
                results.append(sorted([nums[left], nums[right], nums[i]]))
        return results


class Solution_2:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        results = []
        nums.sort()
        for i in range(len(nums) - 2):

            # 중복된 계산 방지
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            left, right = i + 1, len(nums) - 1

            # 정렬된 배열 위에서 투포인터의 범위를 설정해 주어야 한다.
            while left < right:
                sum = nums[i] + nums[left] + nums[right]

                if sum < 0:
                    left += 1
                elif sum > 0:
                    right -= 1
                else:
                    results.append([nums[i], nums[left], nums[right]])

                    # 정답 및 스킵 처리? ..?..?
                    while left < right and nums[left] == nums[left + 1]:
                        left += 1
                    while left < right and nums[right] == nums[right - 1]:
                        right -= 1
                    left += 1
                    right -= 1

        return results


if __name__ == '__main__':
    nums = [-1, 0, 1, 2, -1, -4]

    # solution1 = Solution_1()
    solution2 = Solution_2()
    # print(solution1.threeSum(nums))
    print(solution2.threeSum(nums))
