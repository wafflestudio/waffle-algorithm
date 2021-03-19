class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        max_L = [-1]
        max_R = [-1]
        
        for h in height:
            max_L.append(max(max_L[-1], h))
        max_L.pop()
        
        for h in reversed(height):
            max_R.append(max(max_R[-1], h))
        max_R.pop()
        max_R.reverse()
        
        res = 0
        for i in range(len(height)):
            if max_L[i] == -1 or max_R[i] == -1:
                continue;
            water = min(max_L[i], max_R[i]) - height[i]
            if water >=0:
                res += water
        
        return res