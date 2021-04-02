class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        res = []
        while len(s) > 0:
            c = s[0]
            if c not in res:
                while len(res) > 0 and c < res[-1] and res[-1] in s:
                    res.pop()
                res.append(c)
            s = s[1:]
        return "".join(res)