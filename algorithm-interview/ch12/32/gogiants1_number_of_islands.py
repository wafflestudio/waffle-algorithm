'''
148 ms	15.3 MB	python3
'''

class Solution:
    grid: List[List[str]]
    
    def dfs(self, i:int, j: int):
        if i < 0 or i >= len(self.grid) or \
            j < 0 or j >= len(self.grid[0]) or \
            self.grid[i][j] != '1':
                return
        self.grid[i][j] = '0'
        self.dfs(i+1, j)
        self.dfs(i-1, j)
        self.dfs(i, j+1)
        self.dfs(i, j-1)
        
    def numIslands(self, grid: List[List[str]]) -> int:
        self.grid = grid
        if self.grid is None:
            return 0
        count = 0
        for i in range(len(self.grid)):
            for j in range(len(self.grid[0])):
                if self.grid[i][j] == '1':
                    self.dfs(i, j)
                    count += 1
        return count