"""
819. Most Common Word
정규식에서 \w는 단어 문자를 뜻함. ^는 not의 의미

most_common([n])
Return a list of the n most common elements and their counts from the most common to the least. If n is omitted or None, most_common() returns all elements in the counter. Elements with equal counts are ordered in the order first encountered:

>>>
Counter('abracadabra').most_common(3)
[('a', 5), ('b', 2), ('r', 2)]



Short answer: you should keep the r together with the string.

The r prefix is part of the string syntax. With r, Python doesn't interpret backslash sequences such as \n, \t etc inside the quotes. Without r, you'd have to type each backslash twice in order to pass it to re.sub.

r'\]\n'

and

'\\]\\n'
are two ways to write same string.


"""

class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        words = [word for word in re.sub(r'[^\w]', ' ', paragraph)
                .lower().split()
                if word not in banned]
        counts = collections.Counter(words)
        return counts.most_common(1)[0][0]
        