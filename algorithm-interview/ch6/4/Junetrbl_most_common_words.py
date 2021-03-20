import collections
from typing import List, re


class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        """
        Runtime: 28 ms
        Memory Usage: 14.3 MB
        """
        paragraph = re.sub(r'[^\w]', ' ', paragraph).lower().split()

        words = [word for word in paragraph if word not in banned]

        count = {}
        for word in words:
            if word in count.keys():
                count[word] += 1
            else:
                count[word] = 1

        count = sorted(count.items(), key=lambda x: x[1])

        return count[-1][0]

    def mostCommonWordCounter(self, paragraph: str, banned: List[str]) -> str:
        """
        Runtime: 36 ms
        Memory Usage: 14.2 MB
        """
        paragraph = re.sub(r'[^\w]', ' ', paragraph).lower().split()

        words = [word for word in paragraph if word not in banned]

        count = collections.Counter(words)

        return count.most_common(1)[0][0]