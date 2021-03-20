#
# LeetCode
# ver.Python
#
# Created by GGlifer
#
# Open Source

"""
49. Group Anagrams
"""

from typing import List
from collections import defaultdict


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        dic = defaultdict(list)
        for s in strs:
            key = str(sorted(s))
            dic[key].append(s)
        return list(dic.values())


if __name__ == "__main__":
    solution = Solution()

    strs = ["eat","tea","tan","ate","nat","bat"]

    print(solution.groupAnagrams(strs))

