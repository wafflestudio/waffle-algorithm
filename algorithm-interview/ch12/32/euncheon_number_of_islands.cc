#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int m = 0, n = 0;
    int count = 0;
    
    bool isInRange(int x, int y) {
        return (0 <= x && x < m && 0 <= y && y < n);
    }
    
    void dfs(int x, int y, vector<vector<char>>& grid) {
        if (not isInRange(x, y) || grid[x][y] != '1') {
            return;
        }
        grid[x][y] = '0';
        
        dfs(x+1, y, grid);
        dfs(x-1, y, grid);
        dfs(x, y+1, grid);
        dfs(x, y-1, grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if (grid[i][j] == '1') {
                    dfs(i, j, grid);
                    count++;
                }
            }
        }
        
        return count;
    }
};