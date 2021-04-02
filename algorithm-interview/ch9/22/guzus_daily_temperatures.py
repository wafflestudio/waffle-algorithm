class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        # (index, temp)
        n = len(T)
        res = [0] * n
        s = []
        for i in range(n):
            while len(s) > 0 and T[i] > s[-1][1]:
                res[s[-1][0]] = i - s[-1][0]
                s.pop()
            s.append((i, T[i]))
        return res