#
# LeetCode
# ver.Python
#
# Created by GGlifer
#
# Open Source

"""
819. Most Common Word
"""

from typing import List
from collections import Counter
import re


class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        paragraph = re.sub(r'[\W]', ' ', paragraph).lower()
        words = [word for word in paragraph.split() if word not in banned]
        counter = Counter(words)
        return counter.most_common(1)[0][0]


if __name__ == "__main__":
    solution = Solution()

    paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
    banned = ["hit"]

    print(solution.mostCommonWord(paragraph, banned))

