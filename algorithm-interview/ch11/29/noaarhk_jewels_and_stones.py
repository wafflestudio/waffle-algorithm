import collections


class Solution:
    def cntJewels(self, J: str, S: str):
        freqs = collections.defaultdict(int)
        cnt = 0
        for char in J:
            cnt += freqs[char]
        return cnt
