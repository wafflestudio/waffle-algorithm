class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        # table = {}
        # for i in range(0, len(list(s)) - 1, 2):
        #     table[s[i + 1]] = s[i]
        table = {')': '(', '}': '{', ']': '['}

        for char in s:
            if char not in table.keys():
                stack.append(char)
            elif not stack or table[char] != stack.pop():
                return False
        return len(stack) == 0


if __name__ == '__main__':
    s = '(]{}'
    solution = Solution()
    print(solution.isValid(s))
