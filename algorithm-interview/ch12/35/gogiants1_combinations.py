class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        res = []        
        def dfs(nodes, start: int, k: int):
            # start는 숫자의 순서를  정함.
            # k는 남은 dfs 수행 횟수
            if k == 0 :
                res.append(nodes[:])
                
            for i in range(start, n + 1):
                nodes.append(i)
                dfs(nodes, i + 1, k -1)
                nodes.pop()

        dfs([], 1, k)
        return res
'''
                   1
                / / \ \
               2  3  4  5                    NC1 * N-1C1 * N-2C1 = N * N-1 * N-2 
        [3 4 5]  [4 5] [4] [x]

        nCk = n!/((n-k)! * k!)
        시간 복잡도 : O(n^k) ??     N * N-1 * N-2 + ... + N-1 * 

        https://stackoverflow.com/questions/53419536/what-is-the-computational-complexity-of-itertools-combinations-in-python
'''
