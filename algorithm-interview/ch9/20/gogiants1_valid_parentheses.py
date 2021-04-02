'''
20.
길이가 홀수인 경우 
'''

class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        left = ['(', '{', '[']
        if len(s) % 2 == 1:
            return False

        for p in s:
            if p in left:
                stack.append(p)
            else:
                if not stack:
                    stack.append(p)
                elif p == ')' and stack[-1] == '(':
                    stack.pop()
                elif p == '}' and stack[-1] =='{':
                    stack.pop()
                elif p == ']' and stack[-1] == '[':
                    stack.pop()
                else:
                    return False
        return len(stack) == 0
