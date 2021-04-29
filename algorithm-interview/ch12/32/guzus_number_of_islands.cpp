class Solution
{
public:
    bool visited[305][305] = {{false}};
    int xx[4] = {1, 0, -1, 0}, yy[4] = {0, 1, 0, -1};

    void dfs(int x, int y, int m, int n, vector<vector<char>> &grid)
    {
        visited[x][y] = true;
        for (int i = 0; i < 4; i++)
        {
            int next_x = x + xx[i], next_y = y + yy[i];
            if (next_x >= 0 && next_y >= 0 && next_x < m && next_y < n &&
                grid[next_x][next_y] == '1' && visited[next_x][next_y] == false)
            {
                dfs(next_x, next_y, m, n, grid);
            }
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1' && visited[i][j] == false)
                {
                    dfs(i, j, m, n, grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};