class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = {}
        for num in nums:
            if num in freq:
                freq[num] += 1
            else:
                freq[num] = 1

        elems = []
        for key in freq.keys():
            elems.append((key, freq[key]))
        elems = sorted(elems, key=lambda x: -x[1])

        res = []
        for i in range(k):
            res.append(elems[i][0])
        return res
