"""
Group Anagrams
author: davin111
"""
from typing import List


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        """
        avg runtime (5 attempts): 135.2ms
        runtime beats: about 20%
        memory usage beats: 6%
        """
        from collections import Counter, defaultdict

        anagrams = defaultdict(list)
        # O(nmlogm)
        for string in strs:  # O(n)
            count_list = list(Counter(string).items())  # O(m)
            count_list.sort()   # O(mlogm)
            count_tuple = tuple(count_list)
            anagrams[count_tuple].append(string)  # dict insert: O(1) * list append: O(1)
        return [val for key, val in anagrams.items()]  # anagrams.values() 로 가능 - O(n)

    def group_anagrams_sort(self, strs: List[str]) -> List[List[str]]:
        """
        avg runtime: 88ms
        """
        from collections import defaultdict

        anagrams = defaultdict(list)
        # O(nmlogm)
        for word in strs:  # O(n)
            anagrams[''.join(sorted(word))].append(word)  # sorted: O(mlogm) + (dict insert: O(1) * list append: O(1))
        return list(anagrams.values())  # O(n)


if __name__ == "__main__":
    import json

    try:
        strs = json.loads(input())
    except json.JSONDecodeError:
        exit(1)

    if not isinstance(strs, list):
        exit(1)

    solution = Solution()
    print(solution.groupAnagrams(strs))
