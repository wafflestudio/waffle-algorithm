class Solution:
    '''
    첫 풀이는 time
    '''
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        result = []
        for i, v in enumerate(T):
            today = T[i]
            out = 0
            for k in range(i,len(T)):
                if today < T[k] and out == 0:
                    out = k - i
            result.append(out)
        return result
    

    '''
    책 풀이 참고
    '''
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        answer = [0] * len(T)
        stack = []
        for i, cur in enumerate(T):
            while stack and cur > T[stack[-1]]:
                last = stack.pop()
                answer[last] = i - last
            stack.append(i)
        return answer     