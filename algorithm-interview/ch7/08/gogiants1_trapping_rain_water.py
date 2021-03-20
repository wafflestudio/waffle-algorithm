'''
# 42.
'''


class Solution:
    def trap(self, height: List[int]) -> int:
        # 문제 풀이방법: 투 포인터 이용, 왼쪽 벽, 오른쪽 벽
        if not height:
            return 0
        vol = 0
        left, right = 0, len(height) - 1
        left_max, right_max = height[left], height[right]
        while left< right:
            left_max, right_max = max(height[left], left_max), max(height[right], right_max)
            if left_max <= right_max:
                vol += left_max - height[left]
                left += 1
            else:
                vol += right_max - height[right]
                right -= 1
        return vol